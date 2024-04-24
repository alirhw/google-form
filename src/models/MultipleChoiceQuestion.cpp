//
// Created by alirhw on 4/11/2024.
//

#include "MultipleChoiceQuestion.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>


MultipleChoiceQuestion::MultipleChoiceQuestion(enum type type, std::string questionID, std::string prompt, std::string description, int time, double score, std::vector<std::string> options, std::string correctAnswer) : Question(type, questionID, prompt, description, time, score) {
    this->options[0] = options[0];
    this->options[1] = options[1];
    this->options[2] = options[2];
    this->options[3] = options[3];
    this->correctAnswer = std::move(correctAnswer);
}


void MultipleChoiceQuestion::saveToFile(const std::string &filename) const {
    std::ifstream inFile(filename, std::ios::app);
    // Check if file opened successfully
    if (!inFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::vector<std::string> lines{};
    std::string line = "";
    std::vector<std::string> updatedLines{};
    std::string updatedLine = "";
    bool found = false;
    while (std::getline(inFile, line)) {
        if (line.empty()) continue;
        std::vector<std::string> fields;
        std::string token;
        std::stringstream ss(line);
        while (getline(ss, token, ',')) {
            fields.push_back(token);
        }
        if (fields.at(0) == this->questionID) {
            found = true;
            updatedLine = Question::enumToString(type) + "," + questionID + "," + prompt + "," + description + "," + std::to_string(time) + "," + std::to_string(score.first) + "," + std::to_string(score.second) + ",";
            updatedLine += "[" + options[0] + "-" + options[1] + "-" + options[2] + "-" + options[3] + "]," + correctAnswer + "\n";
        } else {
            updatedLine = line;
        }
        updatedLines.push_back(updatedLine);
    }
    inFile.close();

    std::ofstream outFile(filename, std::ios::trunc);
    // Check if file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    if (!found) {
        updatedLine = Question::enumToString(type) + "," + questionID + "," + prompt + "," + description + "," + std::to_string(time) + "," + std::to_string(score.first) + "," + std::to_string(score.second) + ",";
        updatedLine += "[" + options[0] + "-" + options[1] + "-" + options[2] + "-" + options[3] + "]," + correctAnswer + "\n";
        updatedLines.push_back(updatedLine);
    }

    for (const std::string &l: updatedLines) {
        if (!l.empty()) {
            outFile << l << std::endl;
        }
    }

    outFile.close();
}
bool MultipleChoiceQuestion::autoCorrector(std::string answer) {

    if (answer == correctAnswer) {
        return true;
    } else {
        return false;
    }
}
