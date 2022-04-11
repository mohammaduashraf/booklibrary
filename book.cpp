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
        Book(): Item(-1, "", -1)
        {
            author = "";  
        }

        /**
         * Create an instance from the parameter values.
         */
        Book(const int id, const string title, const double price, const string author) : Item(id, title, price)
        {
 
            this->author = author; 
        }

        /* Copy constructor performs member-wise copy */
        Book(const Book &other): Item (other)
        {
            id = other.getId(); 
            price = other.getPrice(); 
            title = other.getTitle(); 
            this-> author = other.getAuthor(); 
        }
        /*
         * Performs member-wise copy
         *
         * A Must: invoke the base class' operator=
         */
        Book& operator=(Book&other)
        {
              Book k(other.getId(), other.getTitle(), other.getPrice(),other.getAuthor());
			  return k = other; 
        }
        /* getter for author */
		string getAuthor() const
		{
			return author;
		}

        /**
         * Reads values from the command prompt in the following order
         * 1. id
         * 2. price
         * 3. title
         * 4. author
         *
         * A Must: invoke the base class' operator>>
         */
        friend istream& operator>>(istream &in, Book &book)
        {
            //stringstream os; 
            in >>  book.id >> book.title >> book.price >> book.author; 
            //in >> os.str(); 
            return in; 
        }

        /**
         * Prints the values from the command prompt in the following order
         * 1. id
         * 2. price
         * 3. title
         * 4. author
         *
         * A Must: invoke the base class' operator<<
         */
        friend ostream& operator<<(ostream &out, Book &book)
        {
          //  stringstream os; 
            out << book.id << " " << book.title << " " << book.price << " " << book.author; 
           // out << os.str(); 
            return out; 
        }
};

#endif /* BOOK_H_ */
