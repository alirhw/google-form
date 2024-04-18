//
// Created by erfan on 4/14/2024.
//

#include <utility>

#include "../models/descriptiveQuestion.h"
#include "../models/exam.h"
#include "../models/multipleChoiceQuestion.h"
#include "../models/student.h"
#include "../models/studentGroup.h"

class Manager {
public:
    static void createStudentGroup(std::string &name) {
        StudentGroup studentGroup(name);
        studentGroup.saveToFile("data/studentGroups.csv");
    }
    static void createExam(int examId, std::string examName, std::string examDate, std::string examTime, double totalScore) {
        Exam exam(examId, std::move(examName), std::move(examDate), std::move(examTime), totalScore);
        exam.saveToFile("data/exam.csv");
    }
    static void createMultipleChoiceQuestion(int time,std::string questionID,std::string prompt, std::string description, double score, type type, std::string options[4], std::string correctAnswer) {
        MultipleChoiceQuestion multipleChoiceQuestion(type,std::move(questionID),std::move(prompt), std::move(description), time, score, options, std::move(correctAnswer));
        multipleChoiceQuestion.saveToFile("data/multipleChoiceQuestion.csv");
    }
    static void createDescriptiveQuestion(int time,std::string questionID,std::string prompt, std::string description, double score, type type, std::string answer) {
        DescriptiveQuestion descriptiveQuestion(type,std::move(questionID),std::move(prompt), std::move(description), time, score, std::move(answer));
        descriptiveQuestion.saveToFile("data/descriptiveQuestion.csv");
    }
    static void addStudentToGroup(const std::string &name, const std::vector<std::string> &usernames) {
        for (const std::string &username: usernames) {
            Student student = Student::findByUsername("data/credentials.csv", username);
            StudentGroup studentGroup(name);
            studentGroup.appendStudent(student);
            studentGroup.saveToFile("data/studentGroups.csv");
        }
    }
    static void getAllExams(std::vector<Exam> &exams) {
        exams = Exam::getAll("data/exam.csv");
    }
};
