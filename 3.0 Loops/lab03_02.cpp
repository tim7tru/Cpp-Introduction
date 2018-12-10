// Name:        Timmy Truong
// ID:          ID#20772704
// Date:        September 26, 2018
// Course:      SYDE 121
// Lab room:    WEEF Lab - E2 1792
// Assignment:  Lab Assignment #2
// Exercise:    Exercise #2
// File Name:   lab03_02.cpp

//              I hereby declare that this code, submitted for credit for the course
//              SYDE121, is a product of my own efforts.  This coded solution has
//              not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project:     Free Fall Calculator

/*

 * OUTLINE
 * 1.declare variables and constants
 * 2.fix the precision
 * 3.ask for input
 * 4.table headings
 * 5.calculations and appropriate output with the table
 * 6.decrease scope

 * TEST VALUES AND RANGE
 * The user must input a positive number.
 * The program does not accept negative numbers.
 * The program accepts double data type variables

 */
#include <iostream>

using namespace std;

int main() {
    // declaring variables
    const double G = 9.80665, TIME_SCOPE = 0.1;
    double distance, total_distance = 0, time = 0, distance_interval;

    // fix the precision of decimals to 3 decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    // asking for user input to calculate the height the object fell from
    cout << "What distance are you dropping your object from? (in meters)" << endl;
    cin >> distance;

    // table heading
    cout << "Time (in sec):\t\t\t\t\t" << "Total distance travelled (in m):\t\t\t\t" << "Distance Remaining (in m):" << endl;

    // calculations for 1.0 second intervals up until 1000m is left
    if (distance > 0) {
        for (distance_interval = distance; distance_interval > 1000; time++) {
            total_distance = 0.5 * G * time * time;
            distance_interval = distance - total_distance;

            if (total_distance < 1000) {
                cout << time << "\t\t\t\t\t\t\t" << total_distance << "\t\t\t\t\t\t\t\t\t\t\t" << distance_interval
                     << endl;
            } else {
                cout << time << "\t\t\t\t\t\t\t" << total_distance << "\t\t\t\t\t\t\t\t\t\t" << distance_interval
                     << endl;
            }
        }

        // calculation for 0.1 second intervals until 0m
        for (; distance_interval > 0; time += TIME_SCOPE) {
            total_distance = 0.5 * G * time * time;
            distance_interval = distance - total_distance;

            if (total_distance < distance) {
                cout << time << "\t\t\t\t\t\t\t" << total_distance << "\t\t\t\t\t\t\t\t\t\t" << distance_interval
                     << endl;
            }
        }
    }
    else {
        cout << "Please enter a positive number. The program will now quit." << endl;
    }
    cout << "Therefore it takes around " << time - TIME_SCOPE << " seconds to hit the ground." << endl;

    return 0;
}