cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 14)
project(project2)

include_directories(.)

add_executable(project2
        AndOp.h
        conditional.h
        divide.h
        equalto.h
        expression.h
        greaterthan.h
        lessthan.h
        literal.h
        minus.h
        negate.h
        operand.cpp
        operand.h
        Orop.h
        parse.cpp
        parse.h
        plus.h
        project2.cpp
        subexpression.cpp
        subexpression.h
        symboltable.cpp
        symboltable.h
        times.h
        variable.cpp
        variable.h
)
