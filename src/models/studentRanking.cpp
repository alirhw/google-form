//
// Created by erfan on 6/2/2024.
//

#include "studentRanking.h"
#include <algorithm>
#include <vector>

double StudentRanking::calculate_average(
        StudentRanking &student,
        const std::vector<std::string> &selected_exams) {
    double total = 0;
    int count = 0;
    for (const auto &exam: selected_exams) {
        if (student.scores.find(exam) != student.scores.end()) {
            total += student.scores.at(exam);
            count++;
        }
    }
    return count ? total / count : 0;
}

void StudentRanking::rank_students(
        std::vector<StudentRanking> &students,
        const std::vector<std::string> &selected_exams) {
    for (auto &student: students) {
        student.average_score = calculate_average(student, selected_exams);
    }

    std::sort(students.begin(), students.end(),
              [](const StudentRanking &a, const StudentRanking &b) {
                  return a.average_score < b.average_score;
              });

    for (size_t i = 0; i < students.size(); ++i) { students[i].rank = i + 1; }
}
