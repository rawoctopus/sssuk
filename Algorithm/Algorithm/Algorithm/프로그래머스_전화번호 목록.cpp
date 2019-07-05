#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size(); i++) {
        for(int j = i+1; j < phone_book.size(); j++) {
            if(phone_book[j].length() < phone_book[i].length())
                continue;
            
            if(phone_book[j].substr(0, phone_book[i].length()) == phone_book[i])
                return false;
        }
    }
    
    return answer;
}
