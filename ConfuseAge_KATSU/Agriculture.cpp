#include<iostream>
#include <cstdlib>
#include <conio.h> // _getch()
#include <windows.h> // Sleep()
#include <fstream>
#include <nlohmann/json.hpp> // nlohmann::json 라이브러리
#include <sstream>

using json = nlohmann::json;
using namespace std;

static int money = 5000;
static int Year = 1200;
static int month = 1;
static int P_income = 0;
static int add_agriculture;
static int add_commerce;

void Turn();
void Hatakeyama();


void agriculture() {
    try {
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
        json CastleData = json::parse(buffer2.str());  // CastleData.json 문자열을 파싱

        //장군 정보 불러오기
        ifstream GeneralFile("../../Project_ConfuseAge/GeneralInfo.json");
        if (!GeneralFile.is_open()) {
            cerr << "파일 열기 실패!" << endl;
            return;
        }
        stringstream buffer3;
        buffer3 << GeneralFile.rdbuf();  // 전체 파일을 문자열로 읽기
        json GeneralData = json::parse(buffer3.str());  // 문자열을 파싱


        cout << "농업을 개발할 성을 선택해 주세요!" << endl;
        int position = 0;

        bool running = true;
        int count = 0;

        for (const auto& entry : HouseData) {
            if (entry["House"] == "Hatakeyama") {
                for (const auto& castle : entry["Castle_List"]) {
                    for (const auto& castleEntry : CastleData) {
                        if (castle == castleEntry["castle_name"]) {
                            cout << "성 이름 : " << castleEntry["castle_name"] << " Castle  " << "  |  ";
                            cout << "농업 최대치 : " << castleEntry["Max_agriculture"] << "  ||  현재 농업 진행 : " << castleEntry["Early_agriculture"]
                                << (position == count ? "<-" : "  ") << "    " << endl;
                            count++;
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
                json Element = CastleData[position];
                string Castle_Name = Element["castle_name"];
                cout << Castle_Name << "성의 농업을 담당할 사람을 임명해주세요!" << endl;

                bool general_running = true;
                int general_count = 0;
                int general_position = 0;
                for (const auto& entry : HouseData) {
                    if (entry["House"] == "Hatakeyama") {
                        for (const auto& general : entry["General_List"]) {
                            for (const auto& GeneralEntry : GeneralData) {
                                if (general == GeneralEntry["General_Name"]) {
                                    cout << "장군 이름 : " << GeneralEntry["General_Name"] << "  |  ";
                                    cout << "무력 : " << GeneralEntry["Attack"] << "  ||  지략 : " << GeneralEntry["resourceful"]
                                        << (general_position == general_count ? "<-" : "  ") << "    " << endl;
                                    general_count++;
                                }
                            }

                        }
                    }
                }
                while (general_running) {
                    int general_key = _getch();
                    if (general_key == 224) {
                        int general_arrow = _getch();
                        if (general_arrow == 75) { // ←
                            if (general_position > 0)
                                general_position--;
                        }
                        else if (general_arrow == 77) { // →
                            if (general_position < general_count)
                                general_position++;
                        }
                    }
                    else if (general_key == 13)
                    {
                        int res;
                        char agriculture_num;
                        for (const auto& general : GeneralData) {
                            if (general["id"].get<int>() == (general_position + 1)) {
                                 res = general["resourceful"];
                                break;
                            }
                        }

                        system("cls");
                        cout << "농업 개발 시에는 자금 1000원이 소모됩니다!" << endl;
                        cout << "개발 하시겠습니까?" << endl;
                        cout << "예 -> Y , 아니오 -> N" << endl;
                        cin >> agriculture_num;

                        

                        if (agriculture_num == 'Y' || agriculture_num == 'y') {
                            money -= 1000;
                            cout << "농업 - 개발중" << endl;

                            for (auto& castle : CastleData) {
                                if (castle["castle_name"] == Castle_Name){
                                    if (castle["Early_agriculture"] < castle["Max_agriculture"]) {
                                        add_agriculture = castle["Early_agriculture"].get<int>() + (res * 50);
                                        if (add_agriculture >= castle["Max_agriculture"]) {
                                            add_agriculture = castle["Max_agriculture"];
                                        }
                                        castle["Early_agriculture"] = add_agriculture;
                                    }
                                }
                            }
                            ofstream fileOut("../../Project_ConfuseAge/CastleData.json");
                            if (!fileOut.is_open()) {
                                cerr << "파일 저장 실패!" << endl;
                            }
                            
                            fileOut << CastleData.dump(4); //
                            fileOut.close();
                            HouseFile.close();
                            GeneralFile.close();
                            CastleFile.close();

                            for (int i = 0; i < 5; i++)
                            {
                                Sleep(500);
                                cout << "=";
                            }
                            for (int i = 0; i < 5; i++)
                            {
                                Sleep(200);
                                cout << "=";
                            }
                            for (int j = 0; j < 10; j++) {
                                Sleep(50);
                                cout << "=";
                            }
                            cout << endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                            cout << "농업 개발 완료!" << endl;
                            cout << Castle_Name << "성의 현재 농업량 : "  << add_agriculture << endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                            Sleep(1000);
                            Turn();
                            Hatakeyama();
                        }
                        else {
                            Hatakeyama();
                        }
                    }
                    system("cls");
                    int general_count = 0;
                    cout << Castle_Name << "성의 농업을 담당할 사람을 임명해주세요!" << endl;
                    for (const auto& entry : HouseData) {
                        if (entry["House"] == "Hatakeyama") {
                            for (const auto& general : entry["General_List"]) {
                                for (const auto& GeneralEntry : GeneralData) {
                                    if (general == GeneralEntry["General_Name"]) {
                                        cout << "장군 이름 : " << GeneralEntry["General_Name"] << "  |  ";
                                        cout << "무력 : " << GeneralEntry["Attack"] << "  ||  지략 : " << GeneralEntry["resourceful"]
                                            << (general_position == general_count ? "<-" : "  ") << "    " << endl;
                                        general_count++;
                                    }
                                }

                            }
                        }
                    }
                }

                system("cls");

                cout << "농업을 증진할 성을 선택하세요!" << endl;
                for (const auto& entry : HouseData) {
                    if (entry["House"] == "Hatakeyama") {
                        count = entry["Castle_List"].size() - 1;
                        for (const auto& castle : entry["Castle_List"]) {
                            for (const auto& castleEntry : CastleData) {
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
        }
    }
    catch (const json::parse_error& e) {
        cerr << "JSON 파싱 에러 발생: " << e.what() << endl;
        Sleep(3000);
    }

    Sleep(3000);
}


//상업 함수
void commerce() {
    try {
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
        json CastleData = json::parse(buffer2.str());  // CastleData.json 문자열을 파싱

        //장군 정보 불러오기
        ifstream GeneralFile("../../Project_ConfuseAge/GeneralInfo.json");
        if (!GeneralFile.is_open()) {
            cerr << "파일 열기 실패!" << endl;
            return;
        }
        stringstream buffer3;
        buffer3 << GeneralFile.rdbuf();  // 전체 파일을 문자열로 읽기
        json GeneralData = json::parse(buffer3.str());  // 문자열을 파싱


        cout << "상업을 개발할 성을 선택해 주세요!" << endl;
        int position = 0;

        bool running = true;
        int count = 0;

        for (const auto& entry : HouseData) {
            if (entry["House"] == "Hatakeyama") {
                for (const auto& castle : entry["Castle_List"]) {
                    for (const auto& castleEntry : CastleData) {
                        if (castle == castleEntry["castle_name"]) {
                            cout << "성 이름 : " << castleEntry["castle_name"] << " Castle  " << "  |  ";
                            cout << "상업 최대치 : " << castleEntry["Max_commerce"] << "  ||  현재 상업 진행 : " << castleEntry["Early_commerce"]
                                << (position == count ? "<-" : "  ") << "    " << endl;
                            count++;
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
                json Element = CastleData[position];
                string Castle_Name = Element["castle_name"];
                cout << Castle_Name << "성의 상업을 담당할 사람을 임명해주세요!" << endl;

                bool general_running = true;
                int general_count = 0;
                int general_position = 0;
                for (const auto& entry : HouseData) {
                    if (entry["House"] == "Hatakeyama") {
                        for (const auto& general : entry["General_List"]) {
                            for (const auto& GeneralEntry : GeneralData) {
                                if (general == GeneralEntry["General_Name"]) {
                                    cout << "장군 이름 : " << GeneralEntry["General_Name"] << "  |  ";
                                    cout << "무력 : " << GeneralEntry["Attack"] << "  ||  지략 : " << GeneralEntry["resourceful"]
                                        << (general_position == general_count ? "<-" : "  ") << "    " << endl;
                                    general_count++;
                                }
                            }

                        }
                    }
                }
                while (general_running) {
                    int general_key = _getch();
                    if (general_key == 224) {
                        int general_arrow = _getch();
                        if (general_arrow == 75) { // ←
                            if (general_position > 0)
                                general_position--;
                        }
                        else if (general_arrow == 77) { // →
                            if (general_position < general_count)
                                general_position++;
                        }
                    }
                    else if (general_key == 13)
                    {
                        int res;
                        char commerce_num;
                        for (const auto& general : GeneralData) {
                            if (general["id"].get<int>() == (general_position + 1)) {
                                res = general["resourceful"];
                                break;
                            }
                        }

                        system("cls");
                        cout << "상업 개발 시에는 자금 1000원이 소모됩니다!" << endl;
                        cout << "개발 하시겠습니까?" << endl;
                        cout << "예 -> Y , 아니오 -> N" << endl;
                        cin >> commerce_num;



                        if (commerce_num == 'Y' || commerce_num == 'y') {
                            money -= 1000;
                            cout << "상업 - 개발중" << endl;

                            for (auto& castle : CastleData) {
                                if (castle["castle_name"] == Castle_Name) {
                                    if (castle["Early_commerce"] < castle["Max_commerce"]) {
                                        add_commerce = castle["Early_commerce"].get<int>() + (res * 2);
                                        if (add_commerce >= castle["Max_commerce"]) {
                                            add_commerce = castle["Max_commerce"];
                                        }
                                        castle["Early_agriculture"] = add_agriculture;
                                    }
                                }
                            }
                            ofstream fileOut("../../Project_ConfuseAge/CastleData.json");
                            if (!fileOut.is_open()) {
                                cerr << "파일 저장 실패!" << endl;
                            }

                            fileOut << CastleData.dump(4); //
                            fileOut.close();
                            HouseFile.close();
                            GeneralFile.close();
                            CastleFile.close();

                            for (int i = 0; i < 5; i++)
                            {
                                Sleep(500);
                                cout << "=";
                            }
                            for (int i = 0; i < 5; i++)
                            {
                                Sleep(200);
                                cout << "=";
                            }
                            for (int j = 0; j < 10; j++) {
                                Sleep(50);
                                cout << "=";
                            }
                            cout << endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                            cout << "상업 개발 완료!" << endl;
                            cout << Castle_Name << "성의 현재 상업량 : " << add_commerce << endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                            Sleep(1000);
                            Turn();
                            Hatakeyama();
                        }
                        else {
                            Hatakeyama();
                        }
                    }
                    system("cls");
                    int general_count = 0;
                    cout << Castle_Name << "성의 상업을 담당할 사람을 임명해주세요!" << endl;
                    for (const auto& entry : HouseData) {
                        if (entry["House"] == "Hatakeyama") {
                            for (const auto& general : entry["General_List"]) {
                                for (const auto& GeneralEntry : GeneralData) {
                                    if (general == GeneralEntry["General_Name"]) {
                                        cout << "장군 이름 : " << GeneralEntry["General_Name"] << "  |  ";
                                        cout << "무력 : " << GeneralEntry["Attack"] << "  ||  지략 : " << GeneralEntry["resourceful"]
                                            << (general_position == general_count ? "<-" : "  ") << "    " << endl;
                                        general_count++;
                                    }
                                }

                            }
                        }
                    }
                }

                system("cls");

                cout << "상업을 증진할 성을 선택하세요!" << endl;
                for (const auto& entry : HouseData) {
                    if (entry["House"] == "Hatakeyama") {
                        count = entry["Castle_List"].size() - 1;
                        for (const auto& castle : entry["Castle_List"]) {
                            for (const auto& castleEntry : CastleData) {
                                if (castle == castleEntry["castle_name"]) {
                                    cout << "성 이름 : " << castleEntry["castle_name"] << " Castle  " << "  |  ";
                                    cout << "농업 최대치 : " << castleEntry["Max_commerce"] << "  ||  현재 농업 진행 : " << castleEntry["Early_commerce"]
                                        << (position == count ? "<- " : "  ") << "    " << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    catch (const json::parse_error& e) {
        cerr << "JSON 파싱 에러 발생: " << e.what() << endl;
        Sleep(3000);
    }
}


//자금 가져오는 함수
void Income() {
    try {
        //가문의 성 정보 불러오기
        ifstream HouseFile("../../Project_ConfuseAge/HouseInfo.json");
        if (!HouseFile.is_open()) {
            cerr << "파일 열기 실패!" << endl;
            return;
        }
        stringstream buffer1;
        buffer1 << HouseFile.rdbuf();  // 전체 파일을 문자열로 읽기
        json HouseData = json::parse(buffer1.str());  // 문자열을 파싱


        //성 데이터 불러오기
        ifstream CastleFile("../../Project_ConfuseAge/CastleData.json");
        if (!CastleFile.is_open()) {
            cerr << "파일 열기 실패!" << endl;
            return;
        }

        stringstream buffer2;
        buffer2 << CastleFile.rdbuf();  // 전체 파일을 문자열로 읽기
        json CastleData = json::parse(buffer2.str());  // 문자열을 파싱


        P_income = 0;
        for (const auto& entry : HouseData) {
            if (entry["House"] == "Hatakeyama") {
                for (const auto& castle : entry["Castle_List"]) {
                    for (const auto& castleEntry : CastleData) {
                        if (castle == castleEntry["castle_name"]) {
                            P_income += castleEntry["Early_commerce"].get<int>() * (castleEntry["Population"].get<int>() / 10000);
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