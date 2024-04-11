//
// Created by alirhw on 4/11/2024.
//

#include "exam.h"

#include <fstream>
#include <iostream>
#include <utility>


Exam::Exam(int _examId, std::string _examName, std::string _examDate, std::string _examTime, double _totalScore) {
    examId = _examId;
    examName = std::move(_examName);
    examDate = std::move(_examDate);
    examTime = std::move(_examTime);
    totalScore = _totalScore;
}

void Exam::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);

    // Check if file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Write exam data to csv file
    outFile << examId << ","; // Exam ID
    outFile << examName << ","; // Exam Name
    outFile << examDate << ",";// Exam Date
    outFile << examTime << ","; // Exam Time
    outFile << totalScore << "," << std::endl; // Total Score

    // Close the file
    outFile.close();
}

