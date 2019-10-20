#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land) {
    int sol = 0;
    int r = (int)land.size();
    
    for(int i = 0; i < r; i++) {
        if (i == 0) continue;
        for(int j = 0; j < 4; j++) {
            int mx = 0;
            for(int k = 0; k < 4; k++) {
                if(j == k) continue;
                mx = max(mx, land[i-1][k]); //자기 위의 값 중 제일 큰 것
            }
            // 현재 i,j 위치에 적산 한다.
            land[i][j] = mx + land[i][j];
        }
    }
    
    for(int i = 0; i < 4; i++) {
        sol = max(sol, land.back()[i]);
    }
    return sol;
}
