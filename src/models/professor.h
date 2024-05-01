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
    Professor(std::string fullname, std::string username,
              std::string password);
};

#endif//GOOGLE_FORM_PROFESSOR_H
