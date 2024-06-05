#include "create_maze.hpp"
#include "mazeSolver.hpp"

int main() {
    CreateMaze maze(15,15);
    MazeSolver mazeSolver("maze.txt");
    return 0;   
}