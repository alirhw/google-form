//
// Created by erfan on 4/10/2024.
//

#ifndef GOOGLE_FORM_QUESTION_H
#define GOOGLE_FORM_QUESTION_H

#include <string>

enum type { Descriptive = 0,
            MultipleChoice = 1 };

class Question {
public:
    Question(type _type, std::string questionID, std::string _prompt, std::string _description, int _time, double _score);
    type type;
    std::string questionID;
    std::string prompt;
    std::string description;
    int time{};// seconds
    double score{};
    static Question findByQuestionID(const std::string &filename, std::string questionID);
    virtual void saveToFile(const std::string &filename) const;
};

#endif//GOOGLE_FORM_QUESTION_H
