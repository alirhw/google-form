//
// Created by erfan on 4/8/2024.
//

#include "professor.h"
#include "student.h"

Professor::Professor(std::string fullname, std::string username, std::string password)
    : User(std::move(fullname), std::move(username), std::move(password)) {}

// Function to create a new exam
void Professor::createExam(const std::string &examName, const std::string &examDate, int totalScore) {
    // Implementation to create a new exam
}

// Function to add a question to an exam
void Professor::addQuestionToExam(int examId, const std::string &type, const std::string &prompt, int score) {
    // Implementation to add a question to an exam
}

// Function to add students to an exam
void Professor::addStudentsToExam(int examId, Student *students[], int numStudents) {
    // Implementation to add students to an exam
}

// Function to view exam results
void Professor::viewExamResults(int examId) {
    // Implementation to view exam results
}
