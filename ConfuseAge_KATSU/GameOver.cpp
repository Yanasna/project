#include<iostream>
#include <cstdlib>
#include <windows.h> // Sleep()

using namespace std;

void GameOver_Nomoney() {
	system("cls");
	string text = "이런.. 돈을 다 소모하셨군요,,";
	for (char ch : text) {
		cout << ch ;
		Sleep(100); 
	}
	cout << "파산 엔딩..!" << endl;
	exit(0);
}