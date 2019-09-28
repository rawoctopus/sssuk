#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//progresses : 먼저 배포되어야 하는 순서대로 작업의 진도가 적힌 벡터
//speeds : 각 작업의 개발 속도
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for(int i = 0; i < progresses.size(); i++) {
        int dayCnt = 0;
        while(progresses[i] < 100) {
            progresses[i] += speeds[i];
            dayCnt++;
        }
        q.push(dayCnt); //프로그래스 별로 작업 완수한 시간을 큐에 추가
    }
    
    int cnt = 1;
    int cur = q.front();
    q.pop();

    while(!q.empty()) {
        if(q.front() <= cur) {
            q.pop();
            cnt++;
        }
        else {
            answer.push_back(cnt);
            cnt = 1;
            cur = q.front();
            q.pop();
        }
    }
    answer.push_back(cnt);

    return answer;
}


int main() {
    vector<int> p;
    vector<int> s;

    p.push_back(93);
    p.push_back(30);
    p.push_back(55);
    s.push_back(1);
    s.push_back(30);
    s.push_back(5);

    p.clear();
    s.clear();
    p.push_back(40);
    p.push_back(93);
    p.push_back(30);
    p.push_back(55);
    p.push_back(60);
    p.push_back(65);

    s.push_back(60);
    s.push_back(1);
    s.push_back(30);
    s.push_back(5);
    s.push_back(10);
    s.push_back(7);
    //
    //    p.clear();
    //    s.clear();
    //    p.push_back(93);
    //    p.push_back(30);
    //    p.push_back(55);
    //    p.push_back(60);
    //    p.push_back(40);
    //    p.push_back(65);
    //    s.push_back(1);
    //    s.push_back(30);
    //    s.push_back(5);
    //    s.push_back(10);
    //    s.push_back(60);
    //    s.push_back(7);
    for(auto x : solution(p, s))
        cout << x << ' ';

    cout << endl;

    return 0;
}
