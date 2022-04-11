/*
 * Name:
 */
#ifndef BOOK_LIBRARY_H_
#define BOOK_LIBRARY_H_

const static int MAX_CHAR_ARR_SIZE = 64;

#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Book.h"

using namespace std;

class BookLibrary {
    private:
        vector<Book> *vecBookLibrary;

    public:

        /* Initialize vector pointer */
        BookLibrary()
        {
        	Book a;
            vecBookLibrary->push_back(a); 
        }

        /* deallocates membory */
        ~BookLibrary(){}; 

        /**
         * Adds a new book instance to the vector libarary
         */
        void add(const Book &book) const
        {
            vecBookLibrary->push_back(book);  
        }

        /**
         * Reads objects from the specified binary file and adds them to the vector
         * Return true if the read operation succeeds, false otherwise.
         * Any existing objects in the vector are removed
         */
        bool loadFromFile(const string fileName)
        {
            fstream in(fileName, ios::binary | ios::in);
            if(in.is_open())
            {
            	int id,price;
            	string title,author;
            	title.resize(MAX_CHAR_ARR_SIZE);
            	author.resize(MAX_CHAR_ARR_SIZE);
                vecBookLibrary->clear();
                while(!in.eof())
                {
                	in.read((char*)&id,sizeof(id));
                	in.read(&title[0],MAX_CHAR_ARR_SIZE);
                	in.read((char*)&price,sizeof(price));
                	in.read(&author[0],MAX_CHAR_ARR_SIZE);
                	Book a (id,title,price,author);
                	vecBookLibrary->push_back(a);
                }
                in.close();
                return true;
            } 
            in.close();
            return false;
        }

        /**
         * Writes the vector to Disk in binary format. Each object is written as a
         * fixed-width character array.
         *
         * Hint: use the object's char conversion operator
         */
        bool serializeToDisk(const string fileName)
        {
            fstream out(fileName,ios::binary | ios :: out);
            for (int i = 0; i < vecBookLibrary->size(); i++)
            {
            	Book current = vecBookLibrary->at(i); 
            	int id = current.getId();
			    string title = current.getTitle();
            	int price = current.getPrice();
            	string author = current.getAuthor();
            	out.write(reinterpret_cast<const char*>(&id),sizeof(id));
            	out.write(&title[0],MAX_CHAR_ARR_SIZE);
            	out.write(reinterpret_cast<const char*>(&price),sizeof(price));
            	out.write(&author[0],MAX_CHAR_ARR_SIZE);
            }
			out.flush();
			out.close();

            exit(1); 
        }

        /* Formats and prints the contents of the vector to the command line */
        void printFormatted() const {

            for (unsigned int i = 0; i < vecBookLibrary->size(); ++i)
                cout << "Book " << i << ": " << (*vecBookLibrary)[i] << endl;
        }

        // Bonus
        /**
         * Reads a single object from disk NOT from the vector
         * if the index is invalid, return null
         */
        // Book* readSingleObjectFromDisk(const string fileName, const unsigned int index);
		// {
		// 	fstream in(fileName, ios::binary | ios::in);
		// 	Book b (id,title,price,author);
        //     if(in.is_open())
        //     {
        //     	int id,price;
        //     	string title,author;
        //     	title.resize(MAX_CHAR_ARR_SIZE);
        //     	author.resize(MAX_CHAR_ARR_SIZE);
        //         in.read((char*)&id,sizeof(id));
        //         in.read(&title[0],MAX_CHAR_ARR_SIZE);
        //         in.read((char*)&price,sizeof(price));
        //         in.read(&author[0],MAX_CHAR_ARR_SIZE);
        //         vecBookLibrary->push_back(b); 
        //     } 
        //     in.close();
        //     return false;
		// }
        // Bonus
        /**
         * Deletes an object from disk and the vector at the specified index
         * if the index is invalid, no records will be deleted
         */
        //void deleteFromDisk(const string fileName, const unsigned int index);
};

#endif /* BOOK_LIBRARY_H_ */