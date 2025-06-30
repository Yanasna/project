#include<iostream>
#include <cstdlib>
#include <conio.h> // _getch()
#include <windows.h> // Sleep()
#include <fstream>
#include <nlohmann/json.hpp> // nlohmann::json 라이브러리

using json = nlohmann::json;
using namespace std;

void agriculture() {
    try {
        cout << " DataLoader 시작" << endl;
        ifstream file("../../ConfuseAge_KATSU/LoginData.json");
        if (!file.is_open()) {
            cerr << "파일 열기 실패!" << endl;
            return;
        }

        stringstream buffer;
        buffer << file.rdbuf();  // 전체 파일을 문자열로 읽기
        json data = json::parse(buffer.str());  // 문자열을 파싱

        cout << "개발할 성을 선택해 주세요!" << endl;
        int size = sizeof(data["castle"]) / sizeof(data["castle[0]"]);

        for (int i = 0; i < size; i++) {
            cout << "성 이름 : " << data["castle_name"] << endl;
            cout << "농업 최대치 : " << data["Max_agriculture"] << "  ||  " << "현재 농업 진행 : " << data["early_agriculture"] << endl;
        }
        
        
        Sleep(3000);
    }
    catch (const json::parse_error& e) {
        cerr << "JSON 파싱 에러 발생: " << e.what() << endl;
        Sleep(3000);
    }

    Sleep(3000);
}