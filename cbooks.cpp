#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Book {
private:
    int number;
    string title;
    string author;
    bool isAvaible;
public:
    void borrowBook() {
        if (isAvaible == true) {
            number -= 1;
            if (number == 0) isAvaible = false;
        }
        else if (!isAvaible) cout << "There is no books remained";
    }
    void returnBook(int n) {
        number += n;
        if (isAvaible == false) isAvaible = true;
    }
    void displayInfo() {
        cout << "The Book - " << title << ", author - " << author << ", remained " << number << " copies";
    }
    void description() {
        cout << "The Book - " << title << ", author - " << author;
    }

    string getTitle() {
        return title;
    }

    bool Avaible() {
        return isAvaible;
    }
};

class User {
private:
    string name;
    vector<Book*> borrowed;
public:
    void borrowB(Book& b) {
        borrowed.push_back(&b);
    }
    void returnB(Book& b) {
        borrowed.erase(remove(borrowed.begin(), borrowed.end(), &b), borrowed.end());
    }
    void displayBorrowed() {
        for (auto &b : borrowed) {
            b-> description();
            cout << endl;
        }
    }
};

class Library {
private:
    vector<Book> books;
    vector<User> users;
public:
    void addBook(const Book& b) {
        books.push_back(b);
    }

    void addUser(const User& usr) {
        users.push_back(usr);
    }

    Book* findBook(const string& title) {
        for (auto& book: books) {
            if (book.getTitle() == title) {
                return &book;
            }
        }
        return nullptr;
    }

    void showAllBooks() {
        for (auto& book: books) {
            book.displayInfo();
            cout << endl;
        }
    }

    void showAvaibleBooks() {
        for (auto& book: books) {
            if (book.Avaible() == true) {
                book.displayInfo();
                cout << endl;
            }
        }
    }
};

int main() {

}












