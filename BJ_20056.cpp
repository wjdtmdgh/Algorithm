#include <iostream>
#include <vector>
using namespace std;
int arr[51][51][4][4];//4개 기본옵션에다가 m,s,d,cnt

struct Fireball {
    int mass;
    int speed;
    int direction;
    Fireball(int m, int s, int d)
        : mass(m), speed(s), direction(d) {}
};

int N, M, K;
vector<Fireball> currMap[50][50];
vector<Fireball> nextMap[50][50];

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

void get_input() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) { //여기서 저장해두고 첫 명령
        int x, y, m, d, s;
        cin >> x >> y >> m >> s >> d; // 좌표, 질량, 스피드, 방향
        currMap[x - 1][y - 1].push_back(Fireball(m, s, d));
    }
}

void nextPosition(int& x, int& y, int d, int s) {
    x = x + dx[d] * s;
    y = y + dy[d] * s;
    x = (x + N * 1000) % N;
    y = (y + N * 1000) % N;
}

int main() {
    int cnt = 0;
    int all_m = 0, all_s = 0, all_d = 0;

    get_input();

    //이동명령
    for (int turn = 0; turn < K; turn++) {
        // 2 - 1. 이동하기
        for (int x = 0; x < N; x++) { // 이동 시작
            for (int y = 0; y < N; y++) {
                int len = currMap[x][y].size();
                for (int idx = 0; idx < len; idx++) {
                    int next_x = x;
                    int next_y = y;
                    nextPosition(next_x, next_y, currMap[x][y][idx].direction, currMap[x][y][idx].speed);
                    nextMap[next_x][next_y].push_back(currMap[x][y][idx]);
                }
                currMap[x][y].clear();
            }
        } // 이동 끝
        // 2 - 2. 파이어볼 합치기
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                int len = nextMap[x][y].size();
                if (len > 0) { // 현재 위치에 파이어볼이 한개라도 존재하는 경우
                    if (len == 1) { // 현재 위치에 파이어볼이 오직 하나 존재하는 경우
                        currMap[x][y].push_back(nextMap[x][y][0]);
                    }
                    else { // 파이어볼이 2개 이상 있는 경우(합치고 분해하는 과정 필요)
                        // x,y 위치의 첫 번째 파이어볼의 방향이 짝수인지 홀수인지 확인
                        int mass = 0;
                        int speed = 0;
                        bool even = nextMap[x][y][0].direction % 2 == 0 ? true : false; // false;
                        bool flag = true;
                        for (int idx = 0; idx < len; idx++) { // 현재 위치의 벡터에 저장된 모든 파이어볼 순회
                            mass += nextMap[x][y][idx].mass;
                            speed += nextMap[x][y][idx].speed;
                            if (nextMap[x][y][idx].direction % 2 == 0 != even) {
                                flag = false;
                            }
                        }
                        int nextMass = mass / 5;
                        int nextSpeed = speed / len;
                        if (nextMass > 0) {
                            if (flag) { // 전부 짝수이거나 전부 홀수
                                currMap[x][y].push_back(Fireball(nextMass, nextSpeed, 0));
                                currMap[x][y].push_back(Fireball(nextMass, nextSpeed, 2));
                                currMap[x][y].push_back(Fireball(nextMass, nextSpeed, 4));
                                currMap[x][y].push_back(Fireball(nextMass, nextSpeed, 6));
                            }
                            else {
                                currMap[x][y].push_back(Fireball(nextMass, nextSpeed, 1));
                                currMap[x][y].push_back(Fireball(nextMass, nextSpeed, 3));
                                currMap[x][y].push_back(Fireball(nextMass, nextSpeed, 5));
                                currMap[x][y].push_back(Fireball(nextMass, nextSpeed, 7));
                            }
                        }
                    }
                    nextMap[x][y].clear();
                }
            }
        }
    }
    int total = 0;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            int len = currMap[x][y].size();
            for (int idx = 0; idx < len; idx++) {
                total += currMap[x][y][idx].mass;
            }
        }
    }

    cout << total;

    return 0;
}