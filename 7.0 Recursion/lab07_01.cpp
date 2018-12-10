// Name:        Timmy Truong
// ID:          ID#20772704
// Date:        November 14, 2018
// Course:      SYDE 121
// Lab room:    WEEF Lab - E2 1792
// Assignment:  Lab Assignment #6
// Exercise:    Exercise #2
// File Name:   lab07_02.cpp

//              I hereby declare that this code, submitted for credit for the course
//              SYDE121, is a product of my own efforts.  This coded solution has
//              not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project:     Diamond Creator

/*
 * TESTING
 * Tested with negative and positive integers
 */

// Library Declaration
#include <iostream>
using namespace std;

bool run();
// [PURPOSE]    -   to run the simulation, asks the user for the integer value, calls the functions
// [INPUT]      -   user inputs the integer value
// [PROCESSING] -   calculates the line value, and calls the functions to print the top of the diamond and the bottom of the diamond
// [OUTPUT]     -   no output
void top(unsigned int value, int line);
// [PURPOSE]    -   prints the top of the diamond
// [INPUT]      -   no user input, integer value and line value are passed into this function
// [PROCESSING] -   for loops to print the appropriate amount of spaces and stars, then calls itself to print the next line
// [OUTPUT]     -   spaces & stars
void bottom(unsigned int value, int line);
// [PURPOSE]    -   prints the bottom of the diamond
// [INPUT]      -   no user input, integer value and line value are passed into this function
// [PROCESSING] -   for loops to print the appropriate amount of spaces and stars, then calls itself to print the next line
// [OUTPUT]     -   spaces & stars

// Main function - calls simulation function
int main() {
    run();
    return 0;
}

// to run the simulation
bool run() {
    // variable declaration
    unsigned int value;
    int line;

    // asking for user input about the integer value
    cout << "What is your integer value? ";
    cin >> value;

    // calculating line value
    line = value - (value - 1);

    // calling the functions to print the diamond
    top(value, line);
    bottom(value, line);

    return true;
}

// prints the top of the diamond include the middle point
void top(unsigned int value, int line) {
    // if the value is 0, then nothing is printed
    if (value == 0) {
        return;
    }
    // if the value is greater than zero then print this line
    else {
        // print the amount of spaces before the star ie. line # = number of spaces on one side of the stars
        for (int space_before = 0; space_before < value; space_before++) {
            cout << ' ';
        }
        // prints the star
        for (int stars = 0; stars < line; stars++) {
            cout << "* ";
        }
        // prints the amounts of spaces after the star
        for (int space_after = 0; space_after < value; space_after++) {
            cout << ' ';
        }
        // new line
        cout << endl;
        // increment the line value
        line++;
        // recursive function call to print the next line
        top(value-1, line);
    }
}

// prints the bottom of the diamond not including the middle point
void bottom(unsigned int value, int line) {
    // if the value is 0, then nothing is printed
    if (value == 0) {
        return;
    }
    else {
        // prints everythign in reverse, but essentially the same as top(). 
        for (int space_before = 0; space_before < line; space_before++) {
            cout << ' ';
        }
        for (int stars = 0; stars < value-1; stars++) {
            cout << " *";
        }
        for (int space_after = 0; space_after < line; space_after++) {
            cout << ' ';
        }
        cout << endl;
        line++;
        bottom(value-1, line);
    }
}