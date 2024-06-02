//
// Created by erfan on 6/2/2024.
//

#ifndef GOOGLE_FORM_STUDENTRANKING_H
#define GOOGLE_FORM_STUDENTRANKING_H

#include <map>
#include <string>
#include <utility>
#include <vector>

struct StudentRanking {
    StudentRanking(std::string name) : name(std::move(name)) {}
    std::string name;
    std::map<std::string, double> scores;// exam name -> score
    double average_score{};
    int rank{};
    static double calculate_average(StudentRanking &student,
                             const std::vector<std::string> &selected_exams);
    static void rank_students(std::vector<StudentRanking> &students,
                       const std::vector<std::string> &selected_exams);
};

#endif//GOOGLE_FORM_STUDENTRANKING_H
