// Name:        Timmy Truong
// ID:          ID#20772704
// Date:        October 26, 2018
// Course:      SYDE 121
// Lab room:    WEEF Lab - E2 1792
// Assignment:  Lab Assignment #4
// Exercise:    Exercise #2
// File Name:   lab05_02.cpp

//              I hereby declare that this code, submitted for credit for the course
//              SYDE121, is a product of my own efforts.  This coded solution has
//              not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project:     Max, Min, Mean, Standard Deviation Calculator

/*
 * TESTING
 * Tested using set of values found on: https://www.mathsisfun.com/data/standard-deviation-formulas.html
 */

// Libraries included
#include <iostream>
#include <array>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <cmath>

using namespace std;

// Function Declarations
bool run();
// [INPUT]      - asks user if they want to replace a value
// [PROCESSING] - calls all the processing functions
// [OUTPUT]     - asks user if they want to replace a value
bool entry(vector<double>& values);
// [INPUT]      - user inputs value to be stored in vector
// [PROCESSING] - decides whether the inputted value is the ending value, if not, it changed the string to a double
// [OUTPUT]     - asks user to input value
double mean_calculation(vector<double> values, double mean);
// [INPUT]      - function takes vector as input
// [PROCESSING] - calculates mean of numbers
// [OUTPUT]     - none
double maximum_calculation(vector<double> values, double maximum);
// [INPUT]      - function takes vector as input
// [PROCESSING] - calculates maximum of numbers
// [OUTPUT]     - none
double minimum_calculation(vector<double> values, double minimum);
// [INPUT]      - function takes vector as input
// [PROCESSING] - calculates in of numbers
// [OUTPUT]     - none
double standard_calculation(vector<double> values, double stan_dev, double mean);
// [INPUT]      - function takes vector as input
// [PROCESSING] - calculates standard deviation
// [OUTPUT]     - none
void calculations(vector<double> values);
// [INPUT]      - function takes vector as input
// [PROCESSING] - calls all the calulation functions
// [OUTPUT]     - outputs the calculated mean, maximum, minimum, standard deviation
bool replacement (vector<double>& values);
// [INPUT]      - user inputs the location and value to be changed
// [PROCESSING] - changes the input at that location
// [OUTPUT]     - asks for user to input location and value to be changed

// constant declaration
const int ARRAY_SIZE = 21;

// main function
int main() {
    run();
    return 0;
}

// run function to check if the function should run based on user inputs
bool run() {
    char continue_run;
    vector<double> values;

    if (entry(values)) {
        calculations(values);
        do {
            replacement(values);
            calculations(values);
            cout << "Would you like to replace another value? Enter 'y' or 'Y' for yes. Enter any other key to exit the program. ";
            cin >> continue_run;
        } while (continue_run == 'y' || continue_run == 'Y'); // quit decision
    }
    return true;
}

// entry function to get user input into the vector
bool entry(vector<double>& values) {
    string input;
    double converted;
    cout << "Enter your values. When you are finished, enter 'd' or 'done'." << endl;
    for (int index = 0; index < ARRAY_SIZE; index++) {
        cin >> input;
        if (input == "d" || input == "done") {
            break;
        }
        else {
            values.push_back(stod(input));
        }
    }
    return true;
}

// calculates the mean of the inputted numbers
double mean_calculation(vector<double> values, double mean) {
    double current_value = 0;
    int counter = 0;
    for (int i = 0; i < values.size(); i++) {
        current_value += values[i];
        counter++;
    }
    mean = current_value / counter;
    return mean;
}

// calculates the maximum of the inputted numbers
double maximum_calculation(vector<double> values, double maximum) {
    maximum = *max_element(values.begin(), values.end());
    return maximum;
}

// calculates the minimum of the inputted numbers
double minimum_calculation(vector<double> values, double minimum) {
    minimum = *min_element(values.begin(), values.end());
    return minimum;
}

// calculates the standard deviation of the inputted numbers
double standard_calculation(vector<double> values, double stan_dev, double mean) {
    double current_value = 0;
    int counter = 0;
    double step_three = 0;
    for (int i = 0; i < values.size(); i++) {
        current_value += ((values[i] - mean) * (values[i] - mean));
        counter++;
    }
    step_three = current_value / counter;
    stan_dev = sqrt(step_three);

    return stan_dev;
}

// groups all the calculations and organizes output of the display
void calculations(vector<double> values) {
    double mean = 0, maximum = 0, minimum = 0, stan_dev = 0;
    mean = mean_calculation(values, mean);
    maximum = maximum_calculation(values, maximum);
    minimum = minimum_calculation(values, minimum);
    stan_dev = standard_calculation(values, stan_dev, mean);
    cout << "Mean: " << mean << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;
    cout << "Standard Deviation: " << stan_dev << endl;
}

// to replace the value at a specified location
bool replacement(vector<double>& values) {
    int location, replace;
    cout << "Enter the location of the value you would like to replace: ";
    cin >> location;
    cout << "What value would you like to replace it with?";
    cin >> replace;

    values[location] = replace;

    cout << "Your new array is now: ";
    for (int index = 0; index < values.size(); index++) {
        cout << values[index] << ' ';
    }
    cout << endl;
    return true;
}