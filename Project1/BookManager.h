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

    // 필수 기능
    // 책 제목으로 검색
    void searchByTitle(const string& title) const;
    // 작가 이름으로 검색
    void searchByAuthor(const string& author) const;

    // 도전 기능
    vector<Book> findBookByTitle(const string& title);
    vector<Book> findBookByAuthor(const string& author);
    const Book* getBookByTitle(const string& title) const;
    const Book* getBookByAuthor(const string& author) const;
};

// 책 추가 메서드
void BookManager::addBook(const string& title, const string& author) {
    books.push_back(Book(title, author)); // push_back 사용
    cout << "책이 추가되었습니다: " << title << " by " << author << endl;
}

// 모든 책 출력
void BookManager::displayAllBooks() const {
    if (books.empty()) {
        cout << "현재 등록된 책이 없습니다." << endl;
        return;
    }

    cout << "\n현재 도서 목록:" << endl;
    for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
        cout << "- " << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
    }
}

// 제목으로 책 검색 (출력)
void BookManager::searchByTitle(const string& title) const {
    cout << "\n검색 도서 목록 (제목): " << endl;
    vector<Book> searchBooks;
    for (const auto& iter : books) {
        if (iter.getTitle() == title) searchBooks.emplace_back(iter);
    }
    if (!searchBooks.empty()) {
        for (const auto& iter : searchBooks) cout << iter.getTitle() << " by " << iter.getAuthor() << endl;
    }
    else cout << "찾으시는 책이 없습니다." << endl;
}

// 작가 이름으로 책 검색 (출력)
void BookManager::searchByAuthor(const string& author) const {
    cout << "\n검색 도서 목록 (작가): " << endl;
    vector<Book> searchBooks;
    for (const auto& iter : books) {
        if (iter.getAuthor() == author) searchBooks.emplace_back(iter);
    }
    if (!searchBooks.empty()) {
        for (const auto& iter : searchBooks) cout << iter.getTitle() << " by " << iter.getAuthor() << endl;
    }
    else cout << "찾으시는 작가의 책이 없습니다." << endl;
}

// 해당 제목의 도서 목록 반환
vector<Book> BookManager::findBookByTitle(const string& title) {
    vector<Book> fBooks;
    for (const auto& iter : books) {
        if (iter.getTitle() == title) fBooks.emplace_back(iter);
    }
    return fBooks;
}

// 해당 작가의 도서 목록 반환
vector<Book> BookManager::findBookByAuthor(const string& author) {
    vector<Book> fBooks;
    for (const auto& iter : books) {
        if (iter.getAuthor() == author) fBooks.emplace_back(iter);
    }
    return fBooks;
}

const Book* BookManager::getBookByTitle(const string& title) const {
    for (const auto& iter : books) {
        if (iter.getTitle() == title) return &iter;
    }
    return nullptr;
}

const Book* BookManager::getBookByAuthor(const string& author) const {
    for (const auto& iter : books) {
        if (iter.getAuthor() == author) return &iter;
    }
    return nullptr;
}
