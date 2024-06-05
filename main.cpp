#include "create_maze.hpp"
#include "mazeSolver.hpp"

int main() {
    CreateMaze maze(20,20);
    MazeSolver mazeSolver("maze.txt");
    return 0;   
}