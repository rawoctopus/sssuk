/*
 1. 속한 노래가 많이 재생된 장르를 먼저 수록합니다.
 2. 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
 3. 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> playCnt_genre; //장르별 횟수
    
    //장르만 중복 없이 저장(횟수는 0으로 초기화)
    for(int i = 0; i < genres.size(); i++) {
        if(i == 0)
            playCnt_genre.insert(make_pair(genres[i], 0));
        else {
            if(playCnt_genre.count(genres[i]) == 0)
                playCnt_genre.insert(make_pair(genres[i], 0));
        }
    }
    
    //장르별 최대 횟수 카운트
    for(int i = 0; i < genres.size(); i++) {
        playCnt_genre[genres[i]] = playCnt_genre[genres[i]] + plays[i];
    }
    
    //sorting하기 위해 벡터에 횟수와 장르 넣어줌
    vector<pair<int, string>> ordered;
    for(auto x : playCnt_genre) {
        ordered.push_back(make_pair(x.second, x.first));
    }
    sort(ordered.begin(), ordered.end()); //장르별로 재생횟수 오름차순 횟수 소팅됨.
    //ordered[i].second가 장르임
    
    //first=노래재생횟수, second.first=index, second.second=장르
    vector<pair<int, pair<int, string>>> mostSongsPerGenre;
    
    //각 장르별로 재생횟수 많은 노래 2개 뽑아내기
    for(int i = (int)ordered.size()-1; i >= 0; i--) {
        for(int j = 0; j < genres.size(); j++) {
            if(ordered[i].second == genres[j]) {
                mostSongsPerGenre.push_back(make_pair(plays[j], make_pair(j, genres[j])));
            }
        }
    }
    //각 장르별로 재생횟수별로 오름차순 소팅
    sort(mostSongsPerGenre.begin(), mostSongsPerGenre.end());
    
    for(int i = (int)ordered.size()-1; i >= 0; i--) {
        int cnt = 0; //장르별 두가지씩 체크하기 위함.
        for(int j = (int)mostSongsPerGenre.size()-1; j>=0; j--) {
            if(ordered[i].second == mostSongsPerGenre[j].second.second) {
                if(cnt == 2) {
                    if(mostSongsPerGenre[j-1].first == mostSongsPerGenre[j-2].first) {
                        if(answer[answer.size()-1] < answer[answer.size()-2]) {
                            int temp = answer[answer.size()-1];
                            answer[answer.size()-1] = answer[answer.size()-2];
                            answer[answer.size()-2] = temp;
                        }
                    }
                    continue;
                }
                
                answer.push_back(mostSongsPerGenre[j].second.first);
                cnt++;
            }
        }
    }
    
    return answer;
}
