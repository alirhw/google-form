//
// Created by erfan on 4/14/2024.
//

#include "../models/studentGroup.h"

class Manager {
public:
    static void createStudentGroup(std::string &name) {
        StudentGroup studentGroup(name);
        studentGroup.saveToFile("data/studentGroups.csv");
    }
};
