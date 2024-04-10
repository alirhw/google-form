//
// Created by erfan on 4/10/2024.
//

#include <iostream>
#include <string>

void displayLogin(std::string &username, std::string &password) {
    std::cout << "Welcome to the Google Form!" << std::endl;
    std::cout << "Please enter your credentials :" << std::endl;

    // Get username
    std::cout << "Enter your username:";
    getline(std::cin, username);

    // Get password
    std::cout << "Enter your password:";
    getline(std::cin, password);
}