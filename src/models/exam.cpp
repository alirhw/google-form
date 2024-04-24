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
    std::ifstream inFile(filename, std::ios::app);
    // Check if file opened successfully
    if (!inFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inFile, line)) {
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] != ',' && line[i + 1] == ',') {
                if (line.substr(i + 1) == std::to_string(this->examId)) {
                    line = std::to_string(examId) + "," + examName + "," + examDate + "," + examTime + "," + std::to_string(totalScore) + "," + std::to_string(corrected) + ",";
                    line += "[";
                    for (const auto &question: questions) {
                        line += question.questionID + "-";
                    }
                    line += "],";
                    line += "[";
                    for (const auto &student: studentScores) {
                        line += "(" + student.first + "," + std::to_string(student.second) + ")" + "-";
                    }
                    line += "]\n";
                }
            }
        }
        lines.push_back(line);
    }
    inFile.close();

    std::ofstream outFile(filename, std::ios::app);
    // Check if file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    for (const std::string &l: lines) {
        if (!l.empty()) {
            outFile << line << std::endl;
        } else {
            outFile << examId << ",";
            outFile << examName << ",";
            outFile << examDate << ",";
            outFile << examTime << ",";
            outFile << totalScore << ",";
            outFile << corrected << ",";
            outFile << "[";
            for (const auto &question: questions) {
                outFile << question.questionID << "-";
            }
            outFile << "],";
            outFile << "[";
            for (const auto &student: studentScores) {
                outFile << "(" << student.first << "," << std::to_string(student.second) << ")"
                        << "-";
            }
            outFile << "]\n";
        }
    }

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

Exam Exam::findByExamId(const std::string &filename, const int &examIdToFind) {
    std::ifstream inFile(filename, std::ios::app);
    // Check if file opened successfully
    if (!inFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::vector<std::string> fields;
        std::string token;
        std::stringstream ss(line);
        while (getline(ss, token, ',')) {
            fields.push_back(token);
        }
        for (int i = 0; i < fields.size(); ++i) {
            if (fields.at(0) == std::to_string(examIdToFind)) {
                Exam found(stoi(fields.at(0)), fields.at(1), fields.at(2), fields.at(3), stod(fields.at(4)));
                return found;
            }
        }
    }
    inFile.close();
}

std::vector<Exam> Exam::findByCorrected(const std::string &filename) {
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
            std::vector<Question> questions;
            std::string questionsID(fields.at(6));
            questionsID.erase(0, questionsID.find_first_not_of('['));
            questionsID.erase(questionsID.find_last_not_of(']') + 1);
            std::string questionID;
            std::stringstream questionsStream(questionsID);
            while (getline(questionsStream, questionID, '-')) {
                std::vector<std::string> parts;
                std::string part;
                std::stringstream questionStream(questionID);
                while (getline(questionStream, token, ':')) {
                    parts.push_back(part);
                }

                if (parts.at(0) == "D") {
                    Question question = Question::findByQuestionID("data/descriptiveQuestion.csv", parts.at(1));
                    questions.push_back(question);
                } else if (parts.at(0) == "M") {
                    Question question = Question::findByQuestionID("data/multipleChoiceQuestion.csv", parts.at(1));
                    questions.push_back(question);
                }
            }
            if (fields.at(5) == std::to_string(false)) {
                Exam exam(stoi(fields.at(0)), fields.at(1), fields.at(2), fields.at(3), stod(fields.at(4)));
                exam.questions = questions;
                exams.push_back(exam);
            }
        }
    }
    inFile.close();
    return exams;
}