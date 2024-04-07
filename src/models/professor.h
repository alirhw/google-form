//
// Created by erfan on 4/8/2024.
//

#ifndef GOOGLE_FORM_PROFESSOR_H
#define GOOGLE_FORM_PROFESSOR_H

#include "student.h"
#include "user.h"
#include <string>

class Professor : public User {
public:
    Professor(std::string fullname, std::string username, std::string password);

    // Function to create a new exam
    void createExam(const std::string &examName, const std::string &examDate, int totalScore);

    // Function to add a question to an exam
    void addQuestionToExam(int examId, const std::string &type, const std::string &prompt, int score);

    // Function to add students to an exam
    void addStudentsToExam(int examId, Student *students[], int numStudents);

    // Function to view exam results
    void viewExamResults(int examId);
};

#endif//GOOGLE_FORM_PROFESSOR_H
