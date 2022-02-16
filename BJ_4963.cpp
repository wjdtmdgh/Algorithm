#include<iostream>

using namespace std;

int arr[100][100];
int stack[110000][2];
int top = -1;
int N, M;
bool visit[100][100];
int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
int area;

void reset() {
    area = 0;
    top = -1;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            visit[i][j] = false;
        }
    }
}

void input() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
}

void dfs(int x, int y) {
    ++area;
    ++top;
    stack[top][0] = x;
    stack[top][1] = y;
    while (top > -1) {
        int curx = stack[top][0];
        int cury = stack[top][1];
        top--;
        if (!visit[curx][cury]) {
            visit[curx][cury] = true;
            for (int d = 0; d < 8; d++) {
                int new_x = curx + dx[d];
                int new_y = cury + dy[d];
                if (0 <= new_x && new_x < M && 0 <= new_y && new_y < N) {
                    if (arr[new_x][new_y] == 1) {
                        if (!visit[new_x][new_y]) {
                            top++;
                            stack[top][0] = new_x;
                            stack[top][1] = new_y;
                        }
                    }
                }
            }
        }
    }
}
int main() {
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) {
            break;
        }
        reset();
        input();
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == 1 && !visit[i][j]) {
                    dfs(i, j);
                }
            }
        }
        cout << area << endl;
    }
    return 0;
}