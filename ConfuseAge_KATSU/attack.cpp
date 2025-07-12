#include<iostream>
#include <cstdlib>
#include <conio.h> // _getch()
#include <windows.h> // Sleep()
#include <fstream>
#include <nlohmann/json.hpp> // nlohmann::json 라이브러리
#include <sstream>

using json = nlohmann::json;
using namespace std;

void attack_() {
	cout << "어디로 출전할까요?" << endl;


	 try {
        //가문의 성 정보 불러오기
        ifstream HouseFile("../../Project_ConfuseAge/HouseInfo.json");
        if (!HouseFile.is_open()) {
            cerr << "가문 파일 열기 실패!" << endl;
            return;
        }
        stringstream buffer1;
        buffer1 << HouseFile.rdbuf();  // 전체 파일을 문자열로 읽기
        json HouseData = json::parse(buffer1.str());  // HouseInfo문자열을 파싱


        //성 데이터 불러오기
        ifstream CastleFile("../../Project_ConfuseAge/CastleData.json");
        if (!CastleFile.is_open()) {
            cerr << "성 데이터 파일 열기 실패!" << endl;
            return;
        }

        stringstream buffer2;
        buffer2 << CastleFile.rdbuf();  // 전체 파일을 문자열로 읽기
        json CastleData = json::parse(buffer2.str());  // CastleData.json 문자열을 파싱

        //장군 정보 불러오기
        ifstream GeneralFile("../../Project_ConfuseAge/GeneralInfo.json");
        if (!GeneralFile.is_open()) {
            cerr << "장군 정보 파일 열기 실패!" << endl;
            return;
        }
        stringstream buffer3;
        buffer3 << GeneralFile.rdbuf();  // 전체 파일을 문자열로 읽기
        json GeneralData = json::parse(buffer3.str());  // 문자열을 파싱


        for (const auto& entry : HouseData) {
            if (entry["House"] == "Hatakeyama") {
                cout << "하타케야마" << endl;
                cout << "----------------------------------------------------------------" << endl;
                for (const auto& castle : entry["Castle_List"]) {
                    for (const auto& castleEntry : CastleData) {
                        if (castle == castleEntry["castle_name"]) {
                            cout << "성 이름 : " << castleEntry["castle_name"] << " Castle  " << "  |  ";
                            cout << "병력 수 : " << castleEntry["army"] << endl;
                        }
                    }
                }
                cout << "================================================================" << endl;
            }

            if (entry["House"] == "Ogigayatsu") {
                cout << "오기가야츠" << endl;
                cout << "----------------------------------------------------------------" << endl;
                for (const auto& castle : entry["Castle_List"]) {
                    for (const auto& castleEntry : CastleData) {
                        if (castle == castleEntry["castle_name"]) {
                            cout << "성 이름 : " << castleEntry["castle_name"] << " Castle  " << "  |  ";
                            cout << "병력 수 : " << castleEntry["army"] << endl;
                        }
                    }

                }
                cout << "================================================================" << endl;
            }

            if (entry["House"] == "Watanabe") {
                cout << "와타나베" << endl;
                cout << "----------------------------------------------------------------" << endl;
                for (const auto& castle : entry["Castle_List"]) {
                    for (const auto& castleEntry : CastleData) {
                        if (castle == castleEntry["castle_name"]) {
                            cout << "성 이름 : " << castleEntry["castle_name"] << " Castle  " << "  |  ";
                            cout << "병력 수 : " << castleEntry["army"] << endl;
                        }
                    }

                }
                cout << "================================================================" << endl;
            }
        }

    }
    catch (const json::parse_error& e) {
        cerr << "JSON 파싱 에러 발생: " << e.what() << endl;
        Sleep(3000);
    }
	
}