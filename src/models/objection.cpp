//
// Created by erfan on 5/31/2024.
//

#include "objection.h"
#include <fstream>
#include <iostream>
#include <vector>

std::string Objection::getFormattedTimestamp() const {
    std::time_t time = std::chrono::system_clock::to_time_t(timestamp);
    std::tm tm = *std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void Objection::saveToFile(const std::string &filename) const {
    std::ifstream inFile(filename, std::ios::app);
    // Check if file opened successfully
    if (!inFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::vector<std::string> lines{};
    std::string line;
    std::vector<std::string> updatedLines{};
    std::string updatedLine;
    bool found = false;
    while (std::getline(inFile, line)) {
        if (line.empty()) continue;
        std::vector<std::string> fields;
        std::string token;
        std::stringstream ss(line);
        while (getline(ss, token, ',')) { fields.push_back(token); }
        if (fields.at(2) == this->studentId && fields.at(3) == this->examId) {
            found = true;
            updatedLine = this->text + "," + this->answer + "," +
                          this->studentId + "," + this->examId + "," +
                          this->getFormattedTimestamp();
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
        updatedLine = this->text + "," + this->answer + "," + this->studentId +
                      "," + this->examId + "," + this->getFormattedTimestamp();
        updatedLines.push_back(updatedLine);
    }

    for (const std::string &l: updatedLines) {
        if (!l.empty()) { outFile << l << std::endl; }
    }

    outFile.close();
}

std::vector<Objection> Objection::getAll(const std::string &filename) {
    std::ifstream inFile(filename, std::ios::app);
    // Check if file opened successfully
    if (!inFile.is_open()) { std::cerr << "Error opening file!" << std::endl; }

    std::vector<Objection> objections;
    std::string line;
    while (std::getline(inFile, line)) {
        std::vector<std::string> fields;
        std::string token;
        std::stringstream ss(line);
        while (getline(ss, token, ',')) { fields.push_back(token); }
        Objection objection(fields.at(0), fields.at(2), fields.at(3));
        objection.answer = fields.at(1);
        objections.push_back(objection);
    }
    inFile.close();
    return objections;
}