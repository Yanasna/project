#include<iostream>
#include <cstdlib>
#include <conio.h> // _getch()
#include <windows.h> // Sleep()
#include <fstream>
#include <nlohmann/json.hpp> // nlohmann::json 라이브러리

using namespace std;
using json = nlohmann::json;

void ResetData() {
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
    ifstream CastleFile("../../ConfuseAge_KATSU/CastleData.json");
    if (!CastleFile.is_open()) {
        cerr << "파일 열기 실패!" << endl;
        return;
    }

    stringstream buffer2;
    buffer2 << CastleFile.rdbuf();  // 전체 파일을 문자열로 읽기
    json CastleData = json::parse(buffer2.str());  // CastleData.json 문자열을 파싱

    //장군 정보 불러오기
    ifstream GeneralFile("../../ConfuseAge_KATSU/GeneralInfo.json");
    if (!GeneralFile.is_open()) {
        cerr << "파일 열기 실패!" << endl;
        return;
    }
    stringstream buffer3;
    buffer3 << GeneralFile.rdbuf();  // 전체 파일을 문자열로 읽기
    json GeneralData = json::parse(buffer3.str());  // 문자열을 파싱
    



    ofstream fileOut("../../ConfuseAge_KATSU/CastleData.json");
    if (!fileOut.is_open()) {
        cerr << "파일 저장 실패!" << endl;
    }
    fileOut << CastleData.dump(4); //
    fileOut.close();

}