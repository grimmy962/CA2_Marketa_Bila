cmake_minimum_required(VERSION 3.27)
project(CA2_Marketa_Bila)

set(CMAKE_CXX_STANDARD 17)

add_executable(CA2_Marketa_Bila main.cpp
        Shape.cpp
        Shape.h
        Circle.cpp
        Circle.h
        Rectangle.cpp
        Rectangle.h
        Bug.cpp
        Bug.h
        Crawler.cpp
        Crawler.h
        Hopper.cpp
        Hopper.h
        Board.cpp
        Board.h)
