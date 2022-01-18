#include<iostream>

using namespace std;

int arr[1001][1001];
int stack[10000001];
int top = -1;
bool visit[10000001];
int N, M;
int cnt;
int krr[10000001];

void dfs() {
    while (top > -1) {
        int cur = stack[top];
        top--;
        if (!visit[cur]) {
            visit[cur] = true;
            //cout<<'#'<<cur<<' '<<endl;
            for (int i = N; i >= 1; i--) {
                if (arr[cur][i] == 1) {
                    top++;
                    stack[top] = i;
                }
            }
        }
    }
}

int main() {
    cin >> N;
    cin >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= M; i++) {
        cin >> krr[i];
    }

    top++;
    stack[top] = krr[1];
    dfs();

    for (int i = 1; i <= M; i++) {
        if (visit[krr[i]] == true) {
            cnt++;
        }
    }
    if (cnt == M) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}