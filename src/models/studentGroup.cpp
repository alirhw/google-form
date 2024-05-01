//
// Created by erfan on 4/14/2024.
//
#include "studentGroup.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>


StudentGroup::StudentGroup(std::string name) { this->name = std::move(name); }

void StudentGroup::appendStudent(const Student &student) {
    this->students.push_back(student);
}

void StudentGroup::saveToFile(const std::string &filename) const {
    std::ifstream inFile(filename, std::ios::app);
    // Check if file opened successfully
    if (!inFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::vector<std::string> lines{};
    std::string line = "";
    std::vector<std::string> updatedLines{};
    std::string updatedLine = "";
    bool found = false;
    while (std::getline(inFile, line)) {
        if (line.empty()) continue;
        std::vector<std::string> fields;
        std::string token;
        std::stringstream ss(line);
        while (getline(ss, token, ',')) { fields.push_back(token); }
        if (fields.at(0) == this->name) {
            found = true;
            updatedLine = name + "," + "[";
            for (const auto &student: students) {
                updatedLine += student.username + "-";
            }
            std::string studentsUsername(fields.at(1));
            studentsUsername.erase(0, studentsUsername.find_first_not_of('['));
            studentsUsername.erase(studentsUsername.find_last_not_of(']') + 1);
            updatedLine += studentsUsername;
            updatedLine += "]";
        } else {
            updatedLine = line;
        }
        updatedLines.push_back(updatedLine);
    }
    inFile.close();

    std::ofstream outFile(filename, std::ios::trunc);
    // Check if file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    if (!found) {
        updatedLine = name + "," + "[";
        for (const auto &student: students) {
            updatedLine += student.username + "-";
        }
        updatedLine += "]";
        updatedLines.push_back(updatedLine);
    }

    for (const std::string &l: updatedLines) {
        if (!l.empty()) { outFile << l << std::endl; }
    }

    outFile.close();
}

std::vector<StudentGroup> StudentGroup::getAll(const std::string &filename) {
    std::ifstream inFile(filename, std::ios::app);
    // Check if file opened successfully
    if (!inFile.is_open()) { std::cerr << "Error opening file!" << std::endl; }

    std::vector<StudentGroup> studentGroups;
    std::string line;
    while (std::getline(inFile, line)) {
        std::vector<std::string> fields;
        std::string token;
        std::stringstream ss(line);
        while (getline(ss, token, ',')) { fields.push_back(token); }
        std::string Usernames(fields.at(1));
        Usernames.erase(0, Usernames.find_first_not_of('['));
        Usernames.erase(Usernames.find_last_not_of(']') + 1);
        StudentGroup group(fields.at(0));
        std::string username;
        std::stringstream usernameStream(Usernames);
        while (getline(usernameStream, username, '-')) {
            Student student =
                    Student::findByUsername("data/credentials.csv", username);
            group.appendStudent(student);
        }
        studentGroups.push_back(group);
    }
    inFile.close();
    return studentGroups;
}

StudentGroup
StudentGroup::findByGroupName(const std::string &filename,
                              const std::string &groupNameToFind) {
    std::ifstream inFile(filename, std::ios::app);
    // Check if file opened successfully
    if (!inFile.is_open()) { std::cerr << "Error opening file!" << std::endl; }

    std::string line;
    while (std::getline(inFile, line)) {
        std::vector<std::string> fields;
        std::string token;
        std::stringstream ss(line);
        while (getline(ss, token, ',')) { fields.push_back(token); }
        if (fields.at(0) == groupNameToFind) {
            std::string Usernames(fields.at(1));
            Usernames.erase(0, Usernames.find_first_not_of('['));
            Usernames.erase(Usernames.find_last_not_of(']') + 1);
            StudentGroup group(fields.at(0));
            std::string username;
            std::stringstream usernameStream(Usernames);
            while (getline(usernameStream, username, '-')) {
                Student student = Student::findByUsername(
                        "data/credentials.csv", username);
                group.appendStudent(student);
            }
            return group;
        }
    }
    inFile.close();
}