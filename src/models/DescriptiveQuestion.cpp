
#include "descriptiveQuestion.h"

#include <fstream>
#include <iostream>
#include <utility>


DescriptiveQuestion::DescriptiveQuestion(enum type type, std::string questionID, std::string prompt, std::string description, int time, double score) : Question(type, questionID, prompt, description, time, score) {
}


void DescriptiveQuestion::saveToFile(const std::string &filename) const {
    std::ofstream outFile(filename, std::ios::app);

    // Check if file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Write DescriptiveQuestion data to csv file
    outFile << type << ",";
    outFile << questionID << ",";
    outFile << prompt << ",";
    outFile << description << ",";
    outFile << time << ",";
    outFile << score.first << ",";
    outFile << score.second << ",";

    // Close the file
    outFile.close();
}
