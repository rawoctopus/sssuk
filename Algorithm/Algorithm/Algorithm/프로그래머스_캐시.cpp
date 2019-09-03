/*************************************************************
 - 램을 같은 크기의 블록으로 구성해서 운용하는데 이 블록을 페이지라고 부른다,
 - 만약 cpu가 계산을 할 떄 필요한 데이터가 페이지에 있다면 cache hit 라고 부르며, 없을 경우에는 보조기억장치로부터 데이터를 페이지로 옮겨온 후에 계싼을 하는데 이 때를 cache miss라고 부른다.
 - hit 일 떄와 miss 일 때 시간이 차이가 나기 때문에 보다 빠른 연산을 위해선 페이지에 여러 정보중에 어떤 정보를 오래 저장해 놓아야 하는지가 매우 중요한 문제가 된다. 램의 자원이 같더라도 어떤 방식의 알고리즘을 사용하느냐에 따라 10초만에 일을 마칠 수도, 1분만에 일을 마칠수도 있기 때문이다.
 - 페이지 교체 알고리즘에는 대표적으로 다음과 같은 종류의 알고리즘이 있다.
 - FIFO (First In First Out)
 - OPT (OPTimal Page Replacement)
 - LRU (Least Recently Used)
 - Count-Based
 - LFU (Least Frequently Used)
 - MFU (Most Frequently Used)
 ****************************************************************/

/*
 * LRU 알고리즘 : 페이지에서 제거할 때 가장 오랫동안 사용하지 않은 것을 제거하겠다는 알고리즘
 * 구현 방법
 - 페이지에 저장된 데이터가 언제 사용되었는지를 알 수 있게 하는 부분을 구현해서 제일 오랫동안 참조되지 않은 데이터를 제거
 - 페이지에 데이터를 큐형식으로 저장하는 방식
 *
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;

//일단 cacheSize만큼 공간을 만들기 위해 배열로 만들고 캐쉬의 사용 순서를 알기 위한 배열을 또 만든다.
//그 다음 cities를 한 개씩 풀러오면서 캐시에 내용이 존재하지 않으면 값을 집어넣고 사용 순서는 count라는 숫자로 그냥 1개씩 늘렸다.
//count가 높을 수록 최근에 사용된 캐시라는 것으로 이용해서 캐시 사이즈가 꽉찼을 경우 count가 가장 큰 것을 바꾸는 방법을 이용함

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int recent = 0;
    int count = 0;
    bool flag = false;
    vector<string> cache(cacheSize);
    vector<int> cache_recent(cacheSize);
    
    //cache miss
    if(cacheSize == 0)
        return (int)cities.size() * 5;
    
    for(int i = 0; i < (int)cities.size(); i++) {
        //다 소문자로 바꿔줌
        for(int j = 0; j < (int)cities[i].length(); j++) {
            cities[i][j] = tolower(cities[i][j]);
        }
        
        recent = 0;
        flag = false;
        //범위 안에 원하는 값을 찾는다.(일치하는 원소가 없을 경우 last가 리턴)
        //cache.end()와 같지 않는다면 이니까 cache 안에 cities[i]가 있다면
        if(find(cache.begin(), cache.end(), cities[i]) != cache.end()) {
            for(int j = 0; j < cache.size(); j++) {
                if(cache[j] == cities[i]) {
                    cache[j] = cities[i];
                    cache_recent[j] = count++;
                }
            }
            answer++;
        }
        //cache 안에 cities[i]가 없다면 => cache miss
        else {
            for(int j = 0; j < cache.size(); j++) {
                if(cache[j] == "") {
                    answer += 5;
                    cache[j] = cities[i];
                    cache_recent[j] = count++;
                    flag = true;
                    break;
                }
                else {
                    if(cache_recent[recent] >= cache_recent[j])
                        recent = j;
                }
            }
            if(flag == false) {
                cache[recent] = cities[i];
                cache_recent[recent] = count++;
                answer += 5;
            }
        }
    }
    return answer;
}
