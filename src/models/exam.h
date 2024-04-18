///
// Created by erfan on 4/10/2024.
//

#ifndef GOOGLE_FORM_EXAM_H
#define GOOGLE_FORM_EXAM_H

#include "question.h"
#include <string>
#include <utility>
#include <vector>

class Exam {
public:
    Exam(int examId, std::string examName, std::string examDate, std::string examTime, double totalScore);
    int examId;
    std::string examName;
    std::string examDate;
    std::string examTime;
    double totalScore;
    std::vector<Question> questions;
    std::vector<std::pair<std::string, int>> studentScores;
    void saveToFile(const std::string &filename) const;
    static std::vector<Exam> getAll(const std::string &filename);
};

#endif//GOOGLE_FORM_EXAM_H
