#ifndef BOOK_H_
#define BOOK_H_

#include <iostream>

#include "Item.h"

using namespace std;

class Book: public Item {

    private:
        /* hold's the book's author.
         * For this assignment we will assume that all
         * authors are exactly 10 characters long
         */
        string author;

    public:

        static const int AUTHOR_NUM_BYTES = 10;

        /* Creates an instance with default values
         * Initialize string members to "", numeric members to -1
         */
        Book();

        /**
         * Create an instance from the parameter values.
         */
        Book(const int id, const string title, const double price, const string author);

        /* Copy constructor performs member-wise copy */
        Book(const Book &other);

        /*
         * Performs member-wise copy
         *
         * A Must: invoke the base class' operator=
         */
        Book& operator=(Book&other);

        /* getter for author */
        string getAuthor() const;

        /**
         * Reads values from the command prompt in the following order
         * 1. id
         * 2. price
         * 3. title
         * 4. author
         *
         * A Must: invoke the base class' operator>>
         */
        friend istream& operator>>(istream &in, Book &book);

        /**
         * Prints the values from the command prompt in the following order
         * 1. id
         * 2. price
         * 3. title
         * 4. author
         *
         * A Must: invoke the base class' operator<<
         */
        friend ostream& operator<<(ostream &out, Book &book);
};
