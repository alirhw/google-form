//
// Created by erfan on 4/8/2024.
//

#ifndef GOOGLE_FORM_USER_H
#define GOOGLE_FORM_USER_H

#include <string>

class User {
public:
    std::string fullname;
    std::string username;
    std::string password;

    User(std::string fullname, std::string username, std::string password);
};

#endif//GOOGLE_FORM_USER_H
