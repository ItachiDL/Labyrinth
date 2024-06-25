#include "createmaze.h"
#include <random>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

CreateMaze::CreateMaze() {
    // Default constructor
    rows = 10;
    cols = 10;
    maze = vector<vector<char>>(rows, vector<char>(cols, wall));
    run();
}

CreateMaze::CreateMaze(int rows, int cols)  {
    // Parameterized constructor
    this->rows = rows;
    this->cols = cols;
    maze = vector<vector<char>>(rows, vector<char>(cols, wall));
    run();
}

CreateMaze::~CreateMaze() {
    // Destructor
}

bool CreateMaze::isValid(const string &direction,  Point &current_point) {
    int x = current_point.getX();
    int y = current_point.getY();

    if (direction == "up" && x-1 > 0) {
        return (maze[x - 1][y] == wall && maze[x - 1][y - 1] == wall && maze[x - 1][y + 1] == wall);
    }
    if (direction == "down" && x+1 < rows - 1) {
        return (maze[x + 1][y] == wall && maze[x + 1][y - 1] == wall && maze[x + 1][y + 1] == wall);
    }
    if (direction == "left" && y-1 > 0) {
        return (maze[x][y - 1] == wall && maze[x - 1][y - 1] == wall && maze[x + 1][y - 1] == wall);
    }
    if (direction == "right" && y+1 < cols - 1) {
        return (maze[x][y + 1] == wall && maze[x - 1][y + 1] == wall && maze[x + 1][y + 1] == wall);
    }
    return false;
}

void CreateMaze::set_Point(Point &set_point) {
    path_points.push_back(set_point);
    maze[set_point.getX()][set_point.getY()] = path;
}

void CreateMaze::move(const string &direction, Point &current_point) {
    int x = current_point.getX();
    int y = current_point.getY();

    if (direction == "up") {
        current_point.setX(x - 1);
    } else if (direction == "down") {
        current_point.setX(x + 1);
    } else if (direction == "left") {
        current_point.setY(y - 1);
    } else if (direction == "right") {
        current_point.setY(y + 1);
    }
    set_Point(current_point);
}

bool CreateMaze::create(const string &direction, Point &current_point) {
    if (isValid(direction, current_point)) {
        move(direction, current_point);
        return true;
    }
    return false;
}

void CreateMaze::printMaze() {
    cout << "Maze:" << endl;
    for (const auto &row : maze) {
        for (const auto &cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void CreateMaze::transition(Point startPoint) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 3);

    random_device brunch;
    mt19937 gen1(brunch());
    uniform_int_distribution<> prob(0, 100);

    vector<string> directions = {"up", "down", "right", "left"};
    Point currentPoint = startPoint;
    set_Point(currentPoint);

    bool maze_finished = false;
    while (!maze_finished) {
        string random_direction = directions[dis(gen)];
        if (!create(random_direction, currentPoint)) {
            maze_finished = true;
            for (const auto &direction : directions) {
                if (create(direction, currentPoint)) {
                    maze_finished = false;
                    break;
                }
            }
        }
        if (prob(gen1) < 30) {
            transition(currentPoint);
        }
    }
}

void CreateMaze::run() {
    srand(static_cast<unsigned>(time(0)));
    int x = 1 + rand() % (rows - 2);
    int y = 1 + rand() % (cols - 2);
    Point startPoint(x, y);
    transition(startPoint);
    setStartEndPoints();
    //printMaze();
    saveMaze("maze.txt");
}

void CreateMaze::saveMaze(const string &filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto &row : maze) {
            for (const auto &cell : row) {
                file << cell;
            }
            file << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

void CreateMaze::setStartEndPoints() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, path_points.size() - 1);
    Point start, end;
    do{
        start = path_points[dis(gen)];
        end = path_points[dis(gen)];
    } while (start == end);
    maze[start.getX()][start.getY()] = start_char;
    maze[end.getX()][end.getY()] = end_char;
}
