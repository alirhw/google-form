//
// Created by erfan on 4/10/2024.
//

#ifndef GOOGLE_FORM_MULTIPLECHOICEQUESTION_H
#define GOOGLE_FORM_MULTIPLECHOICEQUESTION_H

#include "question.h"
#include <string>

class MultipleChoiceQuestion : public Question {
public:
    MultipleChoiceQuestion(enum type type, std::string prompt, std::string description, int time, double score, std::string options[4], std::string _correctAnswer) : Question(type, prompt, description, time, score);
    std::string options[4];
    std::string correctAnswer;

    void saveToFile(const std::string &filename) const;
};

#endif//GOOGLE_FORM_MULTIPLECHOICEQUESTION_H
