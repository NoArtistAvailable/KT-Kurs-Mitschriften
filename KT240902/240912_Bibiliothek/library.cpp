#include "library.h"
#include <iostream>

using namespace std;

void showLibrary(Book books[], int bookCount, User users[], int userCount) {
	cout << "Bibiliotheksverwaltung gestartet.\n\n"
		<< "Anzahl der Buecher: " << bookCount
		<< "Anzahl der Benutzer " << userCount
		<< endl;

	//int c = sizeof(books) / sizeof(books[0]);
	for (int i = 0; i < bookCount; i++) {
		cout << "\n";
		showBook(books[i]);
	}
	//c = sizeof(users) / sizeof(users[0]);
	for (int i = 0; i < userCount; i++) {
		cout << "\n";
		showUser(users[i]);
	}
}