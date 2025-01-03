#include "Book.h"
#include "BookManager.h"
#include "BorrowManager.h"

int main() {
    BookManager bookManager;
    BorrowManager borrowManager;

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 검색" << endl; // 책 검색
        cout << "4. 대여" << endl; // 책 대여 기능 추가 
        cout << "5. 종료" << endl; // 프로그램 종료
        cout << "선택: ";

        string choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if (choice == "1") {
            // 1번 선택: 책 추가
            // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
            string title, author;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)
            bookManager.addBook(title, author); // 입력받은 책 정보를 추가
            borrowManager.initalizeStock(Book(title, author)); // 재고 추가
        }
        else if (choice == "2") {
            // 2번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            bookManager.displayAllBooks();
        }
        else if (choice == "3") {
            // 3번 선택: 책 검색
            // 검색 방법 선택
            cout << "검색 옵션을 선택하세요: 1) 제목으로 검색, 2) 작가로 검색" << endl;
            string searchOption;
            cin >> searchOption;

            string keyword;
            cin.ignore();

            if (searchOption == "1") { // 제목으로 검색
                cout << "책 제목을 입력하세요 : ";
                getline(cin, keyword);
                bookManager.searchByTitle(keyword);
            }
            else if (searchOption == "2") { // 작가 이름으로 검색
                cout << "작가를 입력하세요 : ";
                getline(cin, keyword);
                bookManager.searchByAuthor(keyword);
            }
            else {
                cout << "잘못된 입력입니다." << endl;
            }
        }
        else if (choice == "4") {
            // 4번 선택: 책 대여
            // 대여 가능 여부 확인 및 대여/반납 진행
            cout << "\n도서 대여" << endl;
            cout << "1. 현재 도서 재고" << endl;
            cout << "2. 도서 대여" << endl;
            cout << "3. 도서 반납" << endl;
            cout << "선택: ";

            string borrowType;
            cin >> borrowType;

            // 현재 도서 재고
            if (borrowType == "1") { 
                borrowManager.displayStock();
            }
            else if (borrowType == "2") {  // 대여 절차
                cout << "검색 옵션을 선택하세요: 1) 제목으로 검색, 2) 작가로 검색" << endl;
                string searchOption;
                cin >> searchOption;

                string keyword;
                cin.ignore();
                if (searchOption == "1") {  // 책 제목으로 대여
                    cout << "책 제목을 입력하세요 : ";
                    getline(cin, keyword);
                    if (bookManager.getBookByTitle(keyword)) borrowManager.borrowBook(bookManager.findBookByTitle(keyword));
                    else cout << "잘못된 입력입니다." << endl;
                }
                else if (searchOption == "2") {  // 작가 이름으로 대여
                    cout << "작가를 입력하세요 : ";
                    getline(cin, keyword);
                    if (bookManager.getBookByAuthor(keyword)) borrowManager.borrowBook(bookManager.findBookByAuthor(keyword));
                    else cout << "잘못된 입력입니다." << endl;
                }
                else cout << "잘못된 입력입니다." << endl;
            }
            else if (borrowType == "3") {  // 반납 절차
                cout << "검색 옵션을 선택하세요: 1) 제목으로 검색, 2) 작가로 검색" << endl;
                string searchOption;
                cin >> searchOption;

                string keyword;
                cin.ignore();
                if (searchOption == "1") {
                    cout << "책 제목을 입력하세요 : ";
                    getline(cin, keyword);
                    if (bookManager.getBookByTitle(keyword)) borrowManager.returnBook(bookManager.findBookByTitle(keyword));
                    else cout << "잘못된 입력입니다." << endl;
                }
                else if (searchOption == "2") {
                    cout << "작가를 입력하세요 : ";
                    getline(cin, keyword);
                    if (bookManager.getBookByAuthor(keyword)) borrowManager.returnBook(bookManager.findBookByAuthor(keyword));
                    else cout << "잘못된 입력입니다." << endl;
                }
                else cout << "잘못된 입력입니다." << endl;
            }
        }
        else if (choice == "5") {
            // 4번 선택: 종료
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        }
        else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0; // 프로그램 정상 종료
}
