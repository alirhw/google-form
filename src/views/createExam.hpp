//
// Created by alirhw on 4/11/2024.
//

#include <iostream>


void displayCreateExam(int &examId, std::string &examName, std::string &examDate, std::string &examTime, double &totalScore) {
    std::cout << "Please enter examId" << std::endl;
    std::cin >> examId;
    std::cout << "Please enter examName" << std::endl;
    getline(std::cin, examName);
    std::cout << "Please enter examDate" << std::endl;
    getline(std::cin, examDate);
    std::cout << "Please enter examTime" << std::endl;
    getline(std::cin, examTime);
    std::cout << "Please enter totalScore" << std::endl;
    std::cin >> totalScore;
}

