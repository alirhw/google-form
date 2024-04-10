#include "src/controllers/user.hpp"
#include "src/views/login.hpp"
#include "src/views/professorDashboard.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string username, password;
    displayLogin(username, password);
    if (Authenticator::authenticate(username, password)) {
        int choice;

        while (true) {
            displayMenu(username);
            cin >> choice;

            switch (choice) {
                case 0:
                    std::cout << "0. Exit" << std::endl;
                    exit(0);
                    break;
                case 1:
                    std::cout << "1. Create New Exam" << std::endl;
                    break;
                case 2:
                    std::cout << "2. View Exam History" << std::endl;
                    break;
                case 3:
                    std::cout << "3. Create New Question" << std::endl;
                    break;
                case 4:
                    std::cout << "4. Create Student Group" << std::endl;
                    break;
                case 5:
                    std::cout << "5. View Student Groups" << std::endl;
                    break;
                case 6:
                    std::cout << "6. Add Student To Groups" << std::endl;
                    break;
                case 7:
                    std::cout << "7. Exam To Be Correct" << std::endl;
                    break;
                default:
                    cout << "Invalid choice. Please choose again." << endl;
                    break;
            }
        }
    } else {
        cout << "Invalid username, password, or role. Login failed." << endl;
    }

    return 0;
}
