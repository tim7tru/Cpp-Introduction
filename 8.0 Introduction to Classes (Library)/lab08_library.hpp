//
// Created by Timmy Truong on 2018-11-21.
//

#ifndef LAB08_LAB08_LIBRARY_HPP
#define LAB08_LAB08_LIBRARY_HPP

#include <iostream>
#include <vector>
#include "lab08_book.hpp"

using namespace std;

// PURPOSE: Models a collection of books
class Library {
    // a vector of Book instances
    vector<Book> books;
    // fuction declaration for checking if book is in library
    int match(Book book);

public:
    // CONSTRUCTORS

    // PURPOSE: default/empty constructor
    Library();

    // PURPOSE: parametric constructor that takes
    //          a new vector instance as input
    Library(vector<Book> new_books);

    /// SERVICE METHODS

    // PURPOSE: prints information for all the books
    //          currently stored in the library
    void print();

    // PURPOSE: inserts a new book into the library
    //     INPUTS: new_title, new_authors, new_dop
    //             - values for the object that is to be inserted
    //     RETURNS: true, if the insertion was succesful;
    //              false, otherwise
    bool insert_book(string new_title,
                     string new_authors,
                     string new_dop);

    // PURPOSE: inserts a new book into the library
    //     INPUTS: new_book - values for the object
    //             that is to be inserted
    //     RETURNS: true, if the insertion was succesful;
    //              false, otherwise
    bool insert_book(Book new_book);

    // PURPOSE: removes a selected book from the library
    //     INPUTS: cur_title, cur_authors, cur_dop
    //             - values for the object that is to be removed
    //     RETURNS: true, if the removal was succesful;
    //              false, otherwise
    bool remove_book(string cur_title,
                     string cur_authors,
                     string cur_dop);

    // PURPOSE: removes a selected book from the library
    //     INPUTS: cur_book - values for the object
    //             that is to be removed
    //     RETURNS: true, if the removal was succesful;
    //              false, otherwise
    bool remove_book(Book cur_book);
};

#endif //LAB08_LAB08_LIBRARY_HPP
