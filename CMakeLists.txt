cmake_minimum_required(VERSION 3.26)
project(CH05INFIXCONVERTFA23)

set(CMAKE_CXX_STANDARD 17)

add_executable(CH05INFIXCONVERTFA23 main.cpp
        Postfix_Evaluator.cpp
        Postfix_Evaluator.h
        Syntax_Error.h
        Infix_To_Postfix.cpp
        Infix_To_Postfix.h)
