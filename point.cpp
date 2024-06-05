#include "point.hpp"

#include <functional>
#include <unordered_map>
#include <stack>

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}  

Point::~Point() {
    // Destructor
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

bool Point::operator!=(const Point& other) const{
    return (x != other.getX() || y != other.getY());
}

bool Point::operator==(const Point& other) const{
    return (x == other.getX() && y == other.getY());
}

bool Point::operator<(const Point& other) const{
    return (x < other.getX() || (x == other.getX() && y < other.getY()));
}

bool Point::operator>(const Point& other) const{
    return (x > other.getX() || (x == other.getX() && y > other.getY()));
}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

