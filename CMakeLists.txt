cmake_minimum_required(VERSION 3.27)
project(CA2_Marketa_Bila)

set(CMAKE_CXX_STANDARD 17)

add_executable(CA2_Marketa_Bila main.cpp
        Bug.cpp
        Bug.h
        Crawler.cpp
        Crawler.h
        Hopper.cpp
        Hopper.h
        Board.cpp
        Board.h
        Flyer.cpp
        Flyer.h
        SuperBug.cpp
        SuperBug.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(CA2_Marketa_Bila sfml-system sfml-window sfml-graphics sfml-audio)