#include<iostream>
#include <windows.h>
#include<string>
#include <cstdlib>
#include <conio.h>

using namespace std;


void gamefirst(bool& firstTime, string& p_name);
void Hatakeyama();

string nameSet();

void gamefirst(bool& firstTime, string& p_name) {
	p_name = nameSet();
	cout << p_name << "님 환영합니다!";

	firstTime = false;

}
//이름 입력 >> 입력으로 json에 데이터 저장, 불러오기
string nameSet() {
	cout << "당신의 이름은 무엇입니까?";
	cout << endl;

	string name;
	int nameInt;

	cin >> name;
	cout << "당신의 이름은 " << name << "!" << endl;
	cout << "예 -> 1 아니오 -> 2" << endl;
	cin >> nameInt;

	if (nameInt == 2) {
		return nameSet();
	}

	else if (nameInt == 1) {
		return name;
	}
	else {
		cout << "다시입력해주세요!" << endl;
		return nameSet();
	}
}
void chooseCountry() {
	string countries[] = { "하타케야마","아카마츠", "사티" };
	int size = sizeof(countries) / sizeof(countries[0]);
	cout << "당신이 플레이할 국가를 선택해주세요" << endl;
	int position = 0;
	cout << "======= 국가 선택 =======" << endl;
	for (int i = 0; i < size; i++) {
		cout << countries[i] << (position == i ? "< " : "  ") << "    ";
	}


	bool running = true;

	while (running) {

		int country_key = _getch();
		if (country_key == 224) { // 방향키는 2단계로 입력됨
			int arrow = _getch();
			if (arrow == 75) { // ←
				if (position > 0)
					position--;
			}
			else if (arrow == 77) { // →
				if (position < size)
					position++;
			}
		}
		else if (country_key == 13) { // Enter 키
			system("cls");
			switch (position) {
			case 0:
				Hatakeyama();
				running = false;
				break;
			case 1:
			case 2:
				cout << "제작중입니다! 다시 선택하세요!" << endl;
				Sleep(1000);
				break;
			}

		}
		system("cls");
		cout << "======= 국가 선택 =======" << endl;
		for (int i = 0; i < size; i++) {
			cout << countries[i] << (position == i ? "< " : "  ") << "    ";
		}
	}
}

int main(void) {
	static bool firstTime = true;
	static string p_name;

	cout << "게임스타트 !!" << endl;

	gamefirst(firstTime, p_name); //게임 처음플레이할 때 이름입력

	chooseCountry();
}
