//
// Created by erfan on 4/10/2024.
//

#ifndef GOOGLE_FORM_MULTIPLECHOICEQUESTION_H
#define GOOGLE_FORM_MULTIPLECHOICEQUESTION_H

#include "question.h"
#include <string>

class MultipleChoiceQuestion : public Question {
public:
    std::string options[4];
    std::string correctAnswer;
};

#endif//GOOGLE_FORM_MULTIPLECHOICEQUESTION_H
