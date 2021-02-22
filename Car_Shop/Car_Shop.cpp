#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include <vector>

using namespace std;


struct Auto {
	string mark;
	int price;
	string color;
};
Auto A[100];

void storeAuto() {
	A[0].mark = "Lambo";
	A[0].price = 500;
	A[0].color = "red";

	A[1].mark = "Bugatti";
	A[1].price = 5000;
	A[1].color = "green";
	string s, find = "Lambo";
	ifstream file("file.txt");

	for (int i = 0; i < 1; i++)
		getline(file, s);

	if (find != s) {
		file.close();
		ofstream file;
		file.open("file.txt", ios_base::app);

		for (int i = 0; i < 2; i++) {
			file << A[i].mark << endl
				<< A[i].price << endl
				<< A[i].color << endl;
		}
		file.close();
	}
}

void Draw() {
	HANDLE hCon;
	COORD cPos;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 10; i++) {
		cPos.Y = i;
		cPos.X = 30;
		SetConsoleCursorPosition(hCon, cPos);
		cout << "*" << endl;
	}
}

void Drawing() {
	HANDLE hCon;
	COORD cPos;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	cPos.Y = 2;
	cPos.X = 40;
	SetConsoleCursorPosition(hCon, cPos);
	cout << " /\\" << "  |)" << "  _ " << "/ \\" << endl;
	cPos.Y = 3;
	cPos.X = 40;
	SetConsoleCursorPosition(hCon, cPos);
	cout << "/--\\" << " |)" << "  | " << "\\ / " << endl;
	cPos.Y = 5;
	cPos.X = 39;
	SetConsoleCursorPosition(hCon, cPos);
	cout << " /   " << "/\\  " << " /\\ " << " / \\" << " |_|" << endl;
	cPos.Y = 6;
	cPos.X = 39;
	SetConsoleCursorPosition(hCon, cPos);
	cout << " \\  " << "/--\\ " << "/  \\ " << "\\ / " << "| |" << endl;

}
void DrawFail() {
	HANDLE hCon;
	COORD cPos;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	cPos.Y = 1;
	cPos.X = 36;
	SetConsoleCursorPosition(hCon, cPos);
	cout << "  _ " << endl;
	cPos.Y = 2;
	cPos.X = 36;
	SetConsoleCursorPosition(hCon, cPos);
	cout << " |-  " << "/\\" << "   | " << "|  " << "    ()" << "/ " << "/ " << endl;
	cPos.Y = 3;
	cPos.X = 36;
	SetConsoleCursorPosition(hCon, cPos);
	cout << " |  " << "/--\\" << "  | " << "|_ " << "    ()" << "\\ " << "\\ " << endl;
}

class CursorPos {
public:
	void PosError() {
		HANDLE hCon;
		COORD cPos;
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		cPos.Y = 16;
		cPos.X = 2;
		SetConsoleCursorPosition(hCon, cPos);
	}
public:
	void Pos() {
		HANDLE hCon;
		COORD cPos;
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		cPos.Y = 1;
		cPos.X = 12;
		SetConsoleCursorPosition(hCon, cPos);
	}
};

