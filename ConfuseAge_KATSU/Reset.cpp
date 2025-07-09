#include<iostream>
#include <cstdlib>
#include <conio.h> // _getch()
#include <windows.h> // Sleep()
#include <fstream>
#include <nlohmann/json.hpp> // nlohmann::json 라이브러리
#include <sstream>

using namespace std;
using json = nlohmann::json;



//성의 기본 값 세팅, 처음에 시작할 시 리셋
void ResetCastle() {
    json CastleData;
    //가문의 성 정보 불러오기
    ifstream HouseFile("../../Project_ConfuseAge/HouseInfo.json");
    if (!HouseFile.is_open()) {
        cerr << "파일 열기 실패!" << endl;
        return;
    }
    stringstream buffer1;
    buffer1 << HouseFile.rdbuf();  // 전체 파일을 문자열로 읽기
    json HouseData = json::parse(buffer1.str());  // HouseInfo문자열을 파싱


    //성 데이터 불러오기
    ifstream CastleFile("../../Project_ConfuseAge/CastleData.json");
    if (!CastleFile.is_open()) {
        cerr << "파일 열기 실패!" << endl;
        return;
    }

    stringstream buffer2;
    buffer2 << CastleFile.rdbuf();  // 전체 파일을 문자열로 읽기
    CastleData = json::parse(buffer2.str());  // CastleData.json 문자열을 파싱

    //장군 정보 불러오기
    ifstream GeneralFile("../../Project_ConfuseAge/GeneralInfo.json");
    if (!GeneralFile.is_open()) {
        cerr << "파일 열기 실패!" << endl;
        return;
    }
    stringstream buffer3;
    buffer3 << GeneralFile.rdbuf();  // 전체 파일을 문자열로 읽기
    json GeneralData = json::parse(buffer3.str());  // 문자열을 파싱

    //성들의 농업, 상업, 병영 정보 리셋
    for (auto& castle : CastleData) {
        if (castle["castle_name"] == "Karouji") {
            castle["Early_agriculture"] = 10000;
            castle["Early_commerce"] = 1800;
            castle["army"] =  4000;
            }
        if (castle["castle_name"] == "Karouka") {
            castle["Early_agriculture"] = 7000;
            castle["Early_commerce"] = 500;
            castle["army"] = 6000;
        }
        if (castle["castle_name"] == "Karobo") {
            castle["Early_agriculture"] = 8000;
            castle["Early_commerce"] = 200;
            castle["army"] = 2000;
        }
        }

    ofstream fileOut("../../Project_ConfuseAge/CastleData.json");
    if (!fileOut.is_open()) {
        cerr << "파일 저장 실패!" << endl;
    }
    fileOut << CastleData.dump(4); //
    fileOut.close();

}