//
// Created by Timmy Truong on 2018-11-21.
//

#ifndef LAB08_LAB08_BOOK_HPP
#define LAB08_LAB08_BOOK_HPP

#include <iostream>
using namespace std;

// PURPOSE: Models information about a book
class Book {
    // corresponding information for a Book instance
    string title, authors, date_of_publication;

public:
    // PURPOSE: default/empty constructor
    Book();

    // PURPOSE: parametric constructor that takes
    //          one string as parameter value
    Book(string new_title);

    // PURPOSE: parametric constructor that takes
    //          two strings as parameter values
    Book(string new_title,
         string new_authors);

    // PURPOSE: parametric constructor that takes
    //          three strings as parameter values
    Book(string new_title,
         string new_authors,
         string new_dop);

    // PURPOSE: getters for individual attribute values
    string get_title();
    string get_authors();
    string get_dop();

    // PURPOSE: prints out the contents of the book objects
    void print();
};

#endif //LAB08_LAB08_BOOK_HPP
