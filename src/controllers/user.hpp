//
// Created by erfan on 4/10/2024.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Authenticator {
public:
    static bool authenticate(const std::string &username, const std::string &password) {
        std::ifstream credentialsFile("data/credentials.csv");
        std::string line;

        if (!credentialsFile.is_open()) {
            std::cerr << "Error: Unable to open credentials file." << std::endl;
            return false;
        }

        // Read each line from the CSV file
        while (getline(credentialsFile, line)) {
            std::istringstream iss(line);
            std::string storedUsername, storedPassword, storedRole;

            // Parse the line into username, password, and role
            if (getline(iss, storedUsername, ',') &&
                getline(iss, storedPassword, ',') &&
                getline(iss, storedRole, ',')) {

                // Check if the provided username and password match the stored credentials
                if (username == storedUsername && password == storedPassword && storedRole == "professor") {
                    credentialsFile.close();
                    return true;// Authentication successful
                }
            }
        }

        credentialsFile.close();
        return false;// Authentication failed
    }
};
