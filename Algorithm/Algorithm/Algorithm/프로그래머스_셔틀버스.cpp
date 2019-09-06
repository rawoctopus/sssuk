/*
 - 시간 계산을 쉽게 하기 위해 string으로 입력받은 time table을 int형식의 분값으로 바꿨다.
 - 그 다음 오름차순으로 시간을 정렬하여, 09:00시(첫차)부터 버스에 타는 크루를 체크하는 방식으로 했다.
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

char timeConvertor[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

//분으로 변경(계산하기 쉽게)
int convertToMin(string time) {
    int minTime = 0;
    //09:00
    int hour = ((time[0] - '0') * 10 + (time[1] - '0')) * 60;
    int min = (time[3] - '0') * 10 + (time[4] - '0');
    
    minTime = hour + min;
    return minTime;
}

//총 n회 t분 간격으로 도착, 하나의 셔틀에는 최대 m명이 탈 수 있다.
//셔틀은 9시부터 탈 수 있음
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int conTime = 0;
    vector<int> timetableToInt; //timetable의 시간을 분단위로 바꿔서 넣어준 컨테이너
    int crewNum = (int)timetable.size();
    
    //timetable의 시간을 분단위로 바꿔서 인트형 벡터에 넣어줌
    for(int i = 0; i < crewNum; i++)
        timetableToInt.push_back(convertToMin(timetable[i]));
    
    //시간 순으로 정렬
    sort(timetableToInt.begin(), timetableToInt.end());
    
    int checkCrew = 0; //버스에 탈 크루 체크(timetable 순서)
    int driveTime = 540; // 9 * 60 = 540분(첫차가 09시)
    
    for(int i = 0; i < n; i++) {
        int shuttleSeat = m; //운행시간마다 셔틀에 탈 수 있는 최대 크루 수
        
        //운행시각마다 셔틀타는 크루수 체크
        for(int j = checkCrew; j < crewNum; j++) {
            if(timetableToInt[j] <= driveTime) {
                shuttleSeat -= 1; //인원수 빼기
                checkCrew += 1;
                if(shuttleSeat == 0) break; //자리 다차면 끝
            }
        }
        
        //다음 운행이 없을 경우 콘 시간 정하기
        if(i == n - 1) {
            if(shuttleSeat == 0)
                conTime = timetableToInt[checkCrew - 1] - 1; //자리가 없을 때
            else
                conTime = driveTime; //자리가 있을 때
        }
        
        driveTime += t;
        if(driveTime >= (60 * 24)) break;
    }
    
    //int 값을 string값으로 만들어주는 코드
    int temp;
    temp = conTime / 60;
    answer += timeConvertor[temp / 10];
    answer += timeConvertor[temp % 10];
    answer += ":";
    temp = conTime % 60;
    answer += timeConvertor[temp / 10];
    answer += timeConvertor[temp % 10];
    
    return answer;
}
