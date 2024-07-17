#include "Point.h"
#include <cmath>

// Default constructor
Point::Point() : x(0), y(0), z(0) {}

// Parameterized constructor
Point::Point(double x, double y, double z): x(x), y(y), z(z) {}

// Getters
double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

double Point::getZ() {
    return z;
}

// Setters
void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

void Point::setZ(double z) {
    this->z = z;
}

// Other functions
int Point::translate(int d, char axis) {
    // Check distance value
    // This is already done by specifying "int" in front of the "d" variable 
    // in this function's parameters

    // Check axis value and apply distance value
    switch (axis) {
        case 'x':
            x += d;
            return 0;
            break;
        case 'y':
            y += d;
            return 0;
            break;
        case 'z':
            z += d;
            return 0;
            break;
        default:
            return -1;
    }
}

double Point::distanceFromPoint(Point& nextPoint){
    return sqrt(pow(x - nextPoint.x, 2) + pow(y - nextPoint.y, 2) + pow(z - nextPoint.z, 2));
}
