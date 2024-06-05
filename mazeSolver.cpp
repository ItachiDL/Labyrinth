#include "mazeSolver.hpp"
#include "point.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

MazeSolver::MazeSolver() {
    // Default constructor
    readMaze("maze.txt");
    run();
}

MazeSolver::MazeSolver(string filename) {
    // Parameterized constructor
    readMaze(filename);
    run();
}

MazeSolver::~MazeSolver() {
    // Destructor
}

void MazeSolver::readMaze(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: file not found" << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        maze.push_back(row);
    }

    rows = maze.size();
    cols = maze[0].size();
}

void MazeSolver::printMaze() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
}

void MazeSolver::searchSandE() {
    bool find_start = false;
    bool find_end = false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == start_char) {
                start.setX(i);
                start.setY(j);
                find_start = true;
            }
            if (maze[i][j] == end_char) {
                end.setX(i);
                end.setY(j);
                find_end = true;
            }
        }
    }
    if (!find_start || !find_end) {
        cerr << "Error: start or end point not found" << endl;
        exit(1);
    }
}

vector<Point> MazeSolver::get_neighbors(Point position) {
    // Get neighbors of a given position
    vector<Point> neighbors;
    int x = position.getX();
    int y = position.getY();
    vector<Point> possible_neighbors = {Point(x - 1, y), Point(x + 1, y), Point(x, y - 1), Point(x, y + 1)};
    for (Point p : possible_neighbors) {
        if (p.getX() > 0 && p.getX() < rows-1 && p.getY() > 0 && p.getY() < cols-1 && maze[p.getX()][p.getY()] != wall) {
            neighbors.push_back(p);
        }
    }
    return neighbors;
}

vector<Point> MazeSolver::dfs() {
    // Implement depth-first search algorithm
    stack<Point> toBeVisited;
    map<Point, Point> parent;
    map<Point, bool> visited;
    vector<Point> path;

    toBeVisited.push(start);
    visited[start] = true;
    parent[start] = Point(-1, -1);

    while(!toBeVisited.empty()) {
        Point current = toBeVisited.top();
        toBeVisited.pop();
        if (current == end) {
            break;
        }
        vector<Point> neighbors = get_neighbors(current);
        for (Point neighbor : neighbors) {
            if (!visited[neighbor]) {
                toBeVisited.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = current;
            }
        }
    }

    // Backtrack to find the path
    for (Point step = end; step != Point(-1, -1); step = parent[step]) {
        path.push_back(step);
    }
    reverse(path.begin(), path.end());

    if (!path.empty() && path.front() == start) {
        return path;
    } else {
        return {};
    }

}

void MazeSolver::run() {
    searchSandE();
    cout << "Start point: (" << start.getX() << ", " << start.getY() << ")" << endl;
    cout << "End point: (" << end.getX() << ", " << end.getY() << ")" << endl;
    auto path = dfs();
}