#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
//실패율 = 스테이지에 도달했으나 아직 클리어하지 못한 플레이어 수 / 스테이지에 도달한 플레이어 수
//N = 전체 스테이지의 개수
//stages = 게임을 이용하는 사용자가 현재 멈춰있는 스테이지의 번호가 담긴 배열

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> failPercent; //(실패 확률, 스테이지 번호)
    
    //스테이지 별로 계산
    for(int n = 1; n <= N; n++) {
        double tried = 0; //시도 한 사람
        double succeed = 0; //성공 한 사람
        
        for(int i = 0; i <(int)stages.size(); i++) {
            if(stages[i] >= n) tried++;
            if(stages[i] > n) succeed++;
        }
        if(tried == 0 && succeed == 0)
            failPercent.push_back(make_pair(0, n));
        else
            failPercent.push_back(make_pair((tried-succeed)/tried, n));
    }
    
    sort(failPercent.begin(), failPercent.end());
    
    for(int i = 0; i < (int)failPercent.size(); i++) {
        for(int j = i+1; j <(int)failPercent.size(); j++) {
            if(failPercent[i].first == failPercent[j].first) {
                if(failPercent[i].second < failPercent[j].second) {
                    pair<double, int> temp;
                    temp = failPercent[i];
                    failPercent[i] = failPercent[j];
                    failPercent[j] = temp;
                }
            }
        }
    }
    
    for(int i = (int)failPercent.size()-1; i >= 0; i--)
        answer.push_back(failPercent[i].second);
    
    return answer;
}
