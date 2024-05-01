//
// Created by erfan on 4/8/2024.
//

#include "user.h"

User::User(std::string fullname, std::string username, std::string password)
    : fullname(std::move(fullname)), username(std::move(username)),
      password(std::move(password)) {}
