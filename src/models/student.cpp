//
// Created by erfan on 4/8/2024.
//

#include "student.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

Student::Student(std::string fullname, std::string username,
                 std::string password)
    : User(std::move(fullname), std::move(username), std::move(password)) {}

Student Student::findByUsername(const std::string &filename,
                                std::string username) {
    std::ifstream inFile(filename, std::ios::app);
    // Check if file opened successfully
    if (!inFile.is_open()) { std::cerr << "Error opening file!" << std::endl; }

    std::string line;
    while (std::getline(inFile, line)) {
        std::vector<std::string> fields;
        std::string token;
        std::stringstream ss(line);
        while (getline(ss, token, ',')) { fields.push_back(token); }
        if (fields.at(0) == username && fields.at(2) == "student") {
            Student found(fields.at(3), fields.at(0), fields.at(1));
            return found;
        }
    }
    inFile.close();
}
