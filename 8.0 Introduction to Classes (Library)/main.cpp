// Name:        Timmy Truong
// ID:          ID#20772704
// Date:        November 22, 2018
// Course:      SYDE 121
// Lab room:    WEEF Lab - E2 1792
// Assignment:  Lab Assignment #7
// Exercise:    Exercise #1
// File Name:   lab08_main.cpp, lab08_book.hpp, lab08_book.cpp, lab08_library.hpp, lab08_library.cpp

//              I hereby declare that this code, submitted for credit for the course
//              SYDE121, is a product of my own efforts.  This coded solution has
//              not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project:     classes, books, libraries

/*
 * TESTING
 * Tested all varients of objects and tested method with thing that didnt work ie.
 * books that were not in the library or already in the library.
 */

#include <iostream>
#include <vector>
#include "lab08_book.cpp"
#include "lab08_library.cpp"

using namespace std;

// declaring objects and functions
Library test_library; // declare this so it can be used for all functions
bool test_book_insertion();
bool test_book_removal();
bool run();

// inserting books test
bool test_book_insertion() {
    // defining first book with all the parameters
    Book HP_1("HP: The Philosopher's Stone", "JK Rowling", "26 June 1997");
    // defining second book with 2 parameters
    Book _1984("1984", "George Orwell");
    // defining third book with one parameter
    Book OfMiceAndMen("Of Mice and Men");
    // defining fourth book with no parameters
    Book MeinKampf("");

    // inserting the books and looking for successful message
    test_library.insert_book(HP_1);
    test_library.insert_book(_1984);
    test_library.insert_book(OfMiceAndMen);
    test_library.insert_book("HP: Chamber of Secrets", "JK Rowling", "2 July 1998 "); // using the other object with three parameters
    test_library.insert_book(MeinKampf);
    test_library.insert_book(OfMiceAndMen); // trying to add a book that is already in the library is not allowed
    return true;
}

// removing books test
bool test_book_removal() {
    // defining first book with all the parameters
    Book HP_1("HP: The Philosopher's Stone", "JK Rowling", "26 June 1997");
    // defining second book with 2 parameters
    Book _1984("1984", "George Orwell");
    // defining third book with one parameter
    Book OfMiceAndMen("Of Mice and Men");
    // defining fourth book with no parameters
    Book _1985("");

    // removing books and looking for successful message
    test_library.remove_book(HP_1);
    test_library.remove_book(_1984);
    test_library.remove_book(OfMiceAndMen);
    test_library.remove_book("HP: Chamber of Secrets", "JK Rowling", "2 July 1998 ");
    test_library.remove_book(_1985); // trying to remove a book that isnt even in the library is not allowed
    return true;
}

// run simulation
bool run() {
    // set variable to true (initialization)
    bool test_results = true;

    // if the test results are true, then the simulation is successful
    test_results = test_results && test_book_insertion();
    test_results = test_results && test_book_removal();
    return test_results;

}

int main() {

    // successful message!
    cout << (run() ? "All tests passed." : "Some tests failed.");

    return 0;
}