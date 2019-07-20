#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define max_int 101
using namespace std;

int root[max_int];

int find(int x) {
    return (x == root[x]) ? x : root[x] = find(root[x]);  // 만든후 par달아주고
}

void myUnion(int x, int y) {
    root[find(y)] = find(x);
} // 만든후 find 달아주고

bool compare(vector<int> &a, vector<int> &b) {
    if(a[2] < b[2])
        return true;
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    // 1. d[i] = i의 부모를 담는다. 처음에는 자기 자신이 부모이다.
    // disjoint-set을 사용하기 위해 초기화
    for(int i=0; i<n; i++){
        root[i] = i;
    }
    
    // 2. 간선의 가중치 기준 오름차순 정렬
    sort(costs.begin(), costs.end(), compare);
    cout << costs[0][2] << costs[1][2];
    // 3. 모든 간선을 검사한다.
    for(int i=0; i<costs.size(); i++){
        int start = find(costs[i][0]);
        int end = find(costs[i][1]);
        int cost = costs[i][2];
        
        // 싸이클 검사
        if(find(start) != find(end)) {
            myUnion(start, end);
            answer += cost;
        }
    }
    
    return answer;
}
