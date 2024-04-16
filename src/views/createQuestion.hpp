//
// Created by alirhw on 4/16/2024.
//

#include <iostream>


void displayCreateQuestion(int &time, std::string &prompt, std::string &description,double &score,type &type) {
	
	std::cout << "Please enter type   Descriptive=0   MultipleChoice=1" << std::endl;
	std::cin>>type;///////????????
    std::cout << "Please enter prompt" << std::endl;
    getline(std::cin, prompt);
    std::cout << "Please enter description" << std::endl;
    getline(std::cin, description);
    std::cout << "Please enter  time" << std::endl;
    std::cin >>time;
    std::cout << "Please enter  score" << std::endl;
    std::cin >>score;
}

