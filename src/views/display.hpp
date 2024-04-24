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
        std::cout << "Please enter examDate " << std::endl;
        std::cout << "something like 1403/02/16 " << std::endl;
        getline(std::cin, examDate);
        std::cout << "Please enter examTime in minutes" << std::endl;
        getline(std::cin, examTime);
        std::cout << "Please enter totalScore" << std::endl;
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

    static void printTableRow(const std::string &col1, const std::string &col2, const std::string &col3, const std::string &col4, const std::string &col5, const std::string &col6, int width) {
        std::cout << "| " << std::setw(width / 2) << col1 << std::setw(width / 2) << " | " << std::setw(width / 2) << col2 << std::setw(width / 2) << " | " << std::setw(width / 2) << col3 << std::setw(width / 2) << " |" << std::setw(width / 2) << col4 << std::setw(width / 2) << " |" << std::setw(width / 2) << col5 << std::setw(width / 2) << " |" << std::setw(width / 2) << col6 << std::setw(width / 2) << " |" << std::endl;
    }

    static void examHistory(const std::vector<Exam> &exams) {
        const int columnWidth = 20;
        for (auto &&exam: exams) {
            printHorizontalLine((columnWidth + 1) * 6);
            printTableRow("ID", "Name", "Date", "Time", "Score", "Corrected", columnWidth);
            printHorizontalLine((columnWidth + 1) * 6);
            printTableRow(std::to_string(exam.examId), exam.examName, exam.examDate, exam.examTime, std::to_string(exam.totalScore), std::to_string(exam.corrected), columnWidth);
            printHorizontalLine((columnWidth + 1) * 6);
            for (auto &studentScore: exam.studentScores) {
                printHorizontalLine((columnWidth + 1) * 2);
                std::cout << "| " << std::setw(columnWidth / 2) << "Student ID" << std::setw(columnWidth / 2) << " | " << std::setw(columnWidth / 2) << "Score" << std::setw(columnWidth / 2) << " | " << std::endl;
                printHorizontalLine((columnWidth + 1) * 2);
                std::cout << "| " << std::setw(columnWidth / 2) << studentScore.first << std::setw(columnWidth / 2) << " | " << std::setw(columnWidth / 2) << studentScore.second << std::setw(columnWidth / 2) << " | " << std::endl;
                printHorizontalLine((columnWidth + 1) * 2);
            }
        }
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
        printHorizontalLine((columnWidth + 1) * 2);
        std::cout << "| " << std::setw(columnWidth / 2) << "Student Username" << std::setw(columnWidth / 2) << " | " << std::setw(columnWidth / 2) << "Student Fullname" << std::setw(columnWidth / 2) << " | " << std::endl;
        printHorizontalLine((columnWidth + 1) * 2);
        for (const auto &student: studentGroups.at(studentGroupId).students) {
            std::cout << "| " << std::setw(columnWidth / 2) << student.username << std::setw(columnWidth / 2) << " | " << std::setw(columnWidth / 2) << student.fullname << std::setw(columnWidth / 2) << " | " << std::endl;
        }
        printHorizontalLine((columnWidth + 1) * 2);
    }

    static void addStudentGroupToExam(int &examId, std::string &studentGroupName) {
        std::cout << "Please enter examId" << std::endl;
        std::cin >> examId;
        std::cout << "Please enter student group name" << std::endl;
        getline(std::cin, studentGroupName);
    }

    static void examToBeCorrect(std::vector<Exam> &examsToBeCorrect) {
        int examID;
        std::cout << "Please enter choose of the exams to start review and correct process" << std::endl;
        for (int i = 0; i < examsToBeCorrect.size(); ++i) {
            std::cout << i << ". "
                      << examsToBeCorrect.at(i).examName << std::endl;
        }
        std::cin >> examID;
        const int columnWidth = 20;
        for (Question question: examsToBeCorrect.at(examID).questions) {
            printHorizontalLine((columnWidth + 1) * 2);
            std::cout << "| " << std::setw(columnWidth / 2) << "Prompt" << std::setw(columnWidth / 2) << " | " << std::setw(columnWidth / 2) << question.prompt << std::setw(columnWidth / 2) << " | " << std::endl;
            printHorizontalLine((columnWidth + 1) * 2);
            std::cout << "| " << std::setw(columnWidth / 2) << "Answer" << std::setw(columnWidth / 2) << " | " << std::setw(columnWidth / 2) << question.answer << std::setw(columnWidth / 2) << " | " << std::endl;
            printHorizontalLine((columnWidth + 1) * 2);
            int command;
            std::cout << "1. Next Question!" << std::endl;
            std::cout << "2. Comment It!" << std::endl;
            if (question.type == Descriptive) {
                std::cout << "3. Score It!" << std::endl;
            }
            std::cin >> command;
            if (command == 1) {
                continue;
            } else if (command == 2) {
                std::string comment;
                std::cout << "Please leave your comment for this question:" << std::endl;
                std::getline(std::cin, comment);
                question.changeDescription(comment);
                if (question.type == MultipleChoice) {
                    question.saveToFile("data/multipleChoiceQuestion.csv");
                } else {
                    question.saveToFile("data/descriptiveQuestion.csv");
                }
            } else if (command == 3) {
                if (question.type == Descriptive) {
                    double score;
                    std::cout << "Please enter the student score according to answer from 0 to " << question.score.second << ":" << std::endl;
                    std::cin >> score;
                    question.score.first = score;
                    question.saveToFile("data/descriptiveQuestion.csv");
                }
            } else {
                std::cout << "Invalid Command!" << std::endl;
            }
        }
        examsToBeCorrect.at(examID).corrected = true;
        examsToBeCorrect.at(examID).saveToFile("data/exam.csv");
    }
};
