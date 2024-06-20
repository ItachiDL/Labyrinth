cmake_minimum_required(VERSION 3.25)

project(Labyrinth 
    VERSION 0.5.0
    DESCRIPTION "A simple maze generator and solver"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE src/main.cpp src/point.cpp src/create_maze.cpp src/mazeSolver.cpp)
set(NAME_EXE maze)

add_executable(${NAME_EXE} ${SOURCE})
