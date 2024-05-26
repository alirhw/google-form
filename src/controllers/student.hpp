//
// Created by erfan on 5/24/2024.
//

#include <utility>

#include "../models/exam.h"

class StudentManager {
public:
    static void getAllExamToBeTake(std::vector<Exam> &examsToBeTake) {
        examsToBeTake = Exam::findByTakeAble("data/exam.csv");
    }
};
