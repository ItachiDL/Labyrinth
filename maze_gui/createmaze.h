#ifndef CREATEMAZE_H
#define CREATEMAZE_H

#include "point.h"
#include <vector>
#include <string>

using namespace std;

class CreateMaze {
public:
    // Constructors
    CreateMaze();
    CreateMaze(int rows, int cols);

    // Destructor
    ~CreateMaze();

    // Public methods
    void run();
    void printMaze();
    void transition(Point startPoint);
    void saveMaze(const string &filename);

private:
    // Private methods
    bool isValid(const string &direction, Point &current_point);
    void move(const string &direction, Point &current_point);
    void set_Point(Point &set_point);
    bool create(const string &direction, Point &current_point);
    void setStartEndPoints();

    // Private members
    vector<vector<char>> maze;
    int rows;
    int cols;
    vector<Point> path_points;
    char wall = 'W';
    char path = 'X';
    char start_char = 'S';
    char end_char = 'E';
};

#endif // CREATEMAZE_H
