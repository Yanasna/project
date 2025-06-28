#include<iostream>
#include <windows.h>
#include<string>

using namespace std;

void gamefirst(bool& firstTime, string& p_name);
void Hatakeyama(string playername);
void chooseCountry(string p_name);
string nameSet();

void gamefirst(bool& firstTime, string& p_name) {
	p_name = nameSet();
	cout << p_name << "님 환영합니다!";

	firstTime = false;

}

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

void Hatakeyama(string playername) {
	string Nline = "------------------------------------------------------------------------------------------------------------------";
	cout << ".................................................................................................................." << endl;
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------INTRO---------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "[하타케야마 하루토모] : \"우리 가문을 배신한 오기가야츠를 향해 우리는 진격한다! \" " << endl;
	cout << "[오기가야츠 카즈마사] :  \"하하, 너 또한 아버지를 따라 죽게 되리라!\" " << endl;
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "하타케야마 하루토모의 패전으로 하타케야마는 하루토모를 포함한 많은 병사들과 세력들을 잃게 된다. " << endl;
	cout << "[하타케야마 하케카츠] : \" 아버지,,, 제가 꼭 복수를 성공하겠습니다... \" " << endl;
	cout << "{{하타케야마 하케카츠}}가 뒤를  잇는다" << endl;
	cout << Nline << endl;
	cout << Nline << endl;

}

//플레이할 국가 선택
void chooseCountry(string p_name) {
	string playername = p_name;
	int choose;
	string countries[] = { "하타케야마","아카마츠", "사티" };
	int size = sizeof(countries) / sizeof(countries[0]);
	cout << "당신이 플레이할 국가를 선택해주세요" << endl;

	while (true) {
		for (int i = 0; i < size; i++) {
			cout << i << "번 : " << countries[i] << endl;
		}
		cin >> choose;
		switch (choose)
		{
		case 0:
			Hatakeyama(playername);
			return;
			return;
		case 1:
			cout << "제작중입니다! 다시선택하세요!" << endl;
			break;
		case 2:
			cout << "제작중입니다! 다시선택하세요!" << endl;
			break;
		default:
			cout << "제대로 입력하세요!" << endl;
			break;
		}
	}
};

int main(void) {
	static bool firstTime = true;
	static string p_name;

	cout << "게임스타트 !!" << endl;

	gamefirst(firstTime, p_name); //게임 처음플레이할 때 이름입력

	chooseCountry(p_name);

	return 0;
}
