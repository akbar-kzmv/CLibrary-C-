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
    string username;
    string password;
    vector<Book*> borrowed;
public:
    User(string username, string password)
        : username(username), password(password) {}

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
    string getName() const{
        return username;
    }

    string getPass() const {
        return password;
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

    bool addUser(const User& usr) {
        if (usrExists(usr.getName()) == true) {
            cout << "User already exists! Please login!\n";
            return false;
        }
        users.push_back(usr);
        cout << "User successfully added!\n";
        return true;
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

    bool usrExists(const string& username) {
        for (auto& u: users) {
            if (u.getName() == username) {
                return true;
            }
        }
        return false;
    }

    bool findUser(const string& username) {
        for (auto& u: users) {
            if (u.getName() == username) {
                return true;
            }
        }
        return false;
    }

    bool checkPass(const string& password) {
        for (auto& u: users) {
            if (u.getPass() == password) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int menu;
    bool oncer = false, forv = true;
    Library lib;
    cout << "Hello! Welcome to our CLibrary. Choose your next action\n1 - Register\n2 - Login\n";
    cin >> menu;
    while (forv) {
        if (oncer == true) {
            cout << "1 - Register\n2 - Login" << endl;
            cin >> menu;
        }
        if (menu == 1) {
            User usr("", "");
            string username, password;
            cout << "Create an account" << endl;
            cout << "Enter your username:";
            cin >> username;
            cout << "Set a password:";
            cin >> password;
            usr = User(username, password);
            lib.addUser(usr);
            oncer = true;

        } else if (menu == 2) {
            User usr("", "");
            string username, password = "";
            cout << "Enter your username:";
            cin >> username;

            if (lib.findUser(username) == true) {
                while (lib.checkPass(password) != true) {
                    cout << "Enter password:";
                    cin >> password;
                    if (lib.checkPass(password) == true) {
                        cout << "Login successful\n";
                        forv = false;
                    } else {
                        cout << "Wrong password!\n";
                    }
                }
            } else {
                cout << "User not found! Please register!\n";
                cout << "1 - Register\n2 - Login" << endl;
                cin >> menu;
            }

        }
    }
}