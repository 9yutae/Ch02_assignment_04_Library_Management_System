#pragma once

#include "Book.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BookManager {
private:
    vector<Book> books; // 책 목록 저장

public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author);

    // 모든 책 출력 메서드
    void displayAllBooks() const;

    // 책 제목으로 검색
    void searchByTitle(const string& title) const;

    // 작가 이름으로 검색
    void searchByAuthor(const string& author) const;
};

void BookManager::addBook(const string& title, const string& author) {
    books.push_back(Book(title, author)); // push_back 사용
    cout << "책이 추가되었습니다: " << title << " by " << author << endl;
}

void BookManager::displayAllBooks() const {
    if (books.empty()) {
        cout << "현재 등록된 책이 없습니다." << endl;
        return;
    }

    cout << "\n현재 도서 목록:" << endl;
    for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
        cout << "- " << books[i].title << " by " << books[i].author << endl;
    }
}

void BookManager::searchByTitle(const string& title) const {
    cout << "\n검색 도서 목록 (제목): " << endl;
    auto iter = find_if(books.begin(), books.end(), [title](const Book& curr) { return curr.title == title; });
    if (iter != books.end()) {
        cout << " " << iter->title << " by " << iter->author << endl;
    }
    else cout << "찾으시는 책이 없습니다." << endl;
}

void BookManager::searchByAuthor(const string& author) const {
    cout << "\n검색 도서 목록 (작가): " << endl;
    vector<Book> searchBooks;
    for (const auto& iter : books) { if (iter.author == author) searchBooks.emplace_back(iter); }
    if (!searchBooks.empty()) {
        for (const auto& iter : searchBooks) cout << iter.title << " by " << iter.author << endl;
    }
    else cout << "찾으시는 작가의 책이 없습니다." << endl;
}
