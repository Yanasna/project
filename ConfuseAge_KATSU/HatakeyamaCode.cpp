#include<iostream>
#include <cstdlib>
#include <conio.h> // _getch()
#include <windows.h> // Sleep()

using namespace std;

void agriculture();
void Income();
void Time();
void Story();


static bool first = true;


void Story() {
	string Nline = "------------------------------------------------------------------------------------------------------------------";

	while (first) {
		cout << ".................................................................................................................." << endl;
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "--------------------------------------------------INTRO---------------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "[하타케야마 하루토모] : \"우리 가문을 배신한 오기가야츠를 향해 우리는 진격한다! \" " << endl;
		cout << "[오기가야츠 카즈마사] :  \"하하, 너 또한 아버지를 따라 죽게 되리라!\" " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		Sleep(200);
		cout << "하타케야마 하루토모의 패전으로 하타케야마는 하루토모를 포함한 많은 병사들과 세력들을 잃게 된다. " << endl;
		Sleep(200);
		cout << "{{하타케야마 하루토모}}가 전사했습니다." << endl;
		Sleep(200);
		cout << "{{하타케야마 하루타카}}가 전사했습니다." << endl;
		Sleep(200);
		cout << "{{와타나베 치카츠에}}가 전사했습니다." << endl;
		Sleep(200);
		cout << "{{히라카미 요케츠}}가 전사했습니다." << endl;
		Sleep(200);
		cout << "[와타나베]가문이 독립했습니다!" << endl;
		Sleep(200);
		cout << "........" << endl;
		cout << "[하타케야마 하케카츠] : \" 아버지,,, 제가 꼭 복수를 성공하겠습니다... \" " << endl;
		Sleep(100);
		cout << "{{하타케야마 하케카츠}}가 하타케야마의 왕이 되었다." << endl;
		cout << Nline << endl;
		cout << Nline << endl;
		first = false;
	}


}

void Hatakeyama() {
	system("cls");
	string Nline = "------------------------------------------------------------------------------------------------------------------";

	Story();

	string menu[] = { "[농업]","[상업]", "[병영]", "[세력정보]", "[출전]", "[저장]"};
	int size = sizeof(menu) / sizeof(menu[0]);

	bool running = true;
	int position = 0;

	cout << "하타케야마 가문" << endl;
	cout << "왕 - 하타케야마 하케카츠" << endl;
	Time();
	Income();
	cout << "===============게임 메뉴==============" << endl;
	for (int i = 0; i < size; i++) {
		cout << menu[i] << (position == i ? "<" : " ") << "    ";
	}
	

	while (running) {
		int key = _getch(); // 키 입력 대기
		
		
		if (key == 224) { // 방향키는 2단계로 입력됨
			int arrow = _getch();
			if (arrow == 75) { // ←
				if (position > 0) position--;
			}
			else if (arrow == 77) { // →
				if (position < 5) position++;
			}
		}
		else if (key == 13) { // Enter 키
			switch (position) {
				
				case 0 :
					system("cls");
					cout << "우리는 농업에 투자한다!" << endl;
					Sleep(1000);
					agriculture();
					break;
				case 1 : 
					system("cls");
					cout << "우리는 상업에 투자한다!" << endl;
					Sleep(1000);
					break;
				case 2 : 
					system("cls");
					cout << "우리는 병영에 투자한다!" << endl;
					Sleep(1000);
					break;
				case 3:
					system("cls");
					cout << "세력정보를 관람한다!" << endl;
					Sleep(1000);
					break;
				case 4:
					system("cls");
					cout << "출전한다!!!" << endl;
					Sleep(1000);
					break;
				case 5:
					system("cls");
					cout << "저장한다!" << endl;
					Sleep(1000);
					break;
			}
		}
		system("cls");
		cout << "하타케야마 가문" << endl;
		cout << "왕 - 하타케야마 하케카츠" << endl;
		Time();
		Income();
		cout << "===============게임 메뉴==============" << endl;
		for (int i = 0; i < size; i++) {
			cout << menu[i] << (position == i ? "<" : " ") << "    ";
		}
	}
}