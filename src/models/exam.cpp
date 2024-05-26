//
// Created by alirhw on 4/11/2024.
//

#include "exam.h"
#include "descriptiveQuestion.h"
#include "multipleChoiceQuestion.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <utility>
#include <vector>


Exam::Exam(int examId, std::string examName, std::string examDate) {
    this->examId = examId;
    this->examName = std::move(examName);
    this->examDate = std::move(examDate);
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
        while (getline(ss, token, ',')) { fields.push_back(token); }
        if (fields.at(0) == std::to_string(this->examId)) {
            found = true;
            updatedLine = std::to_string(this->examId) + "," + this->examName +
                          "," + this->examDate + "," +
                          std::to_string(this->examTime) + "," +
                          std::to_string(this->totalScore) + "," +
                          std::to_string(this->corrected) + ",";
            updatedLine += "[";
            for (const auto &question: this->questions) {
                updatedLine += question->questionID + "-";
            }
            updatedLine += "],";
            updatedLine += "[";
            for (const auto &student: this->studentScores) {
                updatedLine += "(" + student.first + ":" +
                               std::to_string(student.second) + ")" + "-";
            }
            updatedLine += "],";
            updatedLine += std::to_string(this->takeable);
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
        updatedLine = std::to_string(this->examId) + "," + this->examName +
                      "," + this->examDate + "," +
                      std::to_string(this->examTime) + "," +
                      std::to_string(this->totalScore) + "," +
                      std::to_string(this->corrected) + ",";
        updatedLine += "[";
        for (const auto &question: this->questions) {
            updatedLine += question->questionID + "-";
        }
        updatedLine += "],";
        updatedLine += "[";
        for (const auto &student: this->studentScores) {
            updatedLine += "(" + student.first + "," +
                           std::to_string(student.second) + ")" + "-";
        }
        updatedLine += "],";
        updatedLine += std::to_string(this->takeable);
        updatedLines.push_back(updatedLine);
    }

    for (const std::string &l: updatedLines) {
        if (!l.empty()) { outFile << l << std::endl; }
    }

    outFile.close();
}

std::vector<Exam> Exam::getAll(const std::string &filename) {
    std::ifstream inFile(filename, std::ios::app);
    // Check if file opened successfully
    if (!inFile.is_open()) { std::cerr << "Error opening file!" << std::endl; }

    std::vector<Exam> exams;
    std::string line;
    while (std::getline(inFile, line)) {
        if (line.empty()) continue;
        std::vector<std::string> fields;
        std::string token;
        std::stringstream ss(line);
        while (getline(ss, token, ',')) { fields.push_back(token); }
        std::vector<std::unique_ptr<Question>> questions;
        std::string questionsID(fields.at(6));
        questionsID.erase(0, questionsID.find_first_not_of('['));
        questionsID.erase(questionsID.find_last_not_of(']') + 1);
        std::string questionID;
        std::stringstream questionsStream(questionsID);
        while (getline(questionsStream, questionID, '-')) {
            std::vector<std::string> parts;
            std::string part;
            std::stringstream questionStream(questionID);
            while (getline(questionStream, part, ':')) {
                parts.push_back(part);
            }

            if (parts.at(0) == "D") {
                DescriptiveQuestion question =
                        DescriptiveQuestion::findByQuestionID(
                                "data/descriptiveQuestion.csv", questionID);
                auto des = std::make_unique<DescriptiveQuestion>(
                        question.type, question.questionID, question.prompt,
                        question.time, question.score.second);
                des->description = question.description;
                des->score.first = question.score.first;
                questions.push_back(std::move(des));
            } else if (parts.at(0) == "M") {
                MultipleChoiceQuestion question =
                        MultipleChoiceQuestion::findByQuestionID(
                                "data/multipleChoiceQuestion.csv", questionID);
                auto mul = std::make_unique<MultipleChoiceQuestion>(
                        question.type, question.questionID, question.prompt,
                        question.time, question.score.second, question.options,
                        question.correctAnswer);
                mul->description = question.description;
                mul->score.first = question.score.first;
                questions.push_back(std::move(mul));
            }
        }
        Exam exam(stoi(fields.at(0)), fields.at(1), fields.at(2));
        for (const auto &question: questions) {
            if (auto mcq = dynamic_cast<MultipleChoiceQuestion *>(
                        question.get())) {
                auto mul = std::make_unique<MultipleChoiceQuestion>(
                        mcq->type, mcq->questionID, mcq->prompt, mcq->time,
                        mcq->score.second, mcq->options, mcq->correctAnswer);
                mul->description = mcq->description;
                mul->score.first = mcq->score.first;
                exam.questions.push_back(std::move(mul));
            } else if (auto dq = dynamic_cast<DescriptiveQuestion *>(
                               question.get())) {
                auto des = std::make_unique<DescriptiveQuestion>(
                        dq->type, dq->questionID, dq->prompt, dq->time,
                        dq->score.second);
                des->description = dq->description;
                des->score.first = dq->score.first;
                exam.questions.push_back(std::move(des));
            }
        }
        std::vector<std::pair<std::string, int>> studentScores;
        std::string scores(fields.at(7));
        scores.erase(0, scores.find_first_not_of('['));
        scores.erase(scores.find_last_not_of(']') + 1);
        std::string score;
        std::stringstream scoresStream(scores);
        while (getline(scoresStream, score, '-')) {
            score.erase(0, score.find_first_not_of('('));
            score.erase(score.find_last_not_of(')') + 1);
            std::vector<std::string> parts;
            std::string part;
            std::stringstream scoreStream(score);
            while (getline(scoreStream, part, ':')) { parts.push_back(part); }
            exam.studentScores.emplace_back(parts.at(0), stoi(parts.at(1)));
        }
        exam.examTime += stoi(fields.at(3));
        exam.totalScore += stod(fields.at(4));
        exam.corrected = fields.at(5) == "1";
        exam.takeable = fields.at(8) == "1";
        exams.push_back(std::move(exam));
    }
    inFile.close();
    return exams;
}

Exam Exam::findByExamId(const std::string &filename, const int &examIdToFind) {
    std::vector<Exam> exams = Exam::getAll(filename);
    for (auto &exam: exams) {
        if (exam.examId == examIdToFind) { return std::move(exam); }
    }
}

std::vector<Exam> Exam::findByCorrected(const std::string &filename) {
    std::vector<Exam> correctableExams;
    std::vector<Exam> exams = Exam::getAll(filename);
    for (auto &exam: exams) {
        if (!exam.corrected) correctableExams.push_back(std::move(exam));
    }
    return correctableExams;
}

std::vector<Exam> Exam::findByTakeAble(const std::string &filename) {
    std::vector<Exam> takeAbleExams;
    std::vector<Exam> exams = Exam::getAll(filename);
    for (auto &exam: exams) {
        if (exam.takeable) takeAbleExams.push_back(std::move(exam));
    }
    return takeAbleExams;
}