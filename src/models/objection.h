//
// Created by erfan on 5/31/2024.
//

#ifndef GOOGLE_FORM_OBJECTION_H
#define GOOGLE_FORM_OBJECTION_H

#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

class Objection {
public:
    Objection(std::string text, std::string studentId, std::string examId)
        : text(std::move(text)), studentId(std::move(studentId)),
          examId(std::move(examId)),
          timestamp(std::chrono::system_clock::now()) {}
    std::string text;
    std::string answer;
    std::string studentId;
    std::string examId;
    std::chrono::system_clock::time_point timestamp;

    std::string getFormattedTimestamp() const;
    void saveToFile(const std::string &filename) const;
    static std::vector<Objection> getAll(const std::string &filename);
};


#endif//GOOGLE_FORM_OBJECTION_H
