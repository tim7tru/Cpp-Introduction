// Name:        Timmy Truong
// ID:          20772704
// Date:        September 19, 2018
// Course:      SYDE 121
// Lab room:    WEEF Lab - E2 1792
// Assignment:  Lab Assignment #1
// Exercise:    Exercise #3
// File Name:   lab02_3.cpp
//              I hereby declare that this code, submitted for credit for the course
//              SYDE121, is a product of my own efforts.  This coded solution has
//              not been plagiarized from other sources and has not been knowingly plagiarized by others.
// Project:     Sum of Integers

/*
 *
 * OUTLINE
 * 1.declare variables
 * 2.gather input from users
 * 3.put variables into equation given
 * 4.print results
 *
 * TEST VALUES AND RANGE
 * -Any integer works
 * -Plugged equation and values into TI-84 calculator and made notes.
 *      -results matched
 *      -tested the following values:
 *          - 1 to 100
 *          - 1 to 3000
 *          - 1 to 10000
 *          - (-10) to 15000
 *
 * OUTPUT FOR (a)
 * The sum of integers from 1 to 100 is 5050.
 * The sum of integers from 1 to 3000 is 4501500.
 * The sum of integers from 5 to 10000 is 50045000.
 *
 */

#include <iostream>

using namespace std;

int main() {

    // declare variables
    int n, d, a, sum;

    // getting input values from user
    cout << "What is the range of numbers you would like to know the sum of? Input the lower number, press enter, then input the higher number. " << endl;
    cin >> a >> n;
    cout << "What is the difference between each number? " << endl;
    cin >> d;

    // calculation as the assignment sheet
    sum = (n/2) * ((2*a) + d*(n-1));

    // print!
    cout << "The sum of numbers between " << a << " and " << n << " is " << sum << '.' << endl;

    return 0;
}