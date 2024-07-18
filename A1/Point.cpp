#include "Point.h"
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

using namespace std;

// Default constructor
Point::Point() : x(0), y(0), z(0) {}

// Parameterized constructor
Point::Point(int x, int y, int z): x(x), y(y), z(z) {}

// Getters
int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

int Point::getZ() {
    return z;
}

// Setters
void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

void Point::setZ(int z) {
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

// Find distance between the current point and a chosen point
double Point::distanceFromPoint(Point& nextPoint){
    return sqrt(pow(x - nextPoint.x, 2) + pow(y - nextPoint.y, 2) + pow(z - nextPoint.z, 2));
}

void Point::pointInfo() {
    cout << "Point info: " << endl;
    cout << " - X: " << x << endl;
    cout << " - Y: " << y << endl;
    cout << " - Z: " << z << endl;
}
