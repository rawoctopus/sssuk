#include <vector>
#include <string>

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.resize(prices.size());
    
    for(int i = 0; i < prices.size(); i++) {
        for(int j = i+1; j < prices.size(); j++) {
            if(prices[i] <= prices[j])
                answer[i]++;
            else {
                answer[i]++;
                break;
            }
        }
    }
    
    return answer;
}
