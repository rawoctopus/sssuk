/*
 1. 다트 게임은 총 3번의 기회로 구성된다.
 2. 각 기회마다 얻을 수 있는 점수는 0~10점
 3. S=1제곱, D=2제곱, T=3제곱
 4. *=해당 점수와 바로 전에 얻은 점수를 2배로
 5. #=해당 점수 마이너스
 6. *(스타상)은 다른 *와 중첩 가능
 7. *은 # 중첩 가능 => 중첩된 #의 점수는 -2배가 된다.
 */

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int idx = 0;
    int cnt = 0;
    
    int temp[3];
    
    for(int i = 0; i < (int)dartResult.size(); i++) {
        //앞 점수일때
        if(cnt == 0) {
            int n = dartResult[i] - '0';
            temp[idx] = n;
        }
        //앞에 하나 들어가있는 상태에서
        else if(cnt == 1) {
            //10점일때
            if(dartResult[i] == '0') {
                temp[idx] = temp[idx] * 10;
                cnt--;
            }
            else if (dartResult[i] == 'D') {
                int n = temp[idx];
                temp[idx] = n * n;
            }
            else if(dartResult[i] == 'T') {
                int n = temp[idx];
                temp[idx] = n * n * n;
            }
        }
        //뒤 점수일때
        else {
            if(dartResult[i] == '*') {
                temp[idx] = temp[idx] * 2;
                if(idx - 1 >= 0)
                    temp[idx-1] = temp[idx-1]*2;
            }
            else if(dartResult[i] == '#')
                temp[idx] = temp[idx] * -1;
            else
                i--;
            idx++;
        }
        cnt++;
        cnt = cnt % 3;
    }
    
    return answer;
}
