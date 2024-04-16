//
// Created by alirhw on 4/11/2024.
//

#include "question.h"

#include <fstream>
#include <iostream>
#include <utility>


Question::Question(enum type type, std::string prompt, std::string description, int time, double score) {

    type = type;
    prompt = std::move(prompt);
    description = std::move(description);
    time = time;
    score = score;
}

void Question::saveToFile(const std::string &filename) const {
    std::ofstream outFile(filename);

    // Check if file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Write exam data to csv file
    outFile << type << ",";
    outFile << prompt << ",";
    outFile << description << ",";
    outFile << time << ",";
    outFile << score << "," << std::endl;

    // Close the file
    outFile.close();
}