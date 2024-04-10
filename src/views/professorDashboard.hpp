//
// Created by erfan on 4/10/2024.
//

#include <iostream>


void displayMenu(const std::string &username) {
    std::cout << "Professor Dashboard! Welcome, " << username << "!" << std::endl;
    std::cout << "1. Create New Exam" << std::endl;
    std::cout << "2. View Exam History" << std::endl;
    std::cout << "3. Create New Question" << std::endl;
    std::cout << "4. Create Student Group" << std::endl;
    std::cout << "5. View Student Groups" << std::endl;
    std::cout << "6. Add Student To Groups" << std::endl;
    std::cout << "7. Exam To Be Correct" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choose an option: ";
}