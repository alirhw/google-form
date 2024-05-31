//
// Created by erfan on 5/24/2024.
//

#include <utility>

#include "../models/exam.h"

class StudentManager {
public:
    static void getAllExamToBeTake(std::vector<Exam> &examsToBeTake,
                                   const std::string &username) {
        auto exams = Exam::findByTakeAble("data/exam.csv");
        for (auto &exam: exams) {
            for (const auto &scores: exam.studentScores) {
                if (username == scores.first && scores.second == 0) {
                    examsToBeTake.push_back(std::move(exam));
                    break;
                }
            }
        }
    }
    static void getAllExamHistory(std::vector<Exam> &examsToBeTake,
                                  const std::string &username) {
        auto exams = Exam::findByNotTakeAble("data/exam.csv");
        for (auto &exam: exams) {
            for (const auto &scores: exam.studentScores) {
                if (username == scores.first) {
                    examsToBeTake.push_back(std::move(exam));
                    break;
                }
            }
        }
    }
};
