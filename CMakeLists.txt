cmake_minimum_required(VERSION 3.27)
project(google_form)

set(CMAKE_CXX_STANDARD 17)

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
        src/controllers/user.hpp
        src/models/multipleChoiceQuestion.cpp
        src/models/exam.cpp
        src/views/display.hpp
        src/models/studentGroup.cpp
        src/controllers/professor.hpp
        src/models/question.cpp
        src/models/descriptiveQuestion.cpp
        src/controllers/student.hpp
        src/models/objection.h
        src/models/objection.cpp
        src/models/studentRanking.h
        src/models/studentRanking.cpp
)
