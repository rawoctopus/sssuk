#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    int strike = 0;
    int ball = 0;
    bool flag = true;
    string num1 = "";
    string num2 = "";
    
    //baseball[j][1] = strike = 숫자와 위치가 모두 맞을 때
    //baseball[j][2] = ball = 숫자는 맞지만, 위치가 틀렸을 때
    
    for(int i = 123; i <= 987; i++) {
        num1 = to_string(i);
        //같은 숫자 나오는 경우 스킵
        if(num1[0] == num1[1] || num1[0] == num1[2] || num1[1] == num1[2])
            continue;
        else if(num1[0] == '0' || num1[1] == '0' || num1[2] == '0')
            continue;
        
        flag = true;
        
        for(int j = 0; j < baseball.size(); j++) {
            strike = 0;
            ball = 0;
            for(int a = 0; a < 3; a++) {
                for(int b = 0; b < 3; b++) {
                    num2 = to_string(baseball[j][0]);
                    if(a == b && num1[a] == num2[b]) {
                        strike++;
                        continue;
                    }
                    if(a != b && num1[a] == num2[b]) {
                        ball++;
                        continue;
                    }
                }
            }
            if(strike != baseball[j][1] || ball != baseball[j][2]) {
                flag = false;
                break;
            }
        }
        if(flag == true) answer++;
    }
    return answer;
}

int main() {
    vector<vector<int>> b;
    b.resize(4);
    b[0].push_back(123);
    b[0].push_back(1);
    b[0].push_back(1);
    
    b[1].push_back(356);
    b[1].push_back(1);
    b[1].push_back(0);
    
    b[2].push_back(327);
    b[2].push_back(2);
    b[2].push_back(0);
    
    b[3].push_back(489);
    b[3].push_back(0);
    b[3].push_back(1);
    
    cout << solution(b) << endl;
    
    return 0;
}
/*
 작은 경우 123과 가장 마지막 경우인 987까지를 baseball 변수와 비교해서 만족하면 값을 더하는 방식
 각 숫자를 비교할 때 편하게 하기 위해 string은 []참조 방식이 가능하기 때문에 to_string 함수를 이용해서
 int를 string으로 바꿈. 같은 숫자 안나오기 위해 0,2번째가 같은 경우 0,1번째가 같은 경우 1,2번째가 같은 경우와 0,1,2번째가 모두 0ㅇ인 경우는 continue;
 */
