#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    
    vector<string> answer(n);
    for (int i = 0; i < n; i++) {
        int k = arr1[i] | arr2[i];
        answer[i].assign(" ",n);
        for (int j = n - 1; j >= 0; j--) {
            if (k % 2 == 0)
                answer[i][j] = ' ';
            else
                answer[i][j] = '#';
            k /= 2;
            
        }
    }
    return answer;
}
