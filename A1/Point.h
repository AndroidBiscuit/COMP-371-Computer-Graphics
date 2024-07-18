// COMP 371 - Summer 2024
// Assignment 1
// Faizan Ahmad (40100581)

#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x, y, z;

public:
    // Constructors for the pointer class
    Point();
    Point(int x, int y, int z);

    // Destructor
    // This class does not manage any memory or pointers, so it doesn't need one

    // Getters
    int getX();
    int getY();
    int getZ();

    // Setters
    void setX(int x);
    void setY(int y);
    void setZ(int z);

    // Other functions
    int translate(int d, char axis);
    double distanceFromPoint(Point& nextPoint);
    void pointInfo();
};

#endif // POINT_H