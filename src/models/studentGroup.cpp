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


StudentGroup::StudentGroup(std::string name) {
    this->name = std::move(name);
}

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

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inFile, line)) {
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] != ',' && line[i + 1] == ',') {
                if (line.substr(i + 1) == this->name) {
                    line = name + "," + "[";
                    for (const auto &student: students) {
                        line += student.username + "-";
                    }
                    line += "]\n";
                }
            }
        }
        lines.push_back(line);
    }
    inFile.close();

    std::ofstream outFile(filename, std::ios::app);
    // Check if file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    for (const std::string &l: lines) {
        if (!l.empty()) {
            outFile << line << std::endl;
        } else {
            outFile << name << ",";
            outFile << "[";
            for (const auto &student: students) {
                outFile << student.username << "-";
            }
            outFile << "]"
                    << "\n";
        }
    }

    outFile.close();
}

std::vector<StudentGroup> StudentGroup::getAll(const std::string &filename) {
    std::ifstream inFile(filename, std::ios::app);
    // Check if file opened successfully
    if (!inFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
    }

    std::vector<StudentGroup> studentGroups;
    std::string line;
    while (std::getline(inFile, line)) {
        std::vector<std::string> fields;
        std::string token;
        std::stringstream ss(line);
        while (getline(ss, token, ',')) {
            fields.push_back(token);
        }
        for (int i = 0; i < fields.size(); ++i) {
            std::string Usernames(fields.at(1));
            Usernames.erase(0, Usernames.find_first_not_of('['));
            Usernames.erase(Usernames.find_last_not_of(']') + 1);
            StudentGroup group(fields.at(0));
            std::string username;
            std::stringstream usernameStream(Usernames);
            while (getline(usernameStream, username, '-')) {
                Student student = Student::findByUsername("data/credentials.csv", username);
                group.appendStudent(student);
            }
            studentGroups.push_back(group);
        }
    }
    inFile.close();
    return studentGroups;
}