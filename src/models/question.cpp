//
// Created by alirhw on 4/11/2024.
//

#include "question.h"

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <utility>
#include <vector>


Question::Question(enum type type, std::string questionID, std::string prompt,
                   int time = 0, double score = 0) {
    this->type = type;
    this->questionID = std::move(questionID);
    this->prompt = std::move(prompt);
    this->time = time;
    this->score.first = 0;
    this->score.second = score;
}

void Question::changeDescription(std::string comment) {
    this->description = std::move(comment);
}

void Question::saveToFile(const std::string &filename) const {
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
        while (getline(ss, token, ',')) { fields.push_back(token); }
        if (fields.at(1) == this->questionID) {
            found = true;
            updatedLine = Question::enumToString(type) + "," + questionID +
                          "," + prompt + "," + description + "," +
                          std::to_string(time) + "," +
                          std::to_string(score.first) + "," +
                          std::to_string(score.second) + ",";
            if (filename == "data/multipleChoiceQuestion.csv") {
                std::string options(fields.at(7));
                updatedLine += options + ",";
                std::string correctAnswer(fields.at(8));
                updatedLine += options + ',';
            }
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
        updatedLine = Question::enumToString(type) + "," + questionID + "," +
                      prompt + "," + description + "," + std::to_string(time) +
                      "," + std::to_string(score.first) + "," +
                      std::to_string(score.second) + ",";
        updatedLines.push_back(updatedLine);
    }

    for (const std::string &l: updatedLines) {
        if (!l.empty()) { outFile << l << std::endl; }
    }

    outFile.close();
}

std::string Question::enumToString(enum type value) {
    switch (value) {
        case type::Descriptive:
            return "Descriptive";
        case type::MultipleChoice:
            return "MultipleChoice";
        default:
            throw std::invalid_argument("Invalid enum value");
    }
}

type Question::stringToType(const std::string &str) {
    static const std::map<std::string, enum type> enumMap = {
            {"Descriptive", type::Descriptive},
            {"MultipleChoice", type::MultipleChoice}};

    auto it = enumMap.find(str);
    if (it != enumMap.end()) {
        return it->second;
    } else {
        // Return a default value or throw an exception for invalid input
        throw std::invalid_argument("Invalid enum string");
    }
}