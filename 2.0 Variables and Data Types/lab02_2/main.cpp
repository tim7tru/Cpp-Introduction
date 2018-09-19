// Name:        Timmy Truong
// ID:          ID#20772704
// Date:        September 19, 2018
// Course:      SYDE 121
// Lab room:    WEEF Lab - E2 1792
// Assignment:  Lab Assignment #1
// Exercise:    Exercise #2
// File Name:   lab02_2.cpp

//              I hereby declare that this code, submitted for credit for the course
//              SYDE121, is a product of my own efforts.  This coded solution has
//              not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project:     Earth Population Calculator

/*
 *
 * OUTLINE
 * 1.declare variables used, e & years
 * 2.use equation given and calculate population
 * 3.repeat until all years are calculated
 * 4.print out!

 * TEST VALUES AND RANGE
 * -Used TI-84 Calculator to manually test values
 *      -2018 outputted 8.60 billion people (rounded)
 *      -2025 outputted 9.89 billion people (rounded)
 *      -2050 outputted 16.31 billion people (rounded)
 *      -2100 outputted 44.33 billion people (rounded)
 * As long as the output is a positive whole number, the result makes sense according to the equation.
 * There is a whole range of values that output decimal numbers

 * OUTPUT
 * In 2018, the estimated population is around 8.60 billion people.
 * In 2025, the estimated population is around 9.89 billion people.
 * In 2050, the estimated population is around 16.31 billion people.
 * In 2100, the estimated population is around 44.33 billion people.

 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    // declare what e is, and declare year variables
    // Value obtained from https://en.wikipedia.org/wiki/E_(mathematical_constant)
    // e is constant thus it is denoted as 'E'
    const double E = 2.71828182845904523536;
    int year2018 = 2018;
    int year2025 = 2025;
    int year2050 = 2050;
    int year2100 = 2100;

    // population calculations according to the equation given on the assignment:
    // population = 6.0e^(0.02*[Current Year - 2000])
    double population2018 = 6.0 * pow(E, (0.02*(year2018 - 2000)));
    double population2025 = 6.0 * pow(E, (0.02*(year2025 - 2000)));
    double population2050 = 6.0 * pow(E, (0.02*(year2050 - 2000)));
    double population2100 = 6.0 * pow(E, (0.02*(year2100 - 2000)));

    // set precision to two decimal points as in given equation
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // print out!
    cout << "In 2018, the estimated population is around " << population2018 << " billion people." << endl;
    cout << "In 2025, the estimated population is around " << population2025 << " billion people." << endl;
    cout << "In 2050, the estimated population is around " << population2050 << " billion people." << endl;
    cout << "In 2100, the estimated population is around " << population2100 << " billion people." << endl;

    return 0;
}