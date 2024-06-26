//
// Created by erfan on 4/10/2024.
//

#ifndef GOOGLE_FORM_QUESTION_H
#define GOOGLE_FORM_QUESTION_H

#include <string>
#include <vector>

enum class type { Descriptive, MultipleChoice };

class Question {
public:
    Question(type type, std::string questionID, std::string prompt, int time,
             double score);
    type type;
    std::string questionID;
    std::string prompt;
    std::string description;
    int time{};                     // seconds
    std::pair<double, double> score;// (studentScore, maxScore)
    std::vector<std::pair<std::string, std::string>>
            answer;// (studentId, studentAnswer)
    virtual void saveToFile(const std::string &filename) const;
    void changeDescription(std::string comment);
    static std::string enumToString(enum type value);
    static enum type stringToType(const std::string &str);
};

#endif//GOOGLE_FORM_QUESTION_H