class cMenu {
	CursorPos CursorPos;

public:
	void ByMarks() {
		system("cls");
		string s, find;
		int k = 0; 	int i = 0;

		ifstream file("file.txt");

		for (int i = 0; i < 30; i++) {
			cout << "#";
		}

		cout << endl << "Enter mark: ";

		Draw();

		for (int i = 0; i < 30; i++) {
			cout << "#";
		}
		cout << "*" << endl;

		Drawing();

		HANDLE hCon;
		COORD cPos;
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		cPos.Y = 1;
		cPos.X = 12;
		SetConsoleCursorPosition(hCon, cPos);

		cin >> find;

		while (find != s) {
			getline(file, s);
			k++;
		}
		vector <string> L;

		file.seekg(0);
		for (int i = 0; i < 2; i++) {
			while (getline(file, s)) {
				L.push_back(s);
				i++;
			}
			cout << endl;
			cout << " Mark: " << L[i = k - 1] << endl;
			cout << " Price: " << L[i = k] << endl;
			cout << " Color: " << L[i = k + 1] << endl;
		}
		cout << endl;
		cout << " 1 Search more " << endl
			<< " 9 Back" << endl;

		file.close();

		cin >> i;
		switch (i) {
		case 1: ByMarks(); break;
		case 9:return; break;

		}
	}

public:
	void ByPrices() {
		system("cls");
		string s, find;
		int k = 0; 	int i = 0;;
		ifstream file("file.txt");

		for (int i = 0; i < 30; i++) {
			cout << "#";
		}

		cout << endl << "Enter price: ";
		Draw();
		Drawing();
		cout << endl << endl;
		for (int i = 0; i < 30; i++) {
			cout << "#";
		}
		cout << "*" << endl;

		HANDLE hCon;
		COORD cPos;
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		cPos.Y = 1;
		cPos.X = 12;
		SetConsoleCursorPosition(hCon, cPos);

		cin >> find;

		while (find != s) {
			getline(file, s);
			k++;
		}
		vector <string> L;

		file.seekg(0);
		for (int i = 0; i < 2; i++) {
			while (getline(file, s)) {
				L.push_back(s);
				i++;
			}
			cout << endl;
			cout << " Mark: " << L[i = k - 2] << endl;
			cout << " Price: " << L[i = k - 1] << endl;
			cout << " Color: " << L[i = k] << endl;
		}

		cout << endl;
		cout << " 1 Search more " << endl
			<< " 9 Back" << endl;

		cin >> i;

		switch (i) {
		case 1: ByPrices(); break;
		case 9:return; break;

			file.close();
		}
	}

public:
	void ByColors() {
		system("cls");
		string s, find;
		int k = 0; 	int i = 0;

		ifstream file("file.txt");

		for (int i = 0; i < 30; i++) {
			cout << "#";
		}

		cout << endl << "Enter color: ";

		Draw();
		Drawing();
		cout << endl << endl;
		for (int i = 0; i < 30; i++) {
			cout << "#";
		}
		cout << "*" << endl;

		HANDLE hCon;
		COORD cPos;
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		cPos.Y = 1;
		cPos.X = 12;
		SetConsoleCursorPosition(hCon, cPos);

		cin >> find;

		while (find != s) {
			getline(file, s);
			k++;
		}

		vector <string> L;

		file.seekg(0);
		for (int i = 0; i < 2; i++) {
			while (getline(file, s)) {
				L.push_back(s);
				i++;
			}
			cout << endl;
			cout << " Mark: " << L[i = k - 3] << endl;
			cout << " Price: " << L[i = k - 2] << endl;
			cout << " Color: " << L[i = k - 1] << endl;

		}
		cout << endl;
		cout << " 1 Search more " << endl
			<< " 9 Back" << endl;

		cin >> i;
		switch (i) {
		case 1: ByColors(); break;
		case 9:return; break;
			file.close();
		}
		CursorPos.PosError();
		file.close();
	}

public:
	void addData() {
		system("cls");
		enum aMenu { AddMore = 1 };
		int i;

		for (int i = 0; i < 30; i++) {
			cout << "#";
		}

		cout << endl;
		cout << " Enter mark: ";
		Draw();

		for (int i = 0; i < 30; i++) {
			cout << "#";
		}
		Drawing();
		CursorPos.Pos();

		cin >> A[2].mark;
		cout << " Enter price: "; cin >> A[2].price;
		cout << " Enter color: "; cin >> A[2].color;

		ofstream file;
		file.open("file.txt", ios_base::app);
		file << A[2].mark << endl
			<< A[2].price << endl
			<< A[2].color << endl;

		file.close();

		cout << endl;
		cout << "1 Add more" << endl;
		cout << "0 Exit" << endl;

		HANDLE hCon;
		COORD cPos;
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		cPos.Y = 7;
		cPos.X = 1;
		SetConsoleCursorPosition(hCon, cPos);

		cin >> i;
		switch (i) {
		case AddMore: addData(); break;
		case 0:CursorPos.PosError(); break;
		}
	}

public:
	void ViewPrice() {
		system("cls");
		char readfile[50];
		ifstream file("file.txt");

		for (int i = 0; i < 30; i++) {
			cout << "#";
		}

		for (; !file.eof(); ) {

			cout << endl;
			file.getline(readfile, 50);
			cout << "   Mark: " << readfile << "                  *" << endl;

			file.getline(readfile, 50);
			cout << "   Price: " << readfile << "                  *" << endl;

			file.getline(readfile, 50);
			cout << "   Color: " << readfile << "                  *" << endl;
			cout << "******************************" << endl;

		}

		for (int i = 0; i < 30; i++) {
			cout << "#";
		}

		Drawing();

		HANDLE hCon;
		COORD cPos;
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		cPos.Y = 20;
		cPos.X = 3;
		SetConsoleCursorPosition(hCon, cPos);

		file.close();
		_getch();

		cPos.Y = 100;
		cPos.X = 3;
		SetConsoleCursorPosition(hCon, cPos);
	}

public:
	void SearchAuto() {
		for (;;) {
			system("cls");
			string s;
			char c;
			int i;

			ifstream file("file.txt");

			while (!file.eof()) {
				file.get(c);
				s.push_back(c);
			}
			file.close();

			enum smenu { ByMark = 1, ByPrice, ByColor, Back = 9 };
			smenu z;

			for (int i = 0; i < 30; i++) {
				cout << "#";
			}

			cout << endl << " 1 By mark" << endl
				<< " 2 By price" << endl
				<< " 3 By color" << endl << endl
				<< " 9 Back" << endl
				<< " 0 Exit" << endl;

			Draw();

			for (int i = 0; i < 30; i++) {
				cout << "#";
			}

			cout << "*" << endl;
			Drawing();
			HANDLE hCon;
			COORD cPos;
			hCon = GetStdHandle(STD_OUTPUT_HANDLE);
			cPos.Y = 7;
			cPos.X = 1;
			SetConsoleCursorPosition(hCon, cPos);

			cin >> i;

			if (i == 1 || i == 2 || i == 3 || i == 4 || i == 0 || i == 9) {
				switch (i) {
				case ByMark: ByMarks(); break;
				case ByPrice: ByPrices(); break;
				case ByColor: ByColors(); break;
				case 0:CursorPos.PosError(); return; break;
				case Back: return; break;
				}
			}
			else {
				cout << endl << "Smory chto vvodish!!" << endl;
				Sleep(1000);
			}
		}

	}

public:
	void DelAuto() {
		system("cls");
		string s;
		string find;
		int k = 0;
		int i = 0;;

		ifstream file("file.txt");

		for (int i = 0; i < 30; i++) {
			cout << "#";
		}

		cout << endl << "Enter mark: ";

		Draw();

		for (int i = 0; i < 30; i++) {
			cout << "#";
		}
		cout << "*" << endl;

		HANDLE hCon;
		COORD cPos;
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		cPos.Y = 1;
		cPos.X = 12;
		SetConsoleCursorPosition(hCon, cPos);

		cin >> find;
		DrawFail();

		int size = 0;
		while (find != s) {
			getline(file, s);
			k++;
		}

		file.seekg(0);
		string L[100];
		while (!file.eof()) {
			getline(file, s);
			L[i] = s;
			i++;
			size++;
		}
		file.seekg(0);
		file.close();

		ofstream fil;
		fil.open("file.txt");

		file.seekg(0);
		for (int i = 0; i < 10; i++) {

			if (i != k - 1 && i != k && i != k + 1) {
				fil << L[i] << endl;
			}

		}
		cout << endl;

		CursorPos.PosError();
		fil.close();
		_getch();
	}

};


