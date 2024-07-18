// COMP 371 - Summer 2024
// Assignment 1
// Faizan Ahmad (40100581)

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Point.h"
#include "Triangle.h"

using namespace std;

// Dinamically allocate an array of a specified size
int* createArray(int size) {
    cout << endl << "Creating array of size " << size << "..." << endl;

    int* array = new int[size];

    cout << "Array created!" << endl;

    return array;
}

// Initialize array with values from 0 to 1
void initializeArray(int* arrayPointer, int size) {
    cout << endl << "Initializing... " << endl;
    for (int i = 0; i < size; ++i) {
        arrayPointer[i] = i;
    }
    cout << "Array initialized!" << endl;
}

// Print array
void printArray(int* arrayPointer, int size) {
    cout << endl << "Array contents: ";
    for (int i = 0; i < size; i++) {
        if(i == size - 1){
            cout << arrayPointer[i] << endl << endl;
        }
        else {
            cout << arrayPointer[i] << ", ";
        }
    }
}

// Delete array (and pointer)
void deleteArray(int* arrayPointer) {
    cout << endl << "Deleting array... " << endl;
    // Delete memory allocated to array
    delete[] arrayPointer;

    cout << "Deleting pointer... " << endl;
    // Remove pointer
    arrayPointer = nullptr;

    cout << "Deleted array and pointer!" << endl;
}

// Function for running only the first part of the assignment (driver for part one)
void partOne() {
    cout << "\n-----------      Part 1 - Array manipulation      -----------\n" << endl;

    // Get user input for array size
    int userSize;
    cout << "Select array size: ";
    cin >> userSize;

    // 1.1 - Create dynamic array
    int* array = createArray(userSize);

    // 1.2 - Initialize array
    initializeArray(array, userSize);

    // 1.3 - Print array
    printArray(array, userSize);

    // 1.4 - Delete array
    deleteArray(array);
}

void testPointClass() {
    // Get point info
    int userX, userY, userZ;
    cout << "Enter points coordinates: " << endl;
    cout << "Enter value for x: ";
    cin >> userX;
    cout << "Enter value for y: ";
    cin >> userY;
    cout << "Enter value for z: ";
    cin >> userZ;

    // Make pointer
    Point* tempPoint = new Point(userX, userY, userZ);
    cout << "New Point info: " << endl;
    tempPoint->pointInfo();

    // Move the point in all three axes
    cout << endl << "Move point on X by 3:" << endl;
    tempPoint->translate(3, 'x');
    tempPoint->pointInfo();
    cout << endl << endl;
    cout << endl << "Move point on Y by 4:" << endl;
    tempPoint->translate(4, 'y');
    tempPoint->pointInfo();
    cout << endl << endl;
    cout << endl << "Move point on Z by 5:" << endl;
    tempPoint->translate(5, 'z');
    tempPoint->pointInfo();
    cout << endl << endl;

    // Delete pointers
    delete tempPoint;
    tempPoint = nullptr;
}

// Function for running only the second part of the assignment (driver for part two)
void partTwo() {
    cout << "\n-----------   Part 2 - Point / Triangle classes   -----------\n" << endl;

    // 2.0 Point class test
    char pointTest;
    cout << "Do you want to run the point class test? (y/n): ";
    cin >> pointTest;
    if (pointTest == 'y') {
        testPointClass();
    }

    // 2.1 - Create and print a triangle
    int point1X, point1Y, point1Z, point2X, point2Y, point2Z, point3X, point3Y, point3Z;
    cout << "Enter triangle points coordinates " << endl;
    cout << " - Enter value for point 1 x: ";
    cin >> point1X;
    cout << " - Enter value for point 1 y: ";
    cin >> point1Y;
    cout << " - Enter value for point 1 z: ";
    cin >> point1Z;
    cout << " - Enter value for point 2 x: ";
    cin >> point2X;
    cout << " - Enter value for point 2 y: ";
    cin >> point2Y;
    cout << " - Enter value for point 2 z: ";
    cin >> point2Z;
    cout << " - Enter value for point 3 x: ";
    cin >> point3X;
    cout << " - Enter value for point 3 y: ";
    cin >> point3Y;
    cout << " - Enter value for point 3 z: ";
    cin >> point3Z;

    Point* v1 = new Point(point1X, point1Y, point1Z);
    Point* v2 = new Point(point2X, point2Y, point2Z);
    Point* v3 = new Point(point3X, point3Y, point3Z);

    Triangle* tempTriangle = new Triangle(v1, v2, v3);
    cout << endl << "Creating a triangle using these points:" << endl;
    tempTriangle->showCoordinates();
    cout << endl;


    // 2.2 - Show area of triangle
    // Note that there are no units here!
    cout << "Area of the triangle: " << tempTriangle->calcArea() << endl;
    cout << endl << endl;


    // 2.3 - Move the triangle in all three axes
    bool axisCheck = true;
    char userChoice, axis;
    int distance;
    while (axisCheck) {
        cout << "Do you want to check the translation function? (y/n): ";
        cin >> userChoice;
        if (userChoice == 'y') {
            cout << "Select axis (x, y, z): ";
            cin >> axis;
            if (axis != 'x' && axis != 'y' && axis != 'z') {
                cout << endl << "Error - Wrong axis input!" << endl;
                return;
            }
            cout << endl << "Enter distance: ";
            cin >> distance;
            if (cin.fail()) {
                cout << endl << "Error - Wrong distance input!" << endl;
                return;
            }

            cout << endl << "Moving triangle on " << axis << " by " << distance << ":" << endl;
            tempTriangle->translate(distance, axis);
            tempTriangle->showCoordinates();
            cout << endl << endl;
        }
        else {
            axisCheck = false;
        }
    }

    // 2.4 - Delete pointers
    delete tempTriangle;
    tempTriangle = nullptr;
}

int main(){
    int userInput = 0;
    cout << "-------------------------------------------------------------" << endl;
    cout << "-- COMP 371 - Computer Graphics                            --" << endl;
    cout << "-- Assignment 1                                            --" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Choose which part to demo:\n" << endl;
    cout << "1) Part 1: Array manipulation" << endl;
    cout << "2) Part 2: Point Class" << endl;
    cout << "\nYour choice: ";

    cin >> userInput;

    if (userInput == 1) {
        partOne();
    }
    else if (userInput == 2) {
        partTwo();
    }
    else {
        cout << "\nWrong input! Please select the right input next time.\n" << endl;
    }

    cout << "-------------------------------------------------------------" << endl;
    cout << "---                    End of program!                    ---" << endl;
    cout << "-------------------------------------------------------------" << endl;


    // Return statement
    return 0;
}