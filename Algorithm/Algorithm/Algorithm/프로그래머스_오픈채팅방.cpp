#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    //닉네임만
    map<string, string> m; //key=uid, value=nickname
    vector<pair<string, string>> log; //uid, state
    
    for(int i = 0; i < (int)record.size(); i++) {
        string nickname;
        string uid;
        //Enter일 때
        if(record[i].find("Enter") == 0) {
            uid = record[i].substr(6, record[i].substr(6).find(" "));
            nickname = record[i].substr(6).substr((record[i].substr(6)).find(" ")+1);
            m[uid] = nickname;
            log.push_back({uid, "님이 들어왔습니다."});
        }
        //Leave일 때
        else if(record[i].find("Leave") == 0) {
            uid = record[i].substr(6, record[i].substr(6).find(" "));
            //nickname = m[uid];
            log.push_back({uid, "님이 나갔습니다."});
        }
        //Change일 때
        else if(record[i].find("Change") == 0) {
            uid = record[i].substr(7, record[4].substr(7).find(" "));
            nickname = record[i].substr(7).substr((record[i].substr(7)).find(" ")+1);
            m[uid] = nickname;
        }
    }
    
    for(auto x : log) {
        answer.push_back(m[x.first] + x.second);
    }
    
    return answer;
}
