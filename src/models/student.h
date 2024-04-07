//
// Created by erfan on 4/8/2024.
//

#ifndef GOOGLE_FORM_STUDENT_H
#define GOOGLE_FORM_STUDENT_H

#include "user.h"

class Student : public User {
public:
    Student(std::string fullname, std::string username, std::string password);
};

#endif//GOOGLE_FORM_STUDENT_H
