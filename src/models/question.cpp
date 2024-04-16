//
// Created by alirhw on 4/11/2024.
//

#include "question.h"

#include <fstream>
#include <iostream>
#include <utility>


Question::Question(type _type , std::string _prompt,std::string _description,int _time,  double _score) {
	
	type =_type;
    prompt= std::move(_prompt);
    description=std::move(_description);
    time=_time;
    score=_score;
}

void Question::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);

    // Check if file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Write exam data to csv file
    outFile << type << ","; 
    outFile << prompt << ","; 
    outFile << description << ",";
    outFile << time << ","; 
    outFile << score << "," << std::endl; 

    // Close the file
    outFile.close();
}

