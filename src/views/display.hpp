#include <iomanip>
#include <iostream>
#include <map>
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
        std::cout << "***************************************************" << std::endl;
        std::cout << "**  Professor Dashboard! Welcome, " << username << "!      **" << std::endl;
        std::cout << "**  1. Create New Exam                           **" << std::endl;
        std::cout << "**  2. View Exam History                         **" << std::endl;
        std::cout << "**  3. Create New Question                       **" << std::endl;
        std::cout << "**  4. Create Student Group                      **" << std::endl;
        std::cout << "**  5. View Student Groups                       **" << std::endl;
        std::cout << "**  6. Add Student To Groups                     **" << std::endl;
        std::cout << "**  7. Exam To Be Correct                        **" << std::endl;
        std::cout << "**  8. Add Student Group To Exam                 **" << std::endl;
        std::cout << "**  0. Exit                                      **" << std::endl;
        std::cout << "***************************************************" << std::endl;
        std::cout << "Choose an option:";
    }

    static void createMultipleChoiceQuestion(std::vector<std::string> options, std::string &correctAnswer) {
        std::cout << "Please Enter Options 1:" << std::endl;
        std::cin.ignore();
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
        std::cout << "Please Enter Exam ID:" << std::endl;
        std::cin >> examId;

        std::cout << "Please Enter Exam Name:" << std::endl;
        std::cin.ignore();
        getline(std::cin, examName);

        std::cout << "Please Enter Exam Date (something like 1403/02/16):" << std::endl;
        getline(std::cin, examDate);

        std::cout << "Please Enter Exam Time In Minutes:" << std::endl;
        getline(std::cin, examTime);

        std::cout << "Please Enter Total Score:" << std::endl;
        std::cin >> totalScore;
    }

    static void createStudentGroup(std::string &name) {
        std::cout << "Please Enter Name:" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, name);
    }

    static type stringToType(const std::string &str) {
        static const std::map<std::string, type> enumMap = {
                {"Descriptive", type::Descriptive},
                {"MultipleChoice", type::MultipleChoice}};

        auto it = enumMap.find(str);
        if (it != enumMap.end()) {
            return it->second;
        } else {
            // Return a default value or throw an exception for invalid input
            throw std::invalid_argument("Invalid enum string");
        }
    }

    static void CreateQuestion(enum type &type, std::string &questionID, int &examId, std::string &prompt, std::string &description, int &time, double &score) {
        std::cout << "Please Enter Type (Descriptive || MultipleChoice):" << std::endl;
        std::string stype;
        std::cin >> stype;
        type = stringToType(stype);
        std::cout << "Please Enter Question ID:" << std::endl;
        std::cin.ignore();
        getline(std::cin, questionID);
        std::cout << "Please Enter Exam Id To Want To Add The Question To:" << std::endl;
        std::cin >> examId;
        std::cout << "Please Enter Prompt:" << std::endl;
        std::cin.ignore();
        getline(std::cin, prompt);
        std::cout << "Please Enter Description:" << std::endl;
        getline(std::cin, description);
        std::cout << "Please Enter Time In Seconds:" << std::endl;
        std::cin >> time;
        std::cout << "Please Enter Score:" << std::endl;
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

    static void examHistory(const std::vector<Exam> &exams) {
        const int columnWidth = 15;
        for (auto &&exam: exams) {
            printHorizontalLine((columnWidth) * 6);
            std::cout << "| " << std::setw(columnWidth / 2) << "ID" << std::setw(columnWidth / 2) << " | " << std::setw(columnWidth / 2) << "Name" << std::setw(columnWidth / 2) << " | " << std::setw(columnWidth / 2) << "Date" << std::setw(columnWidth / 2) << " |" << std::setw(columnWidth / 2) << "Time" << std::setw(columnWidth / 3) << " |" << std::setw(columnWidth / 2) << "Score" << std::setw(columnWidth / 2) << " |" << std::setw(columnWidth / 2) << "Corrected" << std::setw(columnWidth / 2) << " |" << std::endl;
            printHorizontalLine((columnWidth) * 6);
            std::cout << "| " << std::setw(columnWidth / 2) << std::to_string(exam.examId) << std::setw(columnWidth / 2) << " | " << std::setw(columnWidth / 2) << exam.examName << std::setw(columnWidth / 2) << " | " << std::setw(columnWidth / 2) << exam.examDate << std::setw(columnWidth / 3) << " |" << std::setw(columnWidth / 2) << exam.examTime << std::setw(columnWidth / 3) << " |" << std::setw(columnWidth / 2) << std::to_string(exam.totalScore) << std::setw(columnWidth / 3) << " |" << std::setw(columnWidth / 2) << std::to_string(exam.corrected) << std::setw(columnWidth / 2) << " |" << std::endl;
            printHorizontalLine((columnWidth) * 6);
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
        std::cout << "Please Enter Choose Of The Groups To See The Detail:" << std::endl;
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
        std::cout << "Please Enter Exam ID:" << std::endl;
        std::cin >> examId;
        std::cout << "Please Enter Student Group Name:" << std::endl;
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
            if (question.type == type::Descriptive) {
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
                if (question.type == type::MultipleChoice) {
                    question.saveToFile("data/multipleChoiceQuestion.csv");
                } else {
                    question.saveToFile("data/descriptiveQuestion.csv");
                }
            } else if (command == 3) {
                if (question.type == type::Descriptive) {
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
