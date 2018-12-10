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

// Project:     Substring-Target Indication

/*
 * TESTING
 * Tested all base cases for each recursive function.
 * Tested various strings that returned true and false
 */

// Library Declaration
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// FUNCTION DECLARATIONS
bool check_if_contains(vector <char> target, vector <char> substr, unsigned long int tar_size, unsigned long int sub_size, int place1, int place2);
// [PURPOSE]    -   checks to see if the first character in the substring matches any of the characters in the target
// [INPUT]      -   no user input, the target, substring, target size, substring size, and initialized indices are passed into the function
// [PROCESSING] -   checks base cases, check if there is a match or not, calls the appropriate recursive function
// [OUTPUT]     -   no output
bool character_match(vector <char> target, vector <char> substr, unsigned long int sub_size, int place1, int place2);
// [PURPOSE]    -   checks if consecutive characters match until the substring reaches its endpoint
// [INPUT]      -   no user input, the target, substring, substring size, and indices are passed into the function
// [PROCESSING] -   checks base cases, check if the match continues to the end of the substring using recursive function
// [OUTPUT]     -   no output
bool run();
// [PURPOSE]    -   initalizes variables, gathers input, and calls the functions
// [INPUT]      -   user inputs the target and substring string
// [PROCESSING] -   calculates target and substring size and passes the target, substring, target size, substring size, and indices into the function; checks
//                  if the check_if_contains function returns true and outputs accordingly
// [OUTPUT]     -   true or false


// main function to run the run boolean function
int main() {
    run();
    return 0;
}

// to run the simulation
bool run() {
    // initialize the variables and vectors
    vector <char> target;
    vector <char> substr;
    char input1, input2;

    // asking for target string
    cout << "What is the target string? Enter * when you are finished entering. ";
    // looking for the endpoint
    while (input1 != '*') {
        cin >> input1;
        // putting the string into the vector
        target.push_back(input1);
    }

    // asking for the substring string
    cout << "What is the substring? Enter * when you are finished entering. ";
    // looking for the endpoint
    while (input2 != '*') {
        cin >> input2;
        // putting the string into the vector
        substr.push_back(input2);
    }

    // removing the endpoints of the strings
    target.pop_back();
    substr.pop_back();

    // calculating vector sizes and storing them
    unsigned long int tar_size = target.size();
    unsigned long int sub_size = substr.size();

    // initializing the index variables
    int place1 = 0;
    int place2 = 0;

    // calling the checking functions to see if the substring matches the target anywhere
    if (check_if_contains(target, substr, tar_size, sub_size, place1, place2)) {
        // if there is a match
        cout << "The string is a substring in the target string (True)" << endl;
    }
    else {
        // if there isn't a match
        cout << "The string is not a substring in the target string (False)" << endl;
    }

    return true;
}

// checking the target for the substring's first letter
bool check_if_contains(vector <char> target, vector <char> substr, unsigned long int tar_size, unsigned long int sub_size, int place1, int place2) {
    // if the target reaches the end of the vector without having found the substring's first letter, it returns false
    if (target[place2] == target[tar_size - 1]) {
        return false;
    }
    // if the target size is smaller than the substring, then it returns false
    else if (tar_size < sub_size) {
        return false;
    }
    // if the target size is 0, then it returns true
    else if (tar_size == 0) {
        return true;
    }
    // if the substring size is 0, then it returns false
    else if (sub_size == 0) {
        return false;
    }
    // if the substring's first letter matches any of the characters in the target
    else if (substr[place1] == target[place2]) {
        // it calls the match function to check if the match continues throughout the entire substring/target
        return character_match(target, substr, sub_size, place1, place2);
    }
    else {
        // checks the first letter of the substring with the next character in target
        return check_if_contains(target, substr, tar_size, sub_size, place1, place2 + 1);
    }
}

// checking the target for more matches
bool character_match(vector <char> target, vector <char> substr, unsigned long int sub_size, int place1, int place2) {
    // if the substring reaches the end of the vector, it means the match is complete, thus returns true;
    if (substr[place1] == substr[sub_size - 1]) {
        return true;
    }
    // checking if the substring's next character matches the target's next character
    else if (substr[place1] == target[place2]) {
        // recursive function that checks the next character in each vector
        return character_match(target, substr, sub_size, place1 + 1, place2 + 1);
    }
    else {
        // if there is no match, returns false
        return false;
    }
}
