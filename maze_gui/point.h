#ifndef POINT_H
#define POINT_H

class Point{
public:
    // Constructor
    Point(int x, int y);
    Point() = default;

    // Destructor
    ~Point();

    // Getters
    int getX();
    int getY();

    int getX() const;
    int getY() const;

    // Setters
    void setX(int x);
    void setY(int y);

    // Operator !=
    bool operator!=(const Point& other) const;
    // Operator ==
    bool operator==(const Point& other) const;

    bool operator<(const Point& other) const;

    bool operator>(const Point& other) const;
private:
    int x;
    int y;
};

#endif // POINT_H
