//
// Created by alirhw on 4/11/2024.
//

#include "MultipleChoiceQuestion.h"

#include <fstream>
#include <iostream>
#include <utility>


MultipleChoiceQuestion::MultipleChoiceQuestion(std::string options[4], std::string _correctAnswer) {
    options[0] = std::move(options[0]);
    options[1] = std::move(options[1]);
    options[2] = std::move(options[2]);
    options[3] = std::move(options[3]);
    correctAnswer = std::move(_correctAnswer);
}

void MultipleChoiceQuestion::saveToFile(const std::string &filename) const {
    std::ofstream outFile(filename, std::ios::app);

    // Check if file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Write MultipleChoiceQuestion data to csv file
    outFile << options[0] << ",";
    outFile << options[1] << ",";
    outFile << options[2] << ",";
    outFile << options[3] << ",";
    outFile << correctAnswer << "," << std::endl;

    // Close the file
    outFile.close();
}