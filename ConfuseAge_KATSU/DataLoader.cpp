#include<iostream>
#include <cstdlib>
#include <conio.h> // _getch()
#include <windows.h> // Sleep()
#include <fstream>
#include <nlohmann/json.hpp> // nlohmann::json 라이브러리

using json = nlohmann::json;
using namespace std;

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

        cout << "개발할 성을 선택해 주세요!" << endl;

        for (const auto& entry : HouseData) {
            if (entry["House"] == "Hatakeyama") {
                for (const auto& castle : entry["Castle_List"]) {
                    for (const auto& castleEntry : data) {
                        if (castle == castleEntry["castle_name"]) {
                            cout << "성 이름 : " << castleEntry["castle_name"] << " Castle  " << "  |  ";
                            cout << "농업 최대치 : " << castleEntry["Max_agriculture"] << "  ||  현재 농업 진행 : " << castleEntry["Early_agriculture"] << endl;
                        }
                    }
                }
            }
        }

        Sleep(3000);
    }
    catch (const json::parse_error& e) {
        cerr << "JSON 파싱 에러 발생: " << e.what() << endl;
        Sleep(3000);
    }
       
    Sleep(3000);
}
      