//
// Created by alirhw on 4/11/2024.
//

#include "MultipleChoiceQuestion.h"

#include <fstream>
#include <iostream>
#include <utility>


MultipleChoiceQuestion::MultipleChoiceQuestion(enum type type, std::string questionID, std::string prompt, std::string description, int time, double score, std::vector<std::string> options, std::string correctAnswer) : Question(type, questionID, prompt, description, time, score) {
    this->options[0] = options[0];
    this->options[1] = options[1];
    this->options[2] = options[2];
    this->options[3] = options[3];
    this->correctAnswer = std::move(correctAnswer);
}


void MultipleChoiceQuestion::saveToFile(const std::string &filename) const {
    std::ofstream outFile(filename, std::ios::app);

    // Check if file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Write MultipleChoiceQuestion data to csv file
    outFile << type << ",";
    outFile << questionID << ",";
    outFile << prompt << ",";
    outFile << description << ",";
    outFile << time << ",";
    outFile << score.first << ",";
    outFile << score.second << ",";
    outFile << options[0] << ",";
    outFile << options[1] << ",";
    outFile << options[2] << ",";
    outFile << options[3] << ",";
    outFile << correctAnswer << "," << std::endl;

    // Close the file
    outFile.close();
}
bool MultipleChoiceQuestion::autoCorrector(std::string answer) {

    if (answer == correctAnswer) {
        return true;
    } else {
        return false;
    }
}
