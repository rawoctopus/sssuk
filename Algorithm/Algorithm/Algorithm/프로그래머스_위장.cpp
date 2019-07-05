#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//[의상이름, 의상종류]
int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> hash;
    
    for(int i = 0; i < clothes.size(); i++) {
        //key가 어차피 중복이 되지 않기 때문에
        hash[clothes[i][1]]++; //key가 의상 종류, value가 가지수
    }
    
    map<string, int>:: iterator ihash = hash.begin();
    answer = hash.begin()->second;
    for(ihash++; ihash != hash.end(); ++ihash) {
        answer = answer + (answer+1) * ihash->second;
    }
    
    return answer;
}
