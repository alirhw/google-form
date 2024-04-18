//
// Created by erfan on 4/8/2024.
//

#include "professor.h"
#include "student.h"

Professor::Professor(std::string fullname, std::string username, std::string password)
    : User(std::move(fullname), std::move(username), std::move(password)) {}
