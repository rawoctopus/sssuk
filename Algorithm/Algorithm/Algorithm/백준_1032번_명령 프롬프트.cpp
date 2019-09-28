#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<string> input;

void solution() {
    string answer = input[0];
    
    for(int i = 1; i < input.size(); i++) {
        string s = input[i];
        for(int j = 0; j < s.size(); j++) {
            if(answer[j] != s[j]) answer[j] = '?';
        }
    }
    
    cout << answer << endl;
}

int main() {
    cout << "start" << endl;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        string inp;
        cin >> inp;
        input.push_back(inp);
    }
    solution();
    
    return 0;
}
