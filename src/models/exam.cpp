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
    this->examName = std::move(examName);
    this->examDate = std::move(examDate);
    this->examTime = std::move(examTime);
    this->totalScore = totalScore;
}

void Exam::saveToFile(const std::string &filename) const {
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
        while (getline(ss, token, ',')) {
            fields.push_back(token);
        }
        if (fields.at(0) == std::to_string(this->examId)) {
            found = true;
            updatedLine = std::to_string(this->examId) + "," + this->examName + "," + this->examDate + "," + this->examTime + "," + std::to_string(this->totalScore) + "," + std::to_string(this->corrected) + ",";
            updatedLine += "[";
            for (const auto &question: this->questions) {
                updatedLine += question.questionID + "-";
            }
            std::string questionsID(fields.at(6));
            questionsID.erase(0, questionsID.find_first_not_of('['));
            questionsID.erase(questionsID.find_last_not_of(']') + 1);
            updatedLine += questionsID;
            updatedLine += "],";
            updatedLine += "[";
            for (const auto &student: this->studentScores) {
                updatedLine += "(" + student.first + "," + std::to_string(student.second) + ")" + "-";
            }
            std::string studentsScore(fields.at(7));
            questionsID.erase(0, questionsID.find_first_not_of('['));
            questionsID.erase(questionsID.find_last_not_of(']') + 1);
            updatedLine += studentsScore;
            updatedLine += "]";
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
        updatedLine = std::to_string(this->examId) + "," + this->examName + "," + this->examDate + "," + this->examTime + "," + std::to_string(this->totalScore) + "," + std::to_string(this->corrected) + ",";
        updatedLine += "[";
        for (const auto &question: this->questions) {
            updatedLine += question.questionID + "-";
        }
        updatedLine += "],";
        updatedLine += "[";
        for (const auto &student: this->studentScores) {
            updatedLine += "(" + student.first + "," + std::to_string(student.second) + ")" + "-";
        }
        updatedLine += "]";
        updatedLines.push_back(updatedLine);
    }

    for (const std::string &l: updatedLines) {
        if (!l.empty()) {
            outFile << l << std::endl;
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
        if (line.empty()) continue;
        std::vector<std::string> fields;
        std::string token;
        std::stringstream ss(line);
        while (getline(ss, token, ',')) {
            fields.push_back(token);
        }
        Exam exam(stoi(fields.at(0)), fields.at(1), fields.at(2), fields.at(3), stod(fields.at(4)));
        exams.push_back(exam);
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
        if (fields.at(0) == std::to_string(examIdToFind)) {
            Exam found(stoi(fields.at(0)), fields.at(1), fields.at(2), fields.at(3), stod(fields.at(4)));
            return found;
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
    inFile.close();
    return exams;
}