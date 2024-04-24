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
    static void createMultipleChoiceQuestion(int time, std::string questionID, const int &examId, std::string prompt, std::string description, double score, type type, std::string options[4], std::string correctAnswer) {
        MultipleChoiceQuestion multipleChoiceQuestion(type, std::move(questionID), std::move(prompt), std::move(description), time, score, options, std::move(correctAnswer));
        multipleChoiceQuestion.saveToFile("data/multipleChoiceQuestion.csv");
        Exam exam = Exam::findByExamId("data/exam.csv", examId);
        exam.questions.push_back(multipleChoiceQuestion);
        exam.saveToFile("data/exam.csv");
    }
    static void createDescriptiveQuestion(int time, std::string questionID, const int &examId, std::string prompt, std::string description, double score, type type) {
        DescriptiveQuestion descriptiveQuestion(type, std::move(questionID), std::move(prompt), std::move(description), time, score);
        descriptiveQuestion.saveToFile("data/descriptiveQuestion.csv");
        Exam exam = Exam::findByExamId("data/exam.csv", examId);
        exam.questions.push_back(descriptiveQuestion);
        exam.saveToFile("data/exam.csv");
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
    static void getAllStudentGroups(std::vector<StudentGroup> &studentGroups) {
        studentGroups = StudentGroup::getAll("data/studentGroups.csv");
    }
    static void addStudentGroupToExam(int &examId, std::string &studentGroupName) {
        Exam exam = Exam::findByExamId("data/exam.csv", examId);
        StudentGroup studentGroup = StudentGroup::findByGroupName("data/studentGroups.csv", studentGroupName);
        for (auto &student: studentGroup.students) {
            exam.studentScores.emplace_back(student.username, 0);
        }
        exam.saveToFile("data/exam.csv");
    }
    static void getAllExamToBeCorrect(std::vector<Exam> &examsToBeCorrect) {
        examsToBeCorrect = Exam::findByCorrected("data/exam.csv");
    }
};
