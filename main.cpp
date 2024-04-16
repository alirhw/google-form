#include "src/controllers/professor.hpp"
#include "src/controllers/user.hpp"
#include "src/views/display.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string username, password, studentGroupName;
    int examId;
	string examName,examDate, examTime
	double totalScore;

    Display::login(username, password);
    if (Authenticator::authenticate(username, password)) {
        int choice;

        while (true) {
            Display::menu(username);
            cin >> choice;

            switch (choice) {
                case 0:
                    std::cout << "0. Exit" << std::endl;
                    exit(0);
                case 1:
                    Display::createExam(examId, examName,examDate, examTime, totalScore);
                    Manager::createExam(examId, examName,examDate, examTime, totalScore);
                    break;
                case 2:
                    std::cout << "2. View Exam History" << std::endl;
                    break;
                case 3:
                    std::cout << "3. Create New Question" << std::endl;
                    break;
                case 4:
                    Display::createStudentGroup(studentGroupName);
                    Manager::createStudentGroup(studentGroupName);
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
