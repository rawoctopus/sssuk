/*
 - 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
 - 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
 - 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 101
using namespace std;

typedef pair<int, int> p;

int N, K, L;
int map[MAX][MAX]; //사과x 0, 뱀 위치1, 사과o 2,
int dy[4] = {1, -1, 0, 0}; //아래, 위, 오른쪽, 왼쪽
int dx[4] = {0, 0, 1, -1};

vector<pair<int, char>> directionInfo;

int setDir(int curDir, char nextDir) {
    //방향 전환이 오른쪽으로
    if(nextDir == 'D') {
        if(curDir == 0)
            return 3;
        else if(curDir == 1)
            return 2;
        else if(curDir == 2)
            return 0;
        else
            return 1;
    }
    //방향 전환이 왼쪽으로
    else {
        if(curDir == 0)
            return 2;
        else if(curDir == 1)
            return 3;
        else if(curDir == 2)
            return 1;
        else
            return 0;
    }
}

void simulation() {
    vector<p> snake;

    int x = 0, y = 0; //머리 위치
    int d = 2; //초기 방향
    int sec = 0;

    int vi = 0; //시간 벡터 인덱스
    bool v_flag = false; //벡터가 끝나면 1이됨

    map[y][x] = 1;
    snake.push_back(make_pair(y, x));

    while(true) {
        if(!v_flag && sec == directionInfo[vi].first) {
            //다음 명령 수행하기 바로 전이 되면
            d = setDir(d, directionInfo[vi++].second);
            //다음 명령을 수행해야 할 시간이 되면
            if(vi == directionInfo.size())
                v_flag = 1;
        }

        //다음 좌표
        int ny = y + dy[d];
        int nx = x + dx[d];

        if(ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] == 1)
            break;

        else if(map[ny][nx] == 0) {
            map[snake[0].first][snake[0].second] = 0;
            snake.erase(snake.begin());
        }

        //스네이크 머리 갱신 및 맵 갱신
        y = ny;
        x = nx;
        map[y][x] = 1;
        snake.push_back(make_pair(y, x)); //스네이크 위치를 계속 넣어줌.

        sec++;
    }

    cout << sec + 1 << endl;
}

int main() {
    cout << "start" << endl;

    cin >> N >> K;
    memset(map, 0, sizeof(map));
    map[0][0] = 1; //뱀 초기 위치

    //사과 위치
    for(int i = 0; i < K; i++) {
        int y,x;
        cin >> y >> x;
        map[y-1][x-1] = 2;
    }

    cin >> L;

    //뱀의 방향 전환 정보
    for(int i = 0; i < L; i++) {
        int X;
        char C;
        cin >> X >> C;
        directionInfo.push_back(make_pair(X, C));
    }
    simulation();
    //cout << simulation() << endl;

    return 0;
}

