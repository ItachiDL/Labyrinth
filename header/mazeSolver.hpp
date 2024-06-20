#ifndef MAZE_SOLVER_HPP
#define MAZE_SOLVER_HPP

#include "point.hpp"
#include <vector>
#include <string>

using namespace std;

class MazeSolver {
public:
    // Constructors
    MazeSolver();
    MazeSolver(string filename);

    // Destructor
    ~MazeSolver();

    // Public methods
    void run();
    void printMaze();
    void readMaze(const string &filename);
    vector<Point> dfs();
    void remove_whitespace();
    void searchedPath();

private:	
    // Private methods
    void searchSandE();
    vector<Point> get_neighbors(Point position);
    


    // Private members
    vector<vector<char>> maze;
    int rows;
    int cols;
    vector<Point> solution_points;
    char wall = 'W';
    char path = 'X';
    char start_char = 'S';
    char end_char = 'E';
    char solutin_char = 'O';
    Point start;
    Point end;
};

#endif // MAZE_SOLVER_HPP