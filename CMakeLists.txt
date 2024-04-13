cmake_minimum_required(VERSION 3.27)
project(google_form)

set(CMAKE_CXX_STANDARD 11)

add_executable(google_form main.cpp
        src/models/user.cpp
        src/models/user.h
        src/models/student.cpp
        src/models/student.h
        src/models/professor.cpp
        src/models/professor.h
        src/models/question.h
        src/models/multipleChoiceQuestion.h
        src/models/descriptiveQuestion.h
        src/models/exam.h
        src/models/studentGroup.h
        src/views/login.hpp
        src/controllers/user.hpp
        src/views/professorDashboard.hpp
        src/models/MultipleChoiceQuestion.cpp
        src/models/exam.cpp
)
