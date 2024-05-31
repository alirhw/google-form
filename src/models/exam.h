///
// Created by erfan on 4/10/2024.
//

#ifndef GOOGLE_FORM_EXAM_H
#define GOOGLE_FORM_EXAM_H

#include "question.h"
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Exam {
public:
    Exam(int examId, std::string examName, std::string examDate);
    int examId;
    std::string examName;
    std::string examDate;
    int examTime = 0;
    double totalScore = 0;
    bool corrected = false;
    bool takeable = false;
    std::vector<std::unique_ptr<Question>> questions;
    std::vector<std::pair<std::string, int>> studentScores;
    void saveToFile(const std::string &filename) const;
    static std::vector<Exam> getAll(const std::string &filename);
    static Exam findByExamId(const std::string &filename,
                             const int &examIdToFind);
    static std::vector<Exam> findByCorrected(const std::string &filename);
    static std::vector<Exam> findByTakeAble(const std::string &filename);
    static std::vector<Exam> findByNotTakeAble(const std::string &filename);
};

#endif//GOOGLE_FORM_EXAM_H
