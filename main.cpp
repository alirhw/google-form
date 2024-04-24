#include "src/controllers/professor.hpp"
#include "src/controllers/user.hpp"
#include "src/views/display.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string username, password, studentGroupName;
    string examName, examDate, examTime;
    string prompt, description, questionID;
    string correctAnswer, groupNameToAdd, groupName;
    int examId, time, examIdToAddQuestion, examIdToAdd;
    double totalScore, score;
    enum type type;
    vector<string> options;
    vector<string> usernames{};
    vector<Exam> exams;
    vector<StudentGroup> studentGroups;

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
                    Display::createExam(examId, examName, examDate, examTime, totalScore);
                    Manager::createExam(examId, examName, examDate, examTime, totalScore);
                    break;
                case 2:
                    Manager::getAllExams(exams);
                    Display::examHistory(exams);
                    break;
                case 3:
                    Display::CreateQuestion(type, questionID, examIdToAddQuestion, prompt, description, time, score);
                    if (type == type::Descriptive) {
                        Manager::createDescriptiveQuestion(time, "D:" + questionID, examIdToAddQuestion, prompt, description, score, type);
                    } else if (type == type::MultipleChoice) {
                        Display::createMultipleChoiceQuestion(options, correctAnswer);
                        Manager::createMultipleChoiceQuestion(time, "M:" + questionID, examIdToAddQuestion, prompt, description, score, type, options, correctAnswer);
                    } else {
                        cout << "Wrong Question Type!" << endl;
                    }
                    break;
                case 4:
                    Display::createStudentGroup(studentGroupName);
                    Manager::createStudentGroup(studentGroupName);
                    break;
                case 5:
                    Manager::getAllStudentGroups(studentGroups);
                    Display::studentGroupHistory(studentGroups);
                    break;
                case 6:
                    Display::addToStudentGroup(groupNameToAdd, usernames);
                    Manager::addStudentToGroup(groupNameToAdd, usernames);
                    break;
                case 7:
                    Manager::getAllExamToBeCorrect(exams);
                    Display::examToBeCorrect(exams);
                    break;
                case 8:
                    Display::addStudentGroupToExam(examIdToAdd, groupName);
                    Manager::addStudentGroupToExam(examIdToAdd, groupName);
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
