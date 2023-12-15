#include <iostream>
#include <string>
#include <unordered_map>
#include "book.h"

class Library {
    private:
        unordered_map<long, Book> books;
        long visits;
    public:
        Library() {
            this->visits = 0;
        }
        void addBook(Book book) {
            books[book.getISBN()] = book;
        }
        void addBook(string title, string author, long ISBN) {
            Book bb(title, author, ISBN);
            books[bb.getISBN()] = bb;
        }
        void removeBook(long ISBN) {
            books.erase(ISBN);
        }

        void checkOut(long ISBN) {
            books[ISBN].checkOut();
            visits++;
        }
        void checkIn(long ISBN) {
            books[ISBN].checkIn();
            visits++;
        }
        string toString() {
            string s = "Library\n-------\n";
            for (auto& pair : books) {
                s += pair.second.toString() + "\n";
            }
            return s;
        }
};

int main() {
    Library l;
    l.addBook("The Iliad", "Homer", 1324001801);
    l.addBook("Fourth Wing (The Empyrean, 1)", "Rebecca Yarros", 1649374046);
    cout << l.toString();
    l.checkOut(1324001801);
    cout << l.toString();
    l.checkIn(1324001801);
    cout << l.toString();
}