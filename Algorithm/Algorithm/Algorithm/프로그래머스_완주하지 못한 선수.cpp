#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participants, vector<string> completion) {
    string answer = "";
    sort(participants.begin(), participants.end());
    sort(completion.begin(), completion.end());
    
    int i = 0;
    while(true) {
        if(i == completion.size())
            return participants[i];
        
        if(participants[i] != completion[i])
            return participants[i];
        i++;
    }
    
    return participants[participants.size()-1];
}
