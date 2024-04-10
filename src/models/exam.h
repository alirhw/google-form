//
// Created by erfan on 4/10/2024.
//

#ifndef GOOGLE_FORM_EXAM_H
#define GOOGLE_FORM_EXAM_H

#include "question.h"
#include <string>
#include <utility>

class Exam {
public:
    int examId;
    std::string examName;
    std::string examDate;
    std::string examTime;
    double totalScore;
    Question *questions[100];                      // Assuming a maximum of 100 questions
    std::pair<std::string, int> studentScores[100];// Pair of student username and score
};

#endif//GOOGLE_FORM_EXAM_H
