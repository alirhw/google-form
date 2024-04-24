//
// Created by erfan on 4/10/2024.
//

#ifndef GOOGLE_FORM_MULTIPLECHOICEQUESTION_H
#define GOOGLE_FORM_MULTIPLECHOICEQUESTION_H

#include "question.h"
#include <string>
#include <vector>

class MultipleChoiceQuestion : public Question {
public:
    MultipleChoiceQuestion(enum type type, std::string questionID, std::string prompt, std::string description, int time, double score, std::vector<std::string> options, std::string correctAnswer);
    std::vector<std::string> options;
    std::string correctAnswer;

    bool autoCorrector(std::string answer);
    void saveToFile(const std::string &filename) const;
};

#endif//GOOGLE_FORM_MULTIPLECHOICEQUESTION_H
