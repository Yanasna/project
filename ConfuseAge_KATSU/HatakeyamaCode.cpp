#include<iostream>
#include <cstdlib>
#include <conio.h> // _getch()
#include <windows.h> // Sleep()

using namespace std;

void first_Explain();
void Story();
void agriculture();
void commerce();
void soldier();
void showProfile();
void Income();
void Time();
void Event();
void Turn();
void attack_();

static bool first = true;
static string Nline = "------------------------------------------------------------------------------------------------------------------";

void Story() {
	while (first) {
		cout << ".................................................................................................................." << endl;
		cout << Nline << endl;
		cout << Nline << endl;
		cout << "--------------------------------------------------INTRO---------------------------------------------------------" << endl;
		cout << Nline << endl;
		cout << Nline << endl;
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

void first_Explain() {
	cout << Nline << endl;
	cout << "간단한 설명 : " << endl;
	cout << Nline << endl;
	cout << "농업, 상업 - 증가시 수입 증가" << endl;
	cout << "병력이 많아질수록 수입 감소" << endl;
	cout << "세력정보 - 자신의 세력과 상대의 세력을 관람한다." << endl;
	cout << "출전 - 1부터 10까지의 숫자를 뽑아서 5 밑으로 숫자를 가져갈시 플레이어 선공" << endl;
	cout << "5위로 숫자를 상대가 가져갈시 상대가 선공" << endl;
	cout << "무작위의 장군들이 나와서 무력에 비례한 피해를 입힌다." << endl;
	cout << "상대를 박살낼 시 해당 성 점거." << endl;
	cout << "어떤 가문의 성 전부 점령 시 장수 죽이거나 포섭 가능" << endl;
}

void Hatakeyama() {
	system("cls");

	Story();
	first_Explain();

	string menu[] = { "[농업]","[상업]", "[병영]", "[세력정보]", "[출전]", "[저장]", "[게임설명]", "[턴을 넘긴다]"};
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
				if (position < 7) position++;
			}
		}
		else if (key == 13) { // Enter 키
			switch (position) {

			case 0:
				system("cls");
				cout << "우리는 농업에 투자한다!" << endl;
				Sleep(1000);
				agriculture();
				break;
			case 1:
				system("cls");
				cout << "우리는 상업에 투자한다!" << endl;
				Sleep(1000);
				commerce();
				break;
			case 2:
				system("cls");
				cout << "우리는 병영에 투자한다!" << endl;
				Sleep(1000);
				soldier();
				break;
			case 3:
				system("cls");
				cout << "세력정보를 관람한다!" << endl;
				Sleep(1000);
				showProfile();
				break;
			case 4:
				system("cls");
				cout << "출전한다!!!" << endl;
				Sleep(1000);
				attack_();
				break;
			case 5:
				system("cls");
				cout << "저장한다!" << endl;
				Sleep(1000);
				break;
			case 6:
				system("cls");
				cout << "설명을 보겠어!" << endl;
				Sleep(1000);
				first_Explain();
				Sleep(7000);
				break;
			case 7 : 
				system("cls");
				cout << "이번에는 좀 쉬겠어." << endl;
				Sleep(1000);
				Turn();
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