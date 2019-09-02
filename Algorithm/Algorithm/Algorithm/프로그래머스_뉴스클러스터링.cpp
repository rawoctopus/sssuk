#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

/*
 - 영문자로 된 글자쌍만 유효
 - 공백이나 숫자, 특수 문자가 들어있는 경우는 그 글자 쌍을 버린다.
 - 대소문자 구분x
 - 교집합의 개수 / 합집합 개수 = 자카드 유사도
 */

int solution(string str1, string str2) {
    int answer = 65536;
    double all = 0; //합집합
    double dup = 0; //교집합
    map<string, int> m;
    
    //일단 대문자로 다변환
    for(int i = 0; i < str1.length(); i++)
        str1[i] = toupper(str1[i]);
    
    for(int i = 0; i < str2.length(); i++)
        str2[i] = toupper(str2[i]);
    
    for(int i = 0; i < str1.size() - 1; i++) {
        if(str1[i] < 'A' || str1[i] > 'Z') continue;
        if(str1[i+1] < 'A' || str1[i+1] > 'Z') continue;
        
        string str;
        str = str1[i];
        str += str1[i+1];
        all++;
        
        if(m.count(str)) m[str]++;
        else m[str] = 1;
    }
    
    for(int i = 0; i < str2.size()-1; i++) {
        if(str2[i] < 'A' || str2[i] > 'Z') continue;
        if(str2[i+1] < 'A' || str2[i+1] > 'Z') continue;
        
        string str;
        str = str2[i];
        str += str2[i+1];
        
        if(m.count(str)) {
            if(m[str] > 0) {
                m[str]--;
                dup++;
            }
            else all++;
        }
        else
            all++;
    }
    
    if(all != 0)
        answer = (int)((double)answer * (dup / all));
    
    return answer;
}
