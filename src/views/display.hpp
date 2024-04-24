#include <iomanip>
#include <iostream>
#include <string>

class Display {
public:
    static void login(std::string &username, std::string &password) {
        std::cout << "Welcome to the Google Form!" << std::endl;
        std::cout << "Please enter your credentials:" << std::endl;

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
        std::cout << "8. Add Student Group To Exam" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Choose an option:";
    }

    static void createMultipleChoiceQuestion(std::string options[4], std::string &correctAnswer) {
        std::cout << "Please Enter Options 1:" << std::endl;
        getline(std::cin, options[0]);

        std::cout << "Please Enter Options 2:" << std::endl;
        getline(std::cin, options[1]);

        std::cout << "Please Enter Options 3:" << std::endl;
        getline(std::cin, options[2]);

        std::cout << "Please Enter Options 4:" << std::endl;
        getline(std::cin, options[3]);

        std::cout << "Please Enter Correct Answer:" << std::endl;
        getline(std::cin, correctAnswer);
    }

    static void createExam(int &examId, std::string &examName, std::string &examDate, std::string &examTime, double &totalScore) {
        std::cout << "Please nter examId" << std::endl;
        std::cin >> examId;
        std::cout << "Please Enter examName" << std::endl;
        getline(std::cin, examName);
        std::cout << "Please Enter examDate " << std::endl;
        std::cout << "something like 1403/02/16 " << std::endl;
        getline(std::cin, examDate);
        std::cout << "Please Enter examTime in minutes" << std::endl;
        getline(std::cin, examTime);
        std::cout << "Please Enter totalScore" << std::endl;
        std::cin >> totalScore;
    }

    static void createStudentGroup(std::string &name) {
        std::cout << "Please enter name:" << std::endl;
        std::getline(std::cin, name);
        std::cout << "Creating Student Group:" << name << std::endl;
    }

    static void CreateQuestion(type &type, std::string &questionID, int &examId, std::string &prompt, std::string &description, int &time, double &score) {

        std::cout << "Please enter type   Descriptive=0   MultipleChoice=1" << std::endl;
        std::cin >> reinterpret_cast<bool &>(type);
        std::cout << "Please enter questionID" << std::endl;
        getline(std::cin, questionID);
        std::cout << "Please enter exam id to want to add the question to" << std::endl;
        std::cin >> examId;
        std::cout << "Please enter prompt" << std::endl;
        getline(std::cin, prompt);
        std::cout << "Please enter description" << std::endl;
        getline(std::cin, description);
        std::cout << "Please enter  time in seconds " << std::endl;
        std::cin >> time;
        std::cout << "Please enter  score" << std::endl;
        std::cin >> score;
    }

    static void addToStudentGroup(std::string &name, std::vector<std::string> usernames) {
        int count;
        std::cout << "Please enter the group name:" << std::endl;
        std::getline(std::cin, name);
        std::cout << "Please enter the student count:" << std::endl;
        std::cin >> count;
        std::cout << "Please enter the students username (seperated by space):" << std::endl;
        for (int i = 0; i < count; ++i) {
            std::cin >> usernames[i];
        }
    }

    static void printHorizontalLine(int width) {
        for (int i = 0; i < width; ++i)
            std::cout << "-";
        std::cout << std::endl;
    }

    static void printTableRow(const std::string &col1, const std::string &col2, const std::string &col3, const std::string &col4, const std::string &col5, int width) {
        std::cout << "| " << std::setw(width / 2) << col1 << std::setw(width / 2) << " | " << std::setw(width / 2) << col2 << std::setw(width / 2) << " | " << std::setw(width / 2) << col3 << std::setw(width / 2) << " |" << std::setw(width / 2) << col4 << std::setw(width / 2) << " |" << std::setw(width / 2) << col5 << std::setw(width / 2) << " |" << std::endl;
    }

    static void examHistory(const std::vector<Exam> &exams) {
        const int columnWidth = 20;
        printHorizontalLine((columnWidth + 1) * 5);
        printTableRow("ID", "Name", "Date", "Time", "Score", columnWidth);
        printHorizontalLine((columnWidth + 1) * 5);
        for (auto &&exam: exams) {
            printTableRow(std::to_string(exam.examId), exam.examName, exam.examDate, exam.examTime, std::to_string(exam.totalScore), columnWidth);
        }
        printHorizontalLine((columnWidth + 1) * 5);
    }

    static void studentGroupHistory(const std::vector<StudentGroup> &studentGroups) {
        int studentGroupId;
        std::cout << "Please enter choose of the groups to see the detail" << std::endl;
        for (int i = 0; i < studentGroups.size(); ++i) {
            std::cout << i << ". "
                      << studentGroups.at(i).name << std::endl;
        }
        std::cin >> studentGroupId;
        const int columnWidth = 20;
        printHorizontalLine((columnWidth + 1) * 5);
        std::cout << "| " << std::setw(columnWidth / 2) << "Student Username" << std::setw(columnWidth / 2) << " | " << std::setw(columnWidth / 2) << "Student Fullname" << std::setw(columnWidth / 2) << " | " << std::endl;
        printHorizontalLine((columnWidth + 1) * 5);
        for (const auto &student: studentGroups.at(studentGroupId).students) {
            std::cout << "| " << std::setw(columnWidth / 2) << student.username << std::setw(columnWidth / 2) << " | " << std::setw(columnWidth / 2) << student.fullname << std::setw(columnWidth / 2) << " | " << std::endl;
        }
        printHorizontalLine((columnWidth + 1) * 5);
    }

    static void addStudentGroupToExam(int &examId, std::string &studentGroupName) {
        std::cout << "Please enter examId" << std::endl;
        std::cin >> examId;
        std::cout << "Please enter student group name" << std::endl;
        getline(std::cin, studentGroupName);
    }
};
