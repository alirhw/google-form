//
// Created by alirhw on 4/11/2024.
//

#include <iostream>


void displayCreateMultipleChoiceQuestion( std::string &options[4], std::string &correctAnswer) {
    std::cout << "Please enter options1" << std::endl;
      getline(std::cin, options[0]);
      
    std::cout << "Please enter options2" << std::endl;
    getline(std::cin, options[1]);
    
    std::cout << "Please enter options3" << std::endl;
    getline(std::cin, options[2]);
    
    std::cout << "Please enter options4" << std::endl;
    getline(std::cin, options[3]);
    
    std::cout << "Please enter correctAnswer" << std::endl;
    getline(std::cin, correctAnswer);

}

