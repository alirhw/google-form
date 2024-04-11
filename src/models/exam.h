#endif//GOOGLE_FORM_EXAM_H
///
// Created by erfan on 4/10/2024.
//

#ifndef GOOGLE_FORM_EXAM_H
#define GOOGLE_FORM_EXAM_H

#include "question.h"
#include <string>
#include <utility>

class Exam {
public:
	 Exam(int _examId, std::string _examName, std::string _examDate, std::string _examTime, double _totalScore);
    int examId;
    std::string examName;
    std::string examDate;
    std::string examTime;
    double totalScore;
    Question *questions[100]{};                      // Assuming a maximum of 100 questions
    std::pair<std::string, int> studentScores[100];// Pair of student username and score
    void saveToFile(const std::string &filename) const;
};

#endif//GOOGLE_FORM_EXAM_H

