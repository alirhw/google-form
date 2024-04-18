//
// Created by alirhw on 4/11/2024.
//

#include "exam.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>


Exam::Exam(int examId, std::string examName, std::string examDate, std::string examTime, double totalScore) {
    this->examId = examId;
    examName = std::move(examName);
    examDate = std::move(examDate);
    examTime = std::move(examTime);
    this->totalScore = totalScore;
}

void Exam::saveToFile(const std::string &filename) const {
    std::ofstream outFile(filename, std::ios::app);

    // Check if file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Write exam data to csv file
    outFile << examId << ",";                 // Exam ID
    outFile << examName << ",";               // Exam Name
    outFile << examDate << ",";               // Exam Date
    outFile << examTime << ",";               // Exam Time
    outFile << totalScore << "," << std::endl;// Total Score

    // Close the file
    outFile.close();
}

std::vector<Exam> Exam::getAll(const std::string &filename) {
    std::ifstream inFile(filename, std::ios::app);
    // Check if file opened successfully
    if (!inFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
    }

    std::vector<Exam> exams;
    std::string line;
    while (std::getline(inFile, line)) {
        std::vector<std::string> fields;
        std::string token;
        std::stringstream ss(line);
        while (getline(ss, token, ',')) {
            fields.push_back(token);
        }
        for (int i = 0; i < fields.size(); ++i) {
            Exam exam(stoi(fields.at(0)), fields.at(1), fields.at(2), fields.at(3), stod(fields.at(4)));
            exams.push_back(exam);
        }
    }
    inFile.close();
    return exams;
}
