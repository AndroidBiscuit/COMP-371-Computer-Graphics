// COMP 371 - Summer 2024
// Assignment 1
// Faizan Ahmad (40100581)

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle {
private:
    Point* vertex_1;
    Point* vertex_2;
    Point* vertex_3;

public:
    // Constructors for the pointer class
    Triangle();
    Triangle(Point* vertex_1, Point* vertex_2, Point* vertex_3);

    // Destructor
    ~Triangle();

    // Getters
    Point* getV1();
    Point* getV2();
    Point* getV3();

    // Setters
    void setV1(Point* vertex);
    void setV2(Point* vertex);
    void setV3(Point* vertex);

    // Other functions
    void translate(int d, char axis);
    double calcArea();
    void showCoordinates();
};

#endif // TRIANGLE_H