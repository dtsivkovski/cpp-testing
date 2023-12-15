#include <iostream>
#include <string>
using namespace std;

class Book {
    private:
        string title;
        string author;
        long ISBN;
        bool checkedOut;
    public:
        // constructor 
        Book(string title, string author, long ISBN) {
            this->title = title;
            this->author = author;
            this->ISBN = ISBN;
            this->checkedOut = false;
        }
        int checkOut() {
            if (checkedOut == true) {
                return -1; // failed to check out
            }
            else {
                checkedOut = true;
                return 1;
            }
        }
        int checkIn() {
            if (checkedOut == false) {
                return -1; // failed to check in
            }
            else {
                checkedOut = false;
                return 1;
            }
        }

        /*
            Accessors
        */
        string getTitle() {
            return title;
        }
        string getAuthor() {
            return author;
        }
        long getISBN() {
            return ISBN;
        }
        bool isCheckedOut() {
            return checkedOut;
        }
        string toString() {
            string s = "Title: " + title + "\n";
            s += "Author: " + author + "\n";
            s += "ISBN: " + to_string(ISBN) + "\n";
            s += "Checked Out: " + (checkedOut ? string("Yes") : string("No")) + "\n";
            return s;
        }
        

};

int main() {
    Book b1("The Iliad", "Homer", 1324001801);
    Book b2("Fourth Wing (The Empyrean, 1)", "Rebecca Yarros", 1649374046);
    cout << b1.toString() << endl;
    cout << b2.toString() << endl;
    b1.checkOut();
    cout << b1.toString() << endl;
    b1.checkIn();
    cout << b1.toString() << endl;
}