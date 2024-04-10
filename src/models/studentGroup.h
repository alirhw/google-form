//
// Created by erfan on 4/10/2024.
//

#ifndef GOOGLE_FORM_STUDENTGROUP_H
#define GOOGLE_FORM_STUDENTGROUP_H

#include "student.h"
#include <string>

class StudentGroup {
public:
    std::string name;
    int count;
    Student *students[100];// Assuming a maximum of 100 students
};

#endif//GOOGLE_FORM_STUDENTGROUP_H
