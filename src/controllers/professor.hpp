//
// Created by erfan on 4/14/2024.
//

#include "../models/exam.h"
#include "../models/studentGroup.h"

class Manager {
public:
    static void createStudentGroup(std::string &name) {
        StudentGroup studentGroup(name);
        studentGroup.saveToFile("data/studentGroups.csv");
    }
    static void createExam(int examId, std::string examName, std::string examDate, std::string examTime, double totalScore) {
        Exam exam(examId, examName, examDate, examTime, totalScore);
        exam.saveToFile("data/exam.csv");
    }
};
