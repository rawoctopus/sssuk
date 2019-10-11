#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 사람들의 무게가 들어있는 배열을 정렬한 다음, 최소와 최대값을 비교하여 limit가 넘지 않는다면 answer(배)를 1증가시키고 최소값도 1증가시켜 다음 최소값을 사용하도록 한다.
 그외의 경우는 이미 최소값과 더했을 때 배에 태울 수 없는 경우기 때문에 최대값에 해당하는 사람을 태우게되므로 answer을 1 증가시킨다.
 for문을 빠져나왔을 때 i와 j가 같다면 남는 1명을 태우기위해 answer을 1증가시키도록 한다.
 */
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int size = (int)people.size();
    int i = 0, j = 0;
    
    for(i = size-1; i > j; i--) {
        //최소값과 최대값 더한값이 limit가 넘지 않으면 ++
        if(people[i] + people[j] <= limit) {
            j++;
            answer++;
        }
        //이미 최소값과 더했을 때 배에 태울 수 없는 경우기 때문에 최대값에 해당하는 사람을 태우게 되므로
        else
            answer++;
    }
    //비교대상(인덱스)이 자기 자신이 되는 경우
    if(i == j) answer++;
    
    
    return answer;
}

int main() {
    vector<int> v1, v2;
    v1.push_back(70);
    v1.push_back(50);
    v1.push_back(80);
    v1.push_back(50);
    
    cout << solution(v1, 100) << endl;
    
    v2.push_back(70);
    v2.push_back(80);
    v2.push_back(50);
    
    cout << solution(v2, 100) << endl;
    return 0;
}
