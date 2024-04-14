//
// Created by erfan on 4/14/2024.
//
#include "studentGroup.h"

#include <fstream>
#include <iostream>
#include <utility>


StudentGroup::StudentGroup(std::string name, int count) {
    this->name = std::move(name);
    this->count = count;
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
    outFile << count << ",";// StudentGroup Count
    outFile << "[";
    for (int i = 0; i < count; ++i) {
        outFile << students[i].username << "-";
    }
    outFile << "]"
            << "\n";

    // Close the file
    outFile.close();
}
