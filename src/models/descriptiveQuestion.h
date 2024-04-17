//
// Created by erfan on 4/10/2024.
//

#ifndef GOOGLE_FORM_DESCRIPTIVEQUESTION_H
#define GOOGLE_FORM_DESCRIPTIVEQUESTION_H

#include "question.h"

class DescriptiveQuestion : public Question {
public:
	DescriptiveQuestion(enum type type, std::string prompt, std::string description, int time, double score,std::string answer ) : Question(type, prompt, description, time, score);
    std::string answer;
    
    void saveToFile(const std::string &filename) const;
};

#endif//GOOGLE_FORM_DESCRIPTIVEQUESTION_H
