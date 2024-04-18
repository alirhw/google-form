//
// Created by alirhw on 4/11/2024.
//

#include "question.h"

#include <fstream>
#include <iostream>
#include <utility>


Question::Question(enum type type, std::string questionID,std::string prompt, std::string description, int time, double score) {
    type = type;
    questionID=std::move(questionID);
    prompt = std::move(prompt);
    description = std::move(description);
    time = time;
    score = score;
}
void Question::saveToFile(const std::string &filename) const {
}
