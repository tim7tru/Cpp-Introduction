// Name:        Timmy Truong
// ID:          ID#20772704
// Date:        September 26, 2018
// Course:      SYDE 121
// Lab room:    WEEF Lab - E2 1792
// Assignment:  Lab Assignment #2
// Exercise:    Exercise #1
// File Name:   lab03_01.cpp

//              I hereby declare that this code, submitted for credit for the course
//              SYDE121, is a product of my own efforts.  This coded solution has
//              not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project:     Prime Numbers Checker

/*

 * OUTLINE
 * 1.declare variables used
 * 2.ask user for input
 * 3.set up for loop to iterate every number
 * 4.add another for loop to see if the iterated number is prime
 * 4.if statements to check if:
 *      a.number is prime
 *      b.if the number is prime, check if the sum of digits is odd, or if it is palindromic

 * TEST VALUES AND RANGE
 * -the inputted number must be positive
 * -palindromic only tests numbers less than 10000
 * -sum of digits only tests numbers less than 100000
 *
 */
#include <iostream>

using namespace std;

int main() {
    // declare variables
    int input_number, ten_thousands, thousands, hundreds, tens, ones;

    // ask for input from the user
    cout << "Welcome to the prime number finder!" << endl;
    cout << "Enter a number, and this program will find all the prime numbers less than or equal to that number!" << endl;
    cout << "Enter a number: ";
    cin >> input_number;

    if (input_number > 0) {
        // for loop that iterates looking for numbers that are prime & prints out the correct statements
        for (int i = 0; i <= input_number; i++) {
            bool prime = true;
            for (int x = 2; x < i; x++) {
                if (i % x == 0) {
                    prime = false;
                }
            }
            // prints the prime number according to whether the sum of digits is odd or if they are palindromic or both
            if (prime) {
                if (i < 100000 && i > 10000) {
                    ten_thousands = i / 10000;
                    thousands = (i % 10000) / 1000;
                    hundreds = ((i % 10000) % 1000) / 100;
                    tens = (((i % 10000) % 1000) % 100) / 10;
                    ones = ((((i % 10000) % 1000) % 100) % 10);

                    if ((ten_thousands + thousands + hundreds + tens + ones) % 2 != 0) {
                        cout << i << " is a prime number and the sum of digits is odd." << endl;
                    } else {
                        cout << i << " is a prime number." << endl;
                    }
                } else if (i < 10000 && i > 1000) {
                    thousands = i / 1000;
                    hundreds = (i % 1000) / 100;
                    tens = ((i % 1000) % 100) / 10;
                    ones = ((i % 1000) % 100) % 10;

                    if ((thousands + hundreds + tens + ones) % 2 != 0 && thousands == ones && hundreds == tens) {
                        cout << i << " is a prime number, the sum of digits is odd, and it is a palindromic number."
                             << endl;
                    } else if (thousands == ones && hundreds == tens) {
                        cout << i << " is a prime number and it is a palindromic number." << endl;
                    } else if ((thousands + hundreds + tens + ones) % 2 != 0) {
                        cout << i << " is a prime number and the sum of digits is odd." << endl;
                    } else {
                        cout << i << " is a prime number." << endl;
                    }
                } else if (i < 1000 && i > 100) {
                    hundreds = i / 100;
                    tens = (i % 100) / 10;
                    ones = (i % 100) % 10;

                    if ((hundreds + tens + ones) % 2 != 0 && hundreds == ones) {
                        cout << i << " is a prime number, the sum of digits is odd, and it is a palindromic number."
                             << endl;
                    } else if (hundreds == ones) {
                        cout << i << " is a prime number and it is a palindromic number." << endl;
                    } else if ((hundreds + tens + ones) % 2 != 0) {
                        cout << i << " is a prime number and the sum of digits is odd." << endl;
                    } else {
                        cout << i << " is a prime number." << endl;
                    }
                } else if (i < 100 && i > 10) {
                    tens = i / 10;
                    ones = i % 10;

                    if ((tens + ones) % 2 != 0 && tens == ones) {
                        cout << i << " is a prime number, the sum of digits is odd, and it is a palindromic number."
                             << endl;
                    } else if (tens == ones) {
                        cout << i << " is a prime number and it is a palindromic number." << endl;
                    } else if ((tens + ones) % 2 != 0) {
                        cout << i << " is a prime number and the sum of digits is odd." << endl;
                    } else {
                        cout << i << " is a prime number." << endl;
                    }
                } else if (i < 10 && i >= 2) {
                    cout << i << " is a prime number." << endl;
                }
            }
        }
    }
    else {
        cout << "Number must be positive. The program will now quit." << endl;
    }
    return 0;
}