#pragma once

#include "Book.h"
#include <iostream>
#include <unordered_map>

class BorrowManager {
private:
	unordered_map<Book, int> stock;

public:
	void initalizeStock(Book book, int quantity = 3);
	void borrowBook(const Book& title);
	void returnBook(const Book& title);
	void displayStock();
};

// 새로운 책 재고 설정
void BorrowManager::initalizeStock(Book book, int quantity) {
	if (stock.find(book) == stock.end()) {
		stock.insert(make_pair(book, quantity));
	}
	else cout << "이미 등록된 책입니다." << endl;
}

// 책 대여
void BorrowManager::borrowBook(const Book& book) {
	if (stock.find(book) != stock.end()) {
		if (stock[book] > 0) {
			stock[book]--;
			cout << book.getTitle() << "(" << book.getAuthor() << ")을(를) 대여하였습니다." << endl;
			cout << "남은 재고: " << stock[book] << "권" << endl;
		}
		else cout << book.getTitle() << "(" << book.getAuthor() << ")이(가) 현재 모두 대여 중입니다." << endl;
	}
	else cout << "등록되지 않은 도서입니다." << endl;
}

// 책 반납
void BorrowManager::returnBook(const Book& book) {
	if (stock.find(book) != stock.end()) {
		if (stock[book] < 3) {
			stock[book]++;
			cout << book.getTitle() << "(" << book.getAuthor() << ")을(를) 반납하였습니다." << endl;
			cout << "남은 재고: " << stock[book] << "권" << endl;
		}
		else cout << book.getTitle() << "(" << book.getAuthor() << ")이(가) 대여 중이 아닙니다." << endl;
	}
	else cout << "등록되지 않은 도서입니다." << endl;
}

// 도서 재고 현황
void BorrowManager::displayStock() {
	cout << "도서 재고 현황" << endl;
	if (!stock.empty()) {
		for (const auto& w : stock)
			cout << "- " << w.first.getTitle() << "(" << w.first.getAuthor() << "): " << w.second << "권\n";
	}
	else cout << "현재 등록된 책이 없습니다." << endl;
}
