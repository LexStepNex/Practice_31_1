cmake_minimum_required(VERSION 3.28)
project(Practice_31_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Practice_31_1 main.cpp
        include/toy.h
        include/dog.h
        include/user_input.h
        include/functions_in_logic.h)

target_include_directories(Practice_31_1 PUBLIC include)