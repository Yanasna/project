#include<iostream>
#include <cstdlib>
#include <conio.h> // _getch()
#include <windows.h> // Sleep()
#include <fstream>
#include <nlohmann/json.hpp> // nlohmann::json 라이브러리

using json = nlohmann::json;
using namespace std;

static int money = 5000;
static int Year = 1200;
static int month = 1;
static int P_income = 0;

void Turn();

void agriculture() {;
    try {
        //가문의 성 정보 불러오기
        ifstream HouseFile("../../ConfuseAge_KATSU/HouseInfo.json");
        if (!HouseFile.is_open()) {
            cerr << "파일 열기 실패!" << endl;
            return;
        }
        stringstream buffer1;
        buffer1 << HouseFile.rdbuf();  // 전체 파일을 문자열로 읽기
        json HouseData = json::parse(buffer1.str());  // HouseInfo문자열을 파싱


        //성 데이터 불러오기
        ifstream file("../../ConfuseAge_KATSU/EarlyCastleData.json");
        if (!file.is_open()) {
            cerr << "파일 열기 실패!" << endl;
            return;
        }

        stringstream buffer2;
        buffer2 << file.rdbuf();  // 전체 파일을 문자열로 읽기
        json data = json::parse(buffer2.str());  // EarlyCastleData.json 문자열을 파싱

        cout << "개발할 성을 선택해 주세요!" << endl;
        int position = 0;
        
        bool running = true;
        int count = 0;
        for (const auto& entry : HouseData) {
            if (entry["House"] == "Hatakeyama") {
                count = entry["Castle_List"].size() -1;
                for (const auto& castle : entry["Castle_List"]) {
                    for (const auto& castleEntry : data) {
                        if (castle == castleEntry["castle_name"]) {
                            cout << "성 이름 : " << castleEntry["castle_name"] << " Castle  " << "  |  ";
                            cout << "농업 최대치 : " << castleEntry["Max_agriculture"] << "  ||  현재 농업 진행 : " << castleEntry["Early_agriculture"]
                                << (position == count ? "<- " : "  ") << "    " << endl;
                        }
                    }
                }
            }
        }

        while (running) {
            int country_key = _getch();
            if (country_key == 224) {
                int arrow = _getch();
                if (arrow == 75) { // ←
                    if (position > 0)
                        position--;
                }
                else if (arrow == 77) { // →
                    if (position < count)
                        position++;
                }
            }
            else if (country_key == 13) { // Enter 키
                system("cls");
                json Element = data[position];
                string Castle_Name = Element["castlename"];
                cout << Castle_Name << "성의 농업을 담당할 사람을 임명해주세요!";
            }
            system("cls");
            
            cout << "농업을 증진할 성을 선택하세요!" << endl;
            for (const auto& entry : HouseData) {
                if (entry["House"] == "Hatakeyama") {
                    count = entry["Castle_List"].size() - 1;
                    for (const auto& castle : entry["Castle_List"]) {
                        for (const auto& castleEntry : data) {
                            if (castle == castleEntry["castle_name"]) {
                                cout << "성 이름 : " << castleEntry["castle_name"] << " Castle  " << "  |  ";
                                cout << "농업 최대치 : " << castleEntry["Max_agriculture"] << "  ||  현재 농업 진행 : " << castleEntry["Early_agriculture"]
                                    << (position == count ? "<- " : "  ") << "    " << endl;
                            }
                        }
                    }
                }
            }
        }
        Turn();
        Sleep(3000);
    }
    catch (const json::parse_error& e) {
        cerr << "JSON 파싱 에러 발생: " << e.what() << endl;
        Sleep(3000);
    }
       
    Sleep(3000);
}


//자금 가져오는 함수
void Income() {
    try {
        //가문의 성 정보 불러오기
        ifstream HouseFile("../../ConfuseAge_KATSU/HouseInfo.json");
        if (!HouseFile.is_open()) {
            cerr << "파일 열기 실패!" << endl;
            return;
        }
        stringstream buffer1;
        buffer1 << HouseFile.rdbuf();  // 전체 파일을 문자열로 읽기
        json HouseData = json::parse(buffer1.str());  // 문자열을 파싱


        //성 데이터 불러오기
        ifstream file("../../ConfuseAge_KATSU/EarlyCastleData.json");
        if (!file.is_open()) {
            cerr << "파일 열기 실패!" << endl;
            return;
        }

        stringstream buffer2;
        buffer2 << file.rdbuf();  // 전체 파일을 문자열로 읽기
        json data = json::parse(buffer2.str());  // 문자열을 파싱


        P_income = 0;
        for (const auto& entry : HouseData) {
            if (entry["House"] == "Hatakeyama") {
                for (const auto& castle : entry["Castle_List"]) {
                    for (const auto& castleEntry : data) {
                        if (castle == castleEntry["castle_name"]) {
                            P_income += castleEntry["Early_commerce"].get<int>() * (castleEntry["Population"].get<int>()/ 10000);
                        }
                    }
                }
            }
        }
        cout << " 수입 : " << P_income << endl;
        cout << " 자금 : " << money << endl;
    }
        catch (const json::parse_error& e) {
            cerr << "JSON 파싱 에러 발생: " << e.what() << endl;
            Sleep(3000);
        }
}

void Time() {
    cout << "시간 : " << Year << "년,  " << month << "월" << endl;
    if (month == 12) {
        month = 1;
        Year++;
    }
}

void Turn() {
    money += P_income;
    month++;
}