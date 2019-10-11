#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //minheap = 우선순위가 낮은게 가장 위에
    priority_queue<int, vector<int>, greater<int>> pq;
    int min = 0;
    int min1, min2;
    for(int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    while(pq.top() < K) { //원하는 스코빌 지수보다 min값이 작으면 반복
        //큐에 저장된 값이 1개지만 아직도 반복문에 들어와있다면 불가능한 경우
        if(pq.size() == 1) return -1;
        
        min1 = pq.top();
        pq.pop();
        min2 = pq.top();
        pq.pop();
        min = min1 + min2*2;
        pq.push(min);
        answer++;
    }
    
    return answer;
}

int main() {
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(9);
    s.push_back(10);
    s.push_back(12);
    
    cout << solution(s, 7) << endl;
    
    return 0;
}

//스코빌 지수가 가장 낮은 두개의 음식을 아래와 같이 특별한 방법으로 섞어 새로운 음식을 만든다.
//섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두번째로 맵지 않은 음식의 스코빌 지수*2)
//모든 음식의 스코빌 지수가 K이상이 될 때 까지 반복하여 섞는다.
