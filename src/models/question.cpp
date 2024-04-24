//
// Created by alirhw on 4/11/2024.
//

#include "question.h"

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <utility>
#include <vector>


Question::Question(enum type type, std::string questionID, std::string prompt, std::string description = "", int time = 0, double score = 0) {
    this->type = type;
    this->questionID = std::move(questionID);
    this->prompt = std::move(prompt);
    this->description = std::move(description);
    this->time = time;
    this->score.first = 0;
    this->score.second = score;
}

Question Question::findByQuestionID(const std::string &filename, std::string questionID) {
    std::ifstream inFile(filename, std::ios::app);
    // Check if file opened successfully
    if (!inFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::vector<std::string> fields;
        std::string token;
        std::stringstream ss(line);
        while (getline(ss, token, ',')) {
            fields.push_back(token);
        }
        if (fields.at(0) == questionID) {
            Question found(static_cast<enum type>(reinterpret_cast<bool &>(fields.at(3))), fields.at(0), fields.at(1));
            return found;
        }
    }
    inFile.close();
}

void Question::changeDescription(std::string comment) {
    this->description = std::move(comment);
}

void Question::saveToFile(const std::string &filename) const {
}

std::string Question::enumToString(enum type value) {
    switch (value) {
        case type::Descriptive:
            return "Descriptive";
        case type::MultipleChoice:
            return "MultipleChoice";
        default:
            throw std::invalid_argument("Invalid enum value");
    }
}