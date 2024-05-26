//
// Created by erfan on 4/14/2024.
//

#include <utility>

#include "../models/descriptiveQuestion.h"
#include "../models/exam.h"
#include "../models/multipleChoiceQuestion.h"
#include "../models/student.h"
#include "../models/studentGroup.h"

class ProfessorManager {
public:
    static void createStudentGroup(std::string &name) {
        StudentGroup studentGroup(name);
        studentGroup.saveToFile("data/studentGroups.csv");
    }
    static void createExam(int examId, std::string examName,
                           std::string examDate) {
        Exam exam(examId, std::move(examName), std::move(examDate));
        exam.saveToFile("data/exam.csv");
    }
    static void createMultipleChoiceQuestion(int time, std::string questionID,
                                             const int &examId,
                                             std::string prompt, double score,
                                             type type,
                                             std::vector<std::string> options,
                                             std::string correctAnswer) {
        MultipleChoiceQuestion multipleChoiceQuestion(
                type, std::move(questionID), std::move(prompt), time, score,
                std::move(options), std::move(correctAnswer));
        multipleChoiceQuestion.saveToFile("data/multipleChoiceQuestion.csv");
        Exam exam = Exam::findByExamId("data/exam.csv", examId);
        exam.questions.push_back(std::make_unique<MultipleChoiceQuestion>(
                type, std::move(questionID), std::move(prompt), time, score,
                std::move(options), std::move(correctAnswer)));
        exam.examTime += multipleChoiceQuestion.time;
        exam.totalScore += multipleChoiceQuestion.score.second;
        exam.saveToFile("data/exam.csv");
    }
    static void createDescriptiveQuestion(int time, std::string questionID,
                                          const int &examId,
                                          std::string prompt, double score,
                                          enum type type) {
        DescriptiveQuestion descriptiveQuestion(
                type, std::move(questionID), std::move(prompt), time, score);
        descriptiveQuestion.saveToFile("data/descriptiveQuestion.csv");
        Exam exam = Exam::findByExamId("data/exam.csv", examId);
        exam.questions.push_back(std::make_unique<DescriptiveQuestion>(
                type, std::move(questionID), std::move(prompt), time, score));
        exam.examTime += descriptiveQuestion.time;
        exam.totalScore += descriptiveQuestion.score.second;
        exam.saveToFile("data/exam.csv");
    }
    static void addStudentToGroup(const std::string &name,
                                  const std::vector<std::string> &usernames) {
        for (const std::string &username: usernames) {
            Student student =
                    Student::findByUsername("data/credentials.csv", username);
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
    static void addStudentGroupToExam(int &examId,
                                      std::string &studentGroupName) {
        Exam exam = Exam::findByExamId("data/exam.csv", examId);
        StudentGroup studentGroup = StudentGroup::findByGroupName(
                "data/studentGroups.csv", studentGroupName);
        for (auto &student: studentGroup.students) {
            exam.studentScores.emplace_back(student.username, 0);
        }
        exam.saveToFile("data/exam.csv");
    }
    static void getAllExamToBeCorrect(std::vector<Exam> &examsToBeCorrect) {
        examsToBeCorrect = Exam::findByCorrected("data/exam.csv");
    }
};
