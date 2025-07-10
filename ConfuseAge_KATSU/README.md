## ConfuseAge_KATSU

<p>c++코드로 작성 / nlohmann - json.hpp 사용</p>

<li>카츠_혼란시대_ 업데이트 기록</li>

<li>7/1</li>
<p>Json파일 2개를 연동하여 해당 가문_ 성의(HouseInfo.json) 농업 정보(EarlyCastleData.json)를 받아오도록 구성</p>
<p> 수입설정 Income()</p>
<p>시간설정 Time()  </p>

<li>7/2</li>
<p>GeneralInfo 추가</p>
<p>장군 데이터 추가</p>

<li> 7/3 </li>
<p>agriculture.cpp 업데이트 - 농업-담당자 선택지 추가  </p>
<p>해당 담당자의 지략에 따라 농업 증가 </p>

<li> 7/6 </li>
<p>reset 추가 </p>
<p>처음시작할 때 castleData 초기화 </p>

<li>7/9 </li>
<p>agriculture에commerce() 함수 추가 / 상업 선택지 추가</p>
<p>reset.cpp에 다른 성들도 초기화하도록 초기값 설정 </p>

<li>7/10 </li>
<p>병력 모집, 세력정보 데이터 추가</p>
<p>병력 모집army() 병력 모집시 자금-1000 수 많으면 수입이 줄어들도록 구성</p>
<p> CastleData, GeneralInfo, HouseInfo json파일 업데이트 - 와타나베 가문의 장군 및 가문 데이터 추가 </p>