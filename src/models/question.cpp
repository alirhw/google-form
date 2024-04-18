//
// Created by alirhw on 4/11/2024.
//

#include "question.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>


Question::Question(enum type type, std::string questionID, std::string prompt, std::string description = "", int time = 0, double score = 0) {
    type = type;
    questionID = std::move(questionID);
    prompt = std::move(prompt);
    description = std::move(description);
    time = time;
    score = score;
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
        for (int i = 0; i < fields.size(); ++i) {
            if (fields.at(0) == questionID) {
                Question found(static_cast<enum type>(reinterpret_cast<bool &>(fields.at(3))), fields.at(0), fields.at(1));
                return found;
            }
        }
    }
    inFile.close();
}

void Question::saveToFile(const std::string &filename) const {
}
