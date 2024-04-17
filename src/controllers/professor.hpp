//
// Created by erfan on 4/14/2024.
//

#include "../models/exam.h"
#include "../models/studentGroup.h"

class Manager {
public:
    static void createStudentGroup(std::string &name) {
        StudentGroup studentGroup(name);
        studentGroup.saveToFile("data/studentGroups.csv");
    }
    static void createExam(int examId, std::string examName, std::string examDate, std::string examTime, double totalScore) {
        Exam exam(examId, examName, examDate, examTime, totalScore);
        exam.saveToFile("data/exam.csv");
    }
    static void CreateQuestion(int time, std::string prompt, std::string description, double score, type type) {
     	Question question( time, sprompt, description, score, type);
     	question.saveToFile("data/question.csv");
	 }
	static void createMultipleChoiceQuestion(std::string options[4], std::string correctAnswer) {
		MultipleChoiceQuestion multipleChoiceQuestion(options[4], correctAnswer);
		multipleChoiceQuestion.saveToFile("data/multipleChoiceQuestion.csv");
	}
	static void createDescriptiveQuestion(std::string answer) {
		DescriptiveQuestion descriptiveQuestion( answer);
		descriptiveQuestion.saveToFile("data/descriptiveQuestion.csv");
	}
};
