// COMP 371 - Summer 2024
// Assignment 1
// Faizan Ahmad (40100581)

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
static void deleteArray(int* arrayPointer) {
    cout << endl << "Deleting array... " << endl;
    // Delete memory allocated to array
    delete[] arrayPointer;

    cout << "Deleting pointer... " << endl;
    // Remove pointer
    arrayPointer = nullptr;

    cout << "Deleted array and pointer!" << endl;
}

// Function for running only the first part of the assignment (driver for part one)
static void partOne() {
    cout << "\n-----------   Part 1 - Array manipulation   -----------\n" << endl;

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
        cout << "\nWorking on it!\n" << endl;
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