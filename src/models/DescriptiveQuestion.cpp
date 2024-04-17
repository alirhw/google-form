
#include "descriptiveQuestion.h"

#include <fstream>
#include <iostream>
#include <utility>


DescriptiveQuestion::DescriptiveQuestion(enum type type, std::string prompt, std::string description, int time, double score,std::string answer) : Question(type, prompt, description, time, score)  {
	answer = std::move(answer);
}


void DescriptiveQuestion::saveToFile(const std::string &filename) const {
    std::ofstream outFile(filename, std::ios::app);

    // Check if file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Write DescriptiveQuestion data to csv file
    outFile << answer << "," << std::endl;

    // Close the file
    outFile.close();
}
