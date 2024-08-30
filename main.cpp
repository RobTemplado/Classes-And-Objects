#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    int year;

    Book(string a, string b, int c) {
        title = a;
        author = b;
        year = c;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        string title, author;
        int year;
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter year: ";
        cin >> year;
        books.push_back(Book(title, author, year));
        cout << "Book added successfully!" << endl;
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books in the library." << endl;
        } else {
            cout << "Book List:" << endl;
            for (Book &book : books) {
                cout << "Title: " << book.title << ", Author: " << book.author << ", Year: " << book.year << endl;
            }
        }
    }

    void searchBook() {
        string searchTitle;
        cout << "Enter a book to search: ";
        cin.ignore();
        getline(cin, searchTitle);

        for (Book &book : books) {
            if (book.title == searchTitle) {
                cout << "Book found!" << endl;
                cout << "Title: " << book.title << ", Author: " << book.author << ", Year: " << book.year << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\nMenu" << endl;
        cout << "1 - Add Book" << endl;
        cout << "2 - Display Books" << endl;
        cout << "3 - Search Book" << endl;
        cout << "4 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            library.addBook();
            break;
        case 2:
            library.displayBooks();
            break;
        case 3:
            library.searchBook();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
