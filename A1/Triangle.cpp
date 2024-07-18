#include "Triangle.h"
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

using namespace std;

// Default constructor
Triangle:: Triangle(Point* v1, Point* v2, Point* v3): vertex_1(nullptr), vertex_2(nullptr), vertex_3(nullptr) {}

// Constructor
Triangle:: Triangle(Point* v1, Point* v2, Point* v3): vertex_1(v1), vertex_2(v2), vertex_3(v3) {}

// Getters
Point* Triangle::getV1() {
    return vertex_1;
}

Point* Triangle::getV2() {
    return vertex_2;
}

Point* Triangle::getV3() {
    return vertex_3;
}

// Setters
void Triangle::setV1(Point* v1) {
    vertex_1 = v1;
}

void Triangle::setV2(Point* v2) {
    vertex_2 = v2;
}

void Triangle::setV3(Point* v3) {
    vertex_3 = v3;
}

// Other functions
void Triangle::translate(int d, char axis) {
    vertex_1->translate(d, axis);
    vertex_2->translate(d, axis);
    vertex_3->translate(d, axis);
}

double Triangle::findArea() {
    // Sides are based on Heron's formula
    double sideA = vertex_1->distanceFromPoint(*vertex_2);
    double sideB = vertex_2->distanceFromPoint(*vertex_3);
    double sideC = vertex_3->distanceFromPoint(*vertex_1);
    double halfPerimiter = sideA + sideB + sideC;
    return sqrt(halfPerimiter * (halfPerimiter - sideA) * (halfPerimiter - sideB) * (halfPerimiter - sideC));
}

void Triangle::showCoordinates() {
    cout << "Current coordinates: " << endl;
    cout << " - Point A: " << vertex_1->getX() << ", " << vertex_1->getX() << ", " << vertex_1->getX() << endl;
    cout << " - Point B: " << vertex_2->getY() << ", " << vertex_2->getY() << ", " << vertex_2->getY() << endl;
    cout << " - Point C: " << vertex_3->getZ() << ", " << vertex_3->getZ() << ", " << vertex_3->getZ() << endl;
}
