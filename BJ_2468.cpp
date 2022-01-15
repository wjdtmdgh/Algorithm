#include<iostream>
using  namespace std;
int N;
int arr[101][101];
int samearr[101][101];
int stack[110000][2];
int top;
bool visit[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int area;
int safe_all_area;
int cnt;

void reset() {
    top = -1;
    area = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = samearr[i][j];
            visit[i][j] = false;
        }
    }
}
void dfs() {
    while (top > -1) {
        int curx = stack[top][0];
        int cury = stack[top][1];
        top--;
        if (!visit[curx][cury]) {
            visit[curx][cury] = true;
            for (int d = 0; d < 4; d++) {
                int new_x = curx + dx[d];
                int new_y = cury + dy[d];
                if (0 <= new_x && new_x < N && 0 <= new_y && new_y < N) {
                    if (arr[new_x][new_y] > 0 && !visit[new_x][new_y]) {
                        top++;
                        stack[top][0] = new_x;
                        stack[top][1] = new_y;
                    }
                }
            }
        }
    }
    area++;
}
void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            samearr[i][j] = arr[i][j];
        }
    }
    for (int h = 0; h <= 100; h++) {
        if (safe_all_area < area) {
            safe_all_area = area;
        }
        reset();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] -= h;
                if (arr[i][j] < 0) {
                    arr[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] > 0 && !visit[i][j]) {
                    top++;
                    stack[top][0] = i;
                    stack[top][1] = j;
                    dfs();
                }
            }
        }
    }
    cout << safe_all_area;
}
int main() {
    input();
    return 0;
}