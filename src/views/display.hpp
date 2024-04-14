#include <iostream>
#include <string>

class Display {
public:
    static void login(std::string &username, std::string &password) {
        std::cout << "Welcome to the Google Form!" << std::endl;
        std::cout << "Please enter your credentials :" << std::endl;

        // Get username
        std::cout << "Enter your username:";
        getline(std::cin, username);

        // Get password
        std::cout << "Enter your password:";
        getline(std::cin, password);
    }

    static void menu(const std::string &username) {
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

    static void createMultipleChoiceQuestion(std::string options[4], std::string &correctAnswer) {
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

    static void createExam(int &examId, std::string &examName, std::string &examDate, std::string &examTime, double &totalScore) {
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

    static void createStudentGroup(std::string &name) {
        std::cout << "Please enter name :" << std::endl;
        getline(std::cin, name);
    }
};
