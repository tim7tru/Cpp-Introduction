//
// Created by Timmy Truong on 2018-11-21.
//

#include "lab08_library.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// implementing library constructors
Library::Library() : books({}) {}

Library::Library(vector<Book> new_books) : books(new_books) {}

// defining print service method
void Library::print() {
    for (int i = 0; i < books.size(); i++) {
        books[i].print();
    }
}

// defining match service method
int Library::match(Book new_book) {
    for (int i = 0; i < books.size(); i++) {
        Book current = books[i];
        // checking for match
        bool match_title = (current.get_title() == new_book.get_title());
        bool match_author = (current.get_authors() == new_book.get_authors());
        bool match_dop = (current.get_dop() == new_book.get_dop());

        // if there is a match
        if (match_title && match_author && match_dop) {
            return i;
        }
    }
    // if there is no match (had to be <0)
    return -1;
}

// defining insert book method with parameters
bool Library::insert_book(string new_title, string new_authors, string new_dop) {
    Book new_book(new_title, new_authors, new_dop);
    return insert_book(new_book);
}

// defining insert book method with vector attribute
bool Library::insert_book(Book new_book) {
    // if the book is already in the library
    if (match(new_book) != -1) {
        cout << "The book is already in the library." << endl;
        return false;
    } else { // if the book is not, put it in!
        books.push_back(new_book);
        cout << "The book was inserted into the library." << endl;
        return true;
    }
}

// defining remove book method with parameters
bool Library::remove_book(string cur_title, string cur_authors, string cur_dop) {
    Book cur_book(cur_title, cur_authors, cur_dop);
    return remove_book(cur_book);
}

// defining remove book method with vector attribute
bool Library::remove_book(Book cur_book) {
    // if the book is in the library, take it out
    if (match(cur_book) != -1) {
        books.erase(books.begin() + match(cur_book));
        cout << "The book has been removed from the library." << endl;
        return true;
    } else { // if it's not in the library, cant remove
        cout << "This book is not in the Library." << endl;
        return false;
    }
}
