//
// Created by erfan on 4/10/2024.
//

#ifndef GOOGLE_FORM_STUDENTGROUP_H
#define GOOGLE_FORM_STUDENTGROUP_H

#include "student.h"
#include <string>
#include <vector>

class StudentGroup {
public:
    StudentGroup(std::string name);
    std::string name;
    std::vector<Student> students;
    void appendStudent(const Student &student);
    void saveToFile(const std::string &filename) const;
};

#endif//GOOGLE_FORM_STUDENTGROUP_H
