#pragma once

#include "Book.h"
#include <iostream>
#include <unordered_map>

class BorrowManager {
private:
	unordered_map<Book, int> stock;

public:
	void initalizeStock(Book book, int quantity = 3);
	void borrowBook(vector<Book> books);
	void returnBook(vector<Book> books);
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
void BorrowManager::borrowBook(vector<Book> books) {
	int idx = 0;
	while (true) {
		if (books.size() != 1) {
			idx = 0;
			cout << "다음 도서 중 하나를 선택하세요." << endl;
			for (const auto& w : books) cout << idx++ << ". " << w.getTitle() << "(" << w.getAuthor() << "): " << stock[w] << "권" << endl;
			cin >> idx;
		}
		if (idx >= 0 && idx < books.size()) break;
		else cout << "다시 선택하세요." << endl;
	}


	if (stock[books[idx]] > 0) {
		stock[books[idx]]--;
		cout << books[idx].getTitle() << "(" << books[idx].getAuthor() << ")을(를) 대여하였습니다." << endl;
		cout << "남은 재고: " << stock[books[idx]] << "권" << endl;
	}
	else cout << books[idx].getTitle() << "(" << books[idx].getAuthor() << ")이(가) 현재 모두 대여 중입니다." << endl;
}

// 책 반납
void BorrowManager::returnBook(vector<Book> books) {
	int idx = 0;
	while (true) {
		idx = 0;
		if (books.size() != 1) {
			cout << "다음 도서 중 하나를 선택하세요." << endl;
			for (const auto& w : books) cout << idx++ << ". " << w.getTitle() << "(" << w.getAuthor() << "): " << stock[w] << "권" << endl;
			cin >> idx;
		}
		if (idx >= 0 && idx < books.size()) break;
		else cout << "다시 선택하세요." << endl;
	}

	if (stock[books[idx]] < 3) {
		stock[books[idx]]++;
		cout << books[idx].getTitle() << "(" << books[idx].getAuthor() << ")을(를) 반납하였습니다." << endl;
		cout << "남은 재고: " << stock[books[idx]] << "권" << endl;
	}
	else cout << "대여 중인 " << books[idx].getTitle() << "(" << books[idx].getAuthor() << ")이(가) 없습니다." << endl;
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
