
#include "descriptiveQuestion.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>


DescriptiveQuestion::DescriptiveQuestion(enum type type,
                                         std::string questionID,
                                         std::string prompt, int time,
                                         double score)
    : Question(type, questionID, prompt, time, score) {}


void DescriptiveQuestion::saveToFile(const std::string &filename) const {
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
            updatedLine += "[";
            for (const auto &asw: this->answer) {
                updatedLine += "(" + asw.first + ":" +
                               asw.second + ")" + "-";
            }
            updatedLine += "],";
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
        updatedLine += "[";
        for (const auto &asw: this->answer) {
            updatedLine += "(" + asw.first + ":" +
                           asw.second + ")" + "-";
        }
        updatedLine += "],";
        updatedLines.push_back(updatedLine);
    }

    for (const std::string &l: updatedLines) {
        if (!l.empty()) { outFile << l << std::endl; }
    }

    outFile.close();
}

DescriptiveQuestion
DescriptiveQuestion::findByQuestionID(const std::string &filename,
                                      std::string questionID) {
    std::ifstream inFile(filename, std::ios::app);
    // Check if file opened successfully
    if (!inFile.is_open()) { std::cerr << "Error opening file!" << std::endl; }

    std::string line;
    while (std::getline(inFile, line)) {
        std::vector<std::string> fields;
        std::string token;
        std::stringstream ss(line);
        while (getline(ss, token, ',')) { fields.push_back(token); }
        if (fields.at(1) == questionID) {
            DescriptiveQuestion found(Question::stringToType(fields.at(0)),
                                      fields.at(1), fields.at(2),
                                      stoi(fields.at(4)), stod(fields.at(6)));
            found.description = fields.at(3);
            found.score.first = stod(fields.at(5));
            return found;
        }
    }
    inFile.close();
}
