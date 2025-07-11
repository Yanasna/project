#include<iostream>
#include <cstdlib>
#include <windows.h> // Sleep()

using namespace std;

void GameOver_Nomoney() {
	system("cls");
	Sleep(2000);

	string text = ". . . . . . .";
	string text1 = "이런.. 돈을 다 소모하셨군요,,";
	string text2 = "파산하셨습니다....";
	string text3 = "파 산 엔 딩!";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	for (char ch : text) {
		cout << ch;
		Sleep(100);
	}
	cout << endl;
	for (char ch : text1) {
		cout << ch ;
		Sleep(100); 
	}
	cout << endl;
	for (char ch : text2) {
		cout << ch;
		Sleep(100);
	}
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	for (char ch : text3) {
		cout << ch;
		Sleep(100);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	exit(0);
}