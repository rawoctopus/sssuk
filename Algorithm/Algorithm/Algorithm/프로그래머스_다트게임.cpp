///*
// 1. 다트 게임은 총 3번의 기회로 구성된다.
// 2. 각 기회마다 얻을 수 있는 점수는 0~10점
// 3. S=1제곱, D=2제곱, T=3제곱
// 4. *=해당 점수와 바로 전에 얻은 점수를 2배로
// 5. #=해당 점수 마이너스
// 6. *(스타상)은 다른 *와 중첩 가능
// 7. *은 # 중첩 가능 => 중첩된 #의 점수는 -2배가 된다.
// */
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <math.h>
//
//using namespace std;
//
//int solution(string dartResult) {
//    int answer = 0;
//    int idx = 0;
//    int cnt = 0;
//    
//    int nArr[3];
//    
//    for(int i = 0; i < (int)dartResult.size(); i++) {
//        if(cnt == 0) {
//            int n = dartResult[i] - '0';
//            nArr[idx] = n;
//        }
//        else if(cnt == 1) {
//            if(dartResult[i] == '0') {
//                nArr[idx] = nArr[idx] * 10;
//                cnt--;
//            }
//            else if(dartResult[i] == 'D') {
//                int n = nArr[idx];
//                nArr[idx] = n * n;
//            }
//            else if(dartResult[i] == 'T') {
//                int n = nArr[idx];
//                nArr[idx] = n * n * n;
//            }
//        }
//        else { //cnt==2일때
//            if(dartResult[i] == '*') {
//                nArr[idx] = nArr[idx] * 2;
//                if(idx - 1 >= 0)
//                    nArr[idx-1] = nArr[idx-1]*2;
//            }
//            else if(dartResult[i] == '#')
//                nArr[idx] *= -1;
//            else i--;
//            
//            idx++;
//        }
//        cnt++;
//        cnt = cnt % 3;
//    }
//    
//    for(int i = 0; i < 3; i++)
//        answer += nArr[i];
//    
//    return answer;
//}
//
//int main() {
//    vector<string> s;
//    s.push_back("1S2D*3T");
//    s.push_back("1D2S#10S");
//    s.push_back("1D2S0T");
//    s.push_back("1S*2T*3S");
//    s.push_back("1D#2S*3S");
//    s.push_back("1T2D3D#");
//    s.push_back("1D2S3T*");
//    
//    for(int i = 0; i < s.size(); i++) {
//        cout << solution(s[i]) << endl;
//    }
//    
//    return 0;
//}
