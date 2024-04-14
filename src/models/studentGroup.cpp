//
// Created by erfan on 4/14/2024.
//
#include "studentGroup.h"

#include <fstream>
#include <iostream>
#include <utility>


StudentGroup::StudentGroup(std::string name) {
    this->name = std::move(name);
}

void StudentGroup::appendStudent(const Student &student) {
    this->students.push_back(student);
}

void StudentGroup::saveToFile(const std::string &filename) const {
    std::ofstream outFile(filename);

    // Check if file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Write studentGroup data to csv file
    outFile << name << ","; // StudentGroup Name
    outFile << "[";
    for (const auto & student : students) {
        outFile << student.username << "-";
    }
    outFile << "]"
            << "\n";

    // Close the file
    outFile.close();
}
