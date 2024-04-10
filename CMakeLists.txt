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
)
