#include "../models/objection.h"
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

    static void professorMenu(const std::string &username) {
        std::cout << "***************************************************"
                  << std::endl;
        std::cout << "**  Professor Dashboard! Welcome, " << username
                  << "!         **" << std::endl;
        std::cout << "**  1. Create New Exam                           **"
                  << std::endl;
        std::cout << "**  2. View Exam History                         **"
                  << std::endl;
        std::cout << "**  3. Create New Question                       **"
                  << std::endl;
        std::cout << "**  4. Create Student Group                      **"
                  << std::endl;
        std::cout << "**  5. View Student Groups                       **"
                  << std::endl;
        std::cout << "**  6. Add Student To Groups                     **"
                  << std::endl;
        std::cout << "**  7. Exam To Be Correct                        **"
                  << std::endl;
        std::cout << "**  8. Add Student Group To Exam                 **"
                  << std::endl;
        std::cout << "**  9. Change Share Exam Status                  **"
                  << std::endl;
        std::cout << "**  10. View Objection And Answer                **"
                  << std::endl;
        std::cout << "**  11. Student Ranking                          **"
                  << std::endl;
        std::cout << "**  0. Exit                                      **"
                  << std::endl;
        std::cout << "***************************************************"
                  << std::endl;
        std::cout << "Choose an option:";
    }

    static void createMultipleChoiceQuestion(std::vector<std::string> &options,
                                             std::string &correctAnswer) {
        std::string choice1, choice2, choice3, choice4;
        std::cout << "Please Enter Options 1:" << std::endl;
        std::cin.ignore();
        getline(std::cin, choice1);
        options.push_back(choice1);

        std::cout << "Please Enter Options 2:" << std::endl;
        getline(std::cin, choice2);
        options.push_back(choice2);

        std::cout << "Please Enter Options 3:" << std::endl;
        getline(std::cin, choice3);
        options.push_back(choice3);

        std::cout << "Please Enter Options 4:" << std::endl;
        getline(std::cin, choice4);
        options.push_back(choice4);

        std::cout << "Please Enter Correct Answer:" << std::endl;
        getline(std::cin, correctAnswer);
    }

    static void createExam(int &examId, std::string &examName,
                           std::string &examDate) {
        std::cout << "Please Enter Exam ID:" << std::endl;
        std::cin >> examId;

        std::cout << "Please Enter Exam Name:" << std::endl;
        std::cin.ignore();
        getline(std::cin, examName);

        std::cout << "Please Enter Exam Date (something like 1403/02/16):"
                  << std::endl;
        getline(std::cin, examDate);
    }

    static void createStudentGroup(std::string &name) {
        std::cout << "Please Enter Name:" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, name);
    }

    static void CreateQuestion(enum type &type, std::string &questionID,
                               int &examId, std::string &prompt, int &time,
                               double &score) {
        std::cout << "Please Enter Type (Descriptive || MultipleChoice):"
                  << std::endl;
        std::string stype;
        std::cin >> stype;
        type = Question::stringToType(stype);
        std::cout << "Please Enter Question ID:" << std::endl;
        std::cin.ignore();
        getline(std::cin, questionID);
        std::cout << "Please Enter Exam Id To Want To Add The Question To:"
                  << std::endl;
        std::cin >> examId;
        std::cout << "Please Enter Prompt:" << std::endl;
        std::cin.ignore();
        getline(std::cin, prompt);
        std::cout << "Please Enter Time In Seconds:" << std::endl;
        std::cin >> time;
        std::cout << "Please Enter Score:" << std::endl;
        std::cin >> score;
    }

    static void addToStudentGroup(std::string &name,
                                  std::vector<std::string> &usernames) {
        int count;
        std::cout << "Please enter the group name:" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Please enter the student count:" << std::endl;
        std::cin >> count;
        std::cout << "Please enter the students username (seperated by space):"
                  << std::endl;
        for (int i = 0; i < count; ++i) {
            std::string username;
            std::cin >> username;
            usernames.push_back(username);
        }
    }

    static void printHorizontalLine(int width) {
        for (int i = 0; i < width; ++i) std::cout << "-";
        std::cout << std::endl;
    }

    static void examHistory(const std::vector<Exam> &exams) {
        const int columnWidth = 15;
        for (auto &&exam: exams) {
            printHorizontalLine((columnWidth) * 6);
            std::cout << "| " << std::setw(columnWidth / 2) << "ID"
                      << std::setw(columnWidth / 2) << " | "
                      << std::setw(columnWidth / 2) << "Name"
                      << std::setw(columnWidth / 2) << " | "
                      << std::setw(columnWidth / 2) << "Date"
                      << std::setw(columnWidth / 2) << " |"
                      << std::setw(columnWidth / 2) << "Time"
                      << std::setw(columnWidth / 3) << " |"
                      << std::setw(columnWidth / 2) << "Score"
                      << std::setw(columnWidth / 2) << " |"
                      << std::setw(columnWidth / 2) << "Corrected"
                      << std::setw(columnWidth / 2) << " |" << std::endl;
            printHorizontalLine((columnWidth) * 6);
            std::cout << "| " << std::setw(columnWidth / 2)
                      << std::to_string(exam.examId)
                      << std::setw(columnWidth / 2) << " | "
                      << std::setw(columnWidth / 2) << exam.examName
                      << std::setw(columnWidth / 2) << " | "
                      << std::setw(columnWidth / 2) << exam.examDate
                      << std::setw(columnWidth / 3) << " |"
                      << std::setw(columnWidth / 2) << exam.examTime
                      << std::setw(columnWidth / 3) << " |"
                      << std::setw(columnWidth / 2)
                      << std::to_string(exam.totalScore)
                      << std::setw(columnWidth / 3) << " |"
                      << std::setw(columnWidth / 2)
                      << std::to_string(exam.corrected)
                      << std::setw(columnWidth / 2) << " |" << std::endl;
            printHorizontalLine((columnWidth) * 6);
            for (auto &studentScore: exam.studentScores) {
                printHorizontalLine((columnWidth + 1) * 2);
                std::cout << "| " << std::setw(columnWidth / 2) << "Student ID"
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << "Score"
                          << std::setw(columnWidth / 2) << " | " << std::endl;
                printHorizontalLine((columnWidth + 1) * 2);
                std::cout << "| " << std::setw(columnWidth / 2)
                          << studentScore.first << std::setw(columnWidth / 2)
                          << " | " << std::setw(columnWidth / 2)
                          << studentScore.second << std::setw(columnWidth / 2)
                          << " | " << std::endl;
                printHorizontalLine((columnWidth + 1) * 2);
            }
        }
    }

    static void
    studentGroupHistory(const std::vector<StudentGroup> &studentGroups) {
        int studentGroupId;
        std::cout << "Please Enter Choose Of The Groups To See The Detail:"
                  << std::endl;
        for (int i = 0; i < studentGroups.size(); ++i) {
            std::cout << i << ". " << studentGroups.at(i).name << std::endl;
        }
        std::cin >> studentGroupId;
        const int columnWidth = 20;
        printHorizontalLine((columnWidth) * 3);
        std::cout << "| " << std::setw(columnWidth) << "Student Username"
                  << std::setw(columnWidth / 2) << " | "
                  << std::setw(columnWidth / 2) << "Student Fullname"
                  << std::setw(columnWidth / 2) << " | " << std::endl;
        printHorizontalLine((columnWidth) * 3);
        for (const auto &student: studentGroups.at(studentGroupId).students) {
            std::cout << "| " << std::setw(columnWidth / 2) << student.username
                      << std::setw(columnWidth / 2) << " | "
                      << std::setw(columnWidth / 2) << student.fullname
                      << std::setw(columnWidth / 2) << " | " << std::endl;
        }
        printHorizontalLine((columnWidth) * 3);
    }

    static void addStudentGroupToExam(int &examId,
                                      std::string &studentGroupName) {
        std::cout << "Please Enter Exam ID:" << std::endl;
        std::cin >> examId;
        std::cin.ignore();
        std::cout << "Please Enter Student Group Name:" << std::endl;
        getline(std::cin, studentGroupName);
    }

    static void examToBeCorrect(std::vector<Exam> &examsToBeCorrect,
                                const std::string &username) {
        if (!examsToBeCorrect.empty()) {
            int examID;
            std::cout << "Please choose of the exams to start review "
                         "and correct process"
                      << std::endl;
            for (int i = 0; i < examsToBeCorrect.size(); ++i) {
                std::cout << i << ". " << examsToBeCorrect.at(i).examName
                          << std::endl;
            }
            std::cin >> examID;
            int studentID;
            std::cout << "Please choose of the student to start review "
                         "and correct process"
                      << std::endl;
            for (int i = 0;
                 i < examsToBeCorrect.at(examID).studentScores.size(); ++i) {
                std::cout << i << "."
                          << Student::findByUsername(
                                     "data/credentials.csv",
                                     examsToBeCorrect.at(examID)
                                             .studentScores.at(i)
                                             .first)
                                     .fullname
                          << "("
                          << examsToBeCorrect.at(examID)
                                     .studentScores.at(i)
                                     .first
                          << ")" << std::endl;
            }
            std::cin >> studentID;
            const int columnWidth = 20;
            for (auto &question: examsToBeCorrect.at(examID).questions) {
                printHorizontalLine((columnWidth + 1) * 2);
                std::cout << "| " << std::setw(columnWidth / 2) << "Prompt"
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << question->prompt
                          << std::setw(columnWidth / 2) << " | " << std::endl;
                printHorizontalLine((columnWidth + 1) * 2);
                std::cout << "| " << std::setw(columnWidth / 2) << "Answer"
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2);
                for (const auto &answer: question->answer) {
                    if (answer.first == examsToBeCorrect.at(examID)
                                                .studentScores.at(studentID)
                                                .first) {
                        std::cout << answer.second;
                    }
                }
                std::cout << std::setw(columnWidth / 2) << " | " << std::endl;
                printHorizontalLine((columnWidth + 1) * 2);
            menu:
                int command;

                std::cout << "1. Next Question!" << std::endl;
                std::cout << "2. Comment It!" << std::endl;
                if (question->type == type::Descriptive) {
                    std::cout << "3. Score It!" << std::endl;
                }
                std::cin >> command;
                if (command == 1) {
                    continue;
                } else if (command == 2) {
                    std::string comment;
                    std::cout << "Please leave your comment for this question:"
                              << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, comment);
                    question->changeDescription(comment);
                    if (question->type == type::MultipleChoice) {
                        question->saveToFile(
                                "data/multipleChoiceQuestion.csv");
                        goto menu;
                    } else {
                        question->saveToFile("data/descriptiveQuestion.csv");
                        goto menu;
                    }
                } else if (command == 3) {
                    if (question->type == type::Descriptive) {
                        double score;
                        std::cout << "Please enter the student score "
                                     "according to answer from 0 to "
                                  << question->score.second << ":"
                                  << std::endl;
                        std::cin >> score;
                        question->score.first = score;
                        question->saveToFile("data/descriptiveQuestion.csv");
                        for (auto &scores:
                             examsToBeCorrect.at(examID).studentScores) {
                            if (username == scores.first) {
                                scores.second += question->score.first;
                                break;
                            }
                        }
                        examsToBeCorrect.at(examID).saveToFile(
                                "data/exam.csv");
                        goto menu;
                    }
                } else {
                    std::cout << "Invalid Command!" << std::endl;
                }
            }
            examsToBeCorrect.at(examID).corrected = true;
            examsToBeCorrect.at(examID).saveToFile("data/exam.csv");
        } else {
            std::cout << "There is no exam to correct" << std::endl;
        }
    }

    static void changeSharingExam(std::vector<Exam> &exams) {
        if (!exams.empty()) {
            int examID;
            std::cout << "Please choose of the exams to change sharing status"
                      << std::endl;
            const int columnWidth = 15;
            for (auto &&exam: exams) {
                printHorizontalLine((columnWidth) * 6);
                std::cout << "| " << std::setw(columnWidth / 2) << "ID"
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << "Name"
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << "Date"
                          << std::setw(columnWidth / 2) << " |"
                          << std::setw(columnWidth / 2) << "Time"
                          << std::setw(columnWidth / 3) << " |"
                          << std::setw(columnWidth / 2) << "Score"
                          << std::setw(columnWidth / 2) << " |"
                          << std::setw(columnWidth / 2) << "TakeAble"
                          << std::setw(columnWidth / 2) << " |" << std::endl;
                printHorizontalLine((columnWidth) * 6);
                std::cout << "| " << std::setw(columnWidth / 2)
                          << std::to_string(exam.examId)
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << exam.examName
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << exam.examDate
                          << std::setw(columnWidth / 3) << " |"
                          << std::setw(columnWidth / 2) << exam.examTime
                          << std::setw(columnWidth / 3) << " |"
                          << std::setw(columnWidth / 2)
                          << std::to_string(exam.totalScore)
                          << std::setw(columnWidth / 3) << " |"
                          << std::setw(columnWidth / 2)
                          << std::to_string(exam.takeable)
                          << std::setw(columnWidth / 2) << " |" << std::endl;
                printHorizontalLine((columnWidth) * 6);
            }
            std::cin >> examID;
            for (auto &&exam: exams) {
                if (exam.examId == examID) {
                    exam.takeable = !exam.takeable;
                    exam.saveToFile("data/exam.csv");
                }
            }
        } else {
            std::cout << "There is no exam to change sharing status"
                      << std::endl;
        }
    }

    static void reviewObjections(std::vector<Objection> &objections) {
        if (!objections.empty()) {
            int objectionId;
            std::cout << "Please choose of the objection to answer it"
                      << std::endl;
            const int columnWidth = 15;
            int id = 0;
            for (auto &&objection: objections) {
                std::cout << "| " << std::setw(columnWidth / 2)
                          << "objection: " << objection.text << std::endl;
                printHorizontalLine((columnWidth) * 4);
                std::cout << "| " << std::setw(columnWidth / 2) << "ID"
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << "Student ID"
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << "Exam ID"
                          << std::setw(columnWidth / 2) << " |"
                          << std::setw(columnWidth / 2) << "Created At"
                          << std::setw(columnWidth / 2) << " |" << std::endl;
                printHorizontalLine((columnWidth) * 4);
                std::cout << "| " << std::setw(columnWidth / 2)
                          << std::to_string(id) << std::setw(columnWidth / 2)
                          << " | " << std::setw(columnWidth / 2)
                          << objection.studentId << std::setw(columnWidth / 2)
                          << " | " << std::setw(columnWidth / 2)
                          << objection.examId << std::setw(columnWidth / 3)
                          << " |" << std::setw(columnWidth / 2)
                          << objection.getFormattedTimestamp()
                          << std::setw(columnWidth / 2) << " |" << std::endl;
                printHorizontalLine((columnWidth) * 4);
                id++;
            }
            std::cin >> objectionId;
            std::cout << "Please enter your answer to this objection:"
                      << std::endl;
            std::string answer;
            std::cin.ignore();
            std::getline(std::cin, answer);
            objections.at(objectionId).answer = answer;
            objections.at(objectionId).saveToFile("data/objections.csv");
        } else {
            std::cout << "There is no objection to review" << std::endl;
        }
    }

    static void examSelection(const std::vector<Exam> &exams,
                              std::string &answer) {
        if (!exams.empty()) {
            const int columnWidth = 15;
            for (auto &&exam: exams) {
                printHorizontalLine((columnWidth) * 5);
                std::cout << "| " << std::setw(columnWidth / 2) << "ID"
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << "Name"
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << "Date"
                          << std::setw(columnWidth / 2) << " |"
                          << std::setw(columnWidth / 2) << "Time"
                          << std::setw(columnWidth / 3) << " |"
                          << std::setw(columnWidth / 2) << "Score"
                          << std::setw(columnWidth / 2) << " |" << std::endl;
                printHorizontalLine((columnWidth) * 5);
                std::cout << "| " << std::setw(columnWidth / 2)
                          << std::to_string(exam.examId)
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << exam.examName
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << exam.examDate
                          << std::setw(columnWidth / 3) << " |"
                          << std::setw(columnWidth / 2) << exam.examTime
                          << std::setw(columnWidth / 3) << " |"
                          << std::setw(columnWidth / 2)
                          << std::to_string(exam.totalScore)
                          << std::setw(columnWidth / 2) << " |" << std::endl;
                printHorizontalLine((columnWidth) * 5);
            }
            std::cout << "Please select exams you wanna rank:" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, answer);
        } else {
            std::cout << "There is no exam to rank" << std::endl;
        }
    }

    static void
    studentRanking(const std::vector<StudentRanking> &studentRankings) {
        if (!studentRankings.empty()) {
            const int columnWidth = 15;
            printHorizontalLine((columnWidth) * 3);
            std::cout << "| " << std::setw(columnWidth / 2) << "Rank"
                      << std::setw(columnWidth / 2) << " | "
                      << std::setw(columnWidth / 2) << "Student ID"
                      << std::setw(columnWidth / 2) << " | "
                      << std::setw(columnWidth / 2) << "Average Score"
                      << std::setw(columnWidth / 2) << " |" << std::endl;
            printHorizontalLine((columnWidth) * 3);
            for (auto &&studentRanking: studentRankings) {
                std::cout << "| " << std::setw(columnWidth / 2)
                          << std::to_string(studentRanking.rank)
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << studentRanking.name
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2)
                          << studentRanking.average_score
                          << std::setw(columnWidth / 2) << " |" << std::endl;
                printHorizontalLine((columnWidth) * 3);
            }
        } else {
            std::cout << "There is no exam to rank" << std::endl;
        }
    }

    static void studentMenu(const std::string &username) {
        std::cout << "***************************************************"
                  << std::endl;
        std::cout << "**  Student Dashboard! Welcome, " << username
                  << "!            **" << std::endl;
        std::cout << "**  1. Take A Test                               **"
                  << std::endl;
        std::cout << "**  2. View Exam History                         **"
                  << std::endl;
        std::cout << "**  3. View Objections                           **"
                  << std::endl;
        std::cout << "**  0. Exit                                      **"
                  << std::endl;
        std::cout << "***************************************************"
                  << std::endl;
        std::cout << "Choose an option:";
    }

    static void studentExamTaking(std::vector<Exam> &examsToBeTake,
                                  const std::string &username) {
        if (!examsToBeTake.empty()) {
            int examId;
            const int columnWidth = 15;
            for (auto &&exam: examsToBeTake) {
                printHorizontalLine((columnWidth) * 6);
                std::cout << "| " << std::setw(columnWidth / 2) << "ID"
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << "Name"
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << "Date"
                          << std::setw(columnWidth / 2) << " |"
                          << std::setw(columnWidth / 2) << "Time"
                          << std::setw(columnWidth / 3) << " |"
                          << std::setw(columnWidth / 2) << "Score"
                          << std::setw(columnWidth / 2) << " |"
                          << std::setw(columnWidth / 2) << "Question Count"
                          << std::setw(columnWidth / 2) << " |" << std::endl;
                printHorizontalLine((columnWidth) * 6);
                std::cout << "| " << std::setw(columnWidth / 2)
                          << std::to_string(exam.examId)
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << exam.examName
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << exam.examDate
                          << std::setw(columnWidth / 3) << " |"
                          << std::setw(columnWidth / 2) << exam.examTime
                          << std::setw(columnWidth / 3) << " |"
                          << std::setw(columnWidth / 2)
                          << std::to_string(exam.totalScore)
                          << std::setw(columnWidth / 3) << " |"
                          << std::setw(columnWidth / 2)
                          << std::to_string(exam.questions.size())
                          << std::setw(columnWidth / 2) << " |" << std::endl;
                printHorizontalLine((columnWidth) * 6);
            }
            std::cout << "Please Choose Of The Exams To Take It:" << std::endl;
            std::cin >> examId;
            int remainingQuestion;
            for (auto &exam: examsToBeTake) {
                if (exam.examId == examId) {
                    remainingQuestion = exam.questions.size();
                    for (auto &question: exam.questions) {
                        printHorizontalLine((columnWidth + 1) * 2);

                        std::cout << "| " << std::setw(columnWidth / 2)
                                  << "Prompt: " << question->prompt
                                  << std::endl;

                        printHorizontalLine((columnWidth + 1) * 2);
                        std::cout << "| " << std::setw(columnWidth / 2)
                                  << "Score" << std::setw(columnWidth / 2)
                                  << " | " << std::setw(columnWidth / 2)
                                  << "Time" << std::setw(columnWidth / 2)
                                  << " | " << std::endl;
                        printHorizontalLine((columnWidth + 1) * 2);
                        std::cout << "| " << std::setw(columnWidth / 2)
                                  << question->score.second
                                  << std::setw(columnWidth / 2) << " | "
                                  << std::setw(columnWidth / 2)
                                  << question->time
                                  << std::setw(columnWidth / 2) << " | "
                                  << std::endl;
                        printHorizontalLine((columnWidth + 1) * 2);
                    menu:
                        int command;
                        if (remainingQuestion > 1) {
                            std::cout << "1. Next Question!" << std::endl;
                        } else {
                            std::cout << "1. End Exam!" << std::endl;
                        }
                        std::cout << "2. Answer It!" << std::endl;
                        std::cin >> command;
                        if (command == 1) {
                            remainingQuestion--;
                            continue;
                        } else if (command == 2) {
                            if (question->type == type::Descriptive) {
                                std::string answer;
                                std::cout << "Please leave your answer "
                                             "for this "
                                             "question:"
                                          << std::endl;
                                std::cin.ignore();
                                std::getline(std::cin, answer);
                                question->answer.emplace_back(username,
                                                              answer);
                            } else {
                                if (auto mcq = dynamic_cast<
                                            MultipleChoiceQuestion *>(
                                            question.get())) {
                                    printHorizontalLine((columnWidth) * 4);
                                    std::cout << "| "
                                              << std::setw(columnWidth / 2)
                                              << "Option 1"
                                              << std::setw(columnWidth / 2)
                                              << " | "
                                              << std::setw(columnWidth / 2)
                                              << "Option 2"
                                              << std::setw(columnWidth / 2)
                                              << " | "
                                              << std::setw(columnWidth / 2)
                                              << "Option 3"
                                              << std::setw(columnWidth / 2)
                                              << " |"
                                              << std::setw(columnWidth / 2)
                                              << "Option 4"
                                              << std::setw(columnWidth / 3)
                                              << std::setw(columnWidth / 2)
                                              << " |" << std::endl;
                                    printHorizontalLine((columnWidth) * 4);
                                    std::cout << "| "
                                              << std::setw(columnWidth / 2);
                                    for (int i = 0; i < 4; ++i) {
                                        std::cout << mcq->options.at(i)
                                                  << std::setw(columnWidth / 2)
                                                  << " |";
                                    }
                                    std::cout << std::endl;
                                    printHorizontalLine((columnWidth) * 4);
                                    std::string answer;
                                    std::cout << "Please select a answer "
                                                 "for "
                                                 "this "
                                                 "question:"
                                              << std::endl;
                                    std::cin.ignore();
                                    std::getline(std::cin, answer);
                                    question->answer.emplace_back(username,
                                                                  answer);
                                    if (mcq->autoCorrector(answer)) {
                                        question->score.first =
                                                question->score.second;
                                    } else {
                                        question->score.first = 0;
                                    }
                                    for (auto &scores: exam.studentScores) {
                                        if (username == scores.first) {
                                            scores.second +=
                                                    question->score.first;
                                            break;
                                        }
                                    }
                                    exam.saveToFile("data/exam.csv");
                                }
                            }
                            if (question->type == type::MultipleChoice) {
                                question->saveToFile(
                                        "data/multipleChoiceQuestion.csv");
                                goto menu;
                            } else {
                                question->saveToFile(
                                        "data/descriptiveQuestion.csv");
                                goto menu;
                            }
                        } else {
                            std::cout << "Invalid Command!" << std::endl;
                        }
                    }
                    std::cout << "If you have any objection on the exam enter "
                                 "(1) otherwise enter (0)"
                              << std::endl;
                    int cmd;
                    std::cin >> cmd;
                    if (cmd == 1) {
                        std::string text;
                        std::cout << "Please enter your objection:";
                        std::cin.ignore();
                        std::getline(std::cin, text);
                        Objection objection(text, username,
                                            std::to_string(examId));
                        objection.saveToFile("data/objections.csv");
                    }
                }
            }
        } else {
            std::cout << "There is no exam to take" << std::endl;
        }
    }

    static void studentExamHistory(const std::vector<Exam> &exams,
                                   const std::string &username) {
        if (!exams.empty()) {
            const int columnWidth = 14;
            for (auto &&exam: exams) {
                printHorizontalLine((columnWidth) * 7);
                std::cout << "| " << std::setw(columnWidth / 2) << "ID"
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << "Name"
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << "Date"
                          << std::setw(columnWidth / 2) << " |"
                          << std::setw(columnWidth / 2) << "Time"
                          << std::setw(columnWidth / 3) << " |"
                          << std::setw(columnWidth / 2) << "Total Score"
                          << std::setw(columnWidth / 4) << " |"
                          << std::setw(columnWidth / 2) << "Corrected"
                          << std::setw(columnWidth / 4) << " |"
                          << std::setw(columnWidth / 2) << "Took Score"
                          << std::setw(columnWidth / 2) << " |" << std::endl;
                printHorizontalLine((columnWidth) * 7);
                std::cout << "| " << std::setw(columnWidth / 2)
                          << std::to_string(exam.examId)
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << exam.examName
                          << std::setw(columnWidth / 2) << " | "
                          << std::setw(columnWidth / 2) << exam.examDate
                          << std::setw(columnWidth / 3) << " |"
                          << std::setw(columnWidth / 2) << exam.examTime
                          << std::setw(columnWidth / 3) << " |"
                          << std::setw(columnWidth / 2)
                          << std::to_string(exam.totalScore)
                          << std::setw(columnWidth / 3) << " |"
                          << std::setw(columnWidth / 2)
                          << std::to_string(exam.corrected)
                          << std::setw(columnWidth / 3) << " |"
                          << std::setw(columnWidth / 2);
                for (auto &studentScore: exam.studentScores) {
                    if (studentScore.first == username) {
                        std::cout << studentScore.second;
                    }
                }
                std::cout << std::setw(columnWidth / 2) << " |" << std::endl;
                printHorizontalLine((columnWidth) * 7);
            }
        } else {
            std::cout << "There is no exam to view" << std::endl;
        }
    }

    static void viewObjections(std::vector<Objection> &objections) {
        if (!objections.empty()) {
            const int columnWidth = 15;
            for (auto &&objection: objections) {
                std::cout << "| " << std::setw(columnWidth / 2)
                          << "objection: " << objection.text << std::endl;
                printHorizontalLine((columnWidth) * 2);
                std::cout << "| " << std::setw(columnWidth / 2) << "Exam ID"
                          << std::setw(columnWidth / 2) << " |"
                          << std::setw(columnWidth / 2) << "Created At"
                          << std::setw(columnWidth / 2) << " |" << std::endl;
                printHorizontalLine((columnWidth) * 2);
                std::cout << "| " << std::setw(columnWidth / 2)
                          << objection.examId << std::setw(columnWidth / 3)
                          << " |" << std::setw(columnWidth / 2)
                          << objection.getFormattedTimestamp()
                          << std::setw(columnWidth / 2) << " |" << std::endl;
                printHorizontalLine((columnWidth) * 2);
                std::cout << "| " << std::setw(columnWidth / 2)
                          << "answer: " << objection.answer << std::endl;
            }
        } else {
            std::cout << "There is no objection to view" << std::endl;
        }
    }
};
