#include "BookLibrary.hpp"

/*
void BookLibrary::deleteFromDisk(const std::string fileName, const unsigned int index) { 
    <#code#>;
}


int *BookLibrary::readSingleObjectFromDisk(const std::string fileName, const unsigned int index) { 
    <#code#>;
}
*/

bool BookLibrary::serializeToDisk(const string fileName) {

    string appendFileName ="/Users/Customer/Desktop/";
    appendFileName.append(fileName);
    appendFileName.append(".bin");
  

    ofstream write_file(fileName, ios::out | ios::binary);
    if (write_file.is_open()){
       for (int i =0; i< vecBookLibrary->size(); i++) {
           int id = (*vecBookLibrary)[i].getId();
           double price = (*vecBookLibrary)[i].getPrice();
           string title = (*vecBookLibrary)[i].getTitle();
           string author = (*vecBookLibrary)[i].getAuthor();
           
           write_file.write(reinterpret_cast<char *>(&id), sizeof(int));
           write_file.write(reinterpret_cast<char *>(&price), sizeof(double));
           write_file.write(reinterpret_cast<char *>(&title), 18);
           write_file.write(reinterpret_cast<char *>(&author), 10);
       }
        write_file.flush();
        write_file.close();
        return true;
    }
    cout << " File could not be opened." << endl;
    return false;
}


BookLibrary::~BookLibrary() { 
     delete vecBookLibrary;
 //   delete BookLibrary2;
}


BookLibrary::BookLibrary() {
    vecBookLibrary = new vector<Book>;
  //  BookLibrary2 = new vector<Book>;
}


bool BookLibrary::loadFromFile(const string fileName) {
    string appendFileName ="/Users/Customer/Desktop/";
    appendFileName.append(fileName);
    appendFileName.append(".bin");

    double sizeOfVector = vecBookLibrary->size();
    
    vecBookLibrary->clear();

    ifstream read_file;
    read_file.open(fileName, ios::binary);
    
    if (read_file.is_open()) {
    for (int i = 0; i < sizeOfVector ; i++) {
        
        int id = (*vecBookLibrary)[i].getPrice();
        double price = (*vecBookLibrary)[i].getPrice();
        string title = (*vecBookLibrary)[i].getTitle();
        string author = (*vecBookLibrary)[i].getAuthor();
        
        read_file.read(reinterpret_cast<char *>(&id), sizeof(int));
        read_file.read(reinterpret_cast<char *>(&price), sizeof(double));
        read_file.read(reinterpret_cast<char *>(&title), 18);
        read_file.read(reinterpret_cast<char *>(&author), 10);
      }
    }
    
            cout << "File could not be opened. " << endl;
            return false; 
    
}
        

void BookLibrary::add(const Book &book) const {
    vecBookLibrary->push_back(book);
}