void menu() {
	for (;;) {
		system("cls");
		CursorPos CursorPos;
		cMenu cMenu; int i;
		enum emenu { InsData = 1, ViewPrice, SearchAuto, DelAuto };
		for (int i = 0; i < 30; i++) {
			cout << "#";
		}

		cout << endl
			<< " 1 Add data" << endl
			<< " 2 View price" << endl
			<< " 3 Search Auto" << endl
			<< " 4 Delete Auto" << endl << endl
			<< " 0 Exit" << endl
			<< endl;

		Draw();

		for (int i = 0; i < 30; i++) {
			cout << "#";
		}
		cout << "*" << endl;

		Drawing();

		HANDLE hCon;
		COORD cPos;
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		cPos.Y = 7;
		cPos.X = 1;
		SetConsoleCursorPosition(hCon, cPos);

		cin >> i;

		if (i == 1 || i == 2 || i == 3 || i == 4 || i == 0) {
			switch (i) {
			case InsData: cMenu.addData(); break;
			case ViewPrice: cMenu.ViewPrice(); break;
			case SearchAuto: cMenu.SearchAuto(); break;
			case DelAuto: cMenu.DelAuto(); break;
			case 0:CursorPos.PosError(); return; break;
			}
		}
		else {
			cout << endl << "Smory chto vvodish!!" << endl;
			Sleep(1000);
		}
	}
}


int main() {
	storeAuto();
	menu();
	return 0;
}
