#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct spec {
    int height;
    int weight;
    int order;
}spec;

int N;
vector<spec> body; //키, 몸무게, 등수

void solve() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            
            //키와 몸무게가 모두 작아야 등수가 올라간다
            else if(body[i].height < body[j].height && body[i].weight < body[j].weight)
                body[i].order++;
        }
    }
}

int main() {
    cout << "start" << endl;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        body.push_back({y, x, 1});
    }
    
    solve();
    for(int i = 0; i < N; i++) {
        cout << body[i].order << ' ';
    }
    
    return 0;
}
