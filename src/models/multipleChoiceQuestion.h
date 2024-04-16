//
// Created by erfan on 4/10/2024.
//

#ifndef GOOGLE_FORM_MULTIPLECHOICEQUESTION_H
#define GOOGLE_FORM_MULTIPLECHOICEQUESTION_H

#include "question.h"
#include <string>

class MultipleChoiceQuestion : public Question {
public:
	MultipleChoiceQuestion(std::string _options[4], std::string _correctAnswer);
    std::string options[4];
    std::string correctAnswer;
    
     void saveToFile(const std::string &filename) const;
};

#endif//GOOGLE_FORM_MULTIPLECHOICEQUESTION_H
