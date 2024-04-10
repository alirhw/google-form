//
// Created by erfan on 4/10/2024.
//

#ifndef GOOGLE_FORM_QUESTION_H
#define GOOGLE_FORM_QUESTION_H

#include <string>

enum type { Descriptive,
            MultipleChoice };

class Question {
public:
    type type;
    std::string prompt;
    std::string description;
    int time;// seconds
    double score;
};

#endif//GOOGLE_FORM_QUESTION_H
