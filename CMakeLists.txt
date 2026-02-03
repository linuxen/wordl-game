cmake_minimum_required(VERSION 3.10)

project(WordlGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(WordlGame
    MyGame/main.cpp
    MyGame/Logic.cpp
    MyGame/Parser.cpp
)
