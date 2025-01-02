#pragma once

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;

public:
    Book(const string& title, const string& author)
        : title(title), author(author) {
    }

    string getTitle() const { return title; }
    string getAuthor() const { return author; }

    bool operator==(const Book& other) const {
        return title == other.title && author == other.author;
    }
};

// Custom hash function specialization
namespace std {
    template <>
    struct hash<Book> {
        size_t operator()(const Book& book) const {
            return hash<string>()(book.getTitle()) ^ (hash<string>()(book.getAuthor()) << 1);
        }
    };
}
