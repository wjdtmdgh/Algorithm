#include<iostream>

using namespace std;

int arr[100][100];
int trr[10000];
int start;

int factorial(int N) {
    if (N == 0) {
        return 1;
    }
    else {
        return N * factorial(N - 1);
    }
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

bool next_number(int N) {
    int i = N;
    while (i > 1 && trr[i - 1] >= trr[i]) {
        i--;
    }
    if (i == 1) return false;
    int j = N;
    while (trr[i - 1] >= trr[j]) {
        j--;
    }
    swap(trr[i - 1], trr[j]);
    j = N;
    while (i < j) {
        swap(trr[i], trr[j]);
        i += 1;
        j -= 1;
    }
    return true;
}

int main() {
    int N;
    int F;
    int val;
    int max_val = 214748364;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        trr[i] = i;
    }
    trr[N + 1] = trr[1];
    F = factorial(N);
    for (int i = 1; i <= F; i++) {
        bool ok = true;
        val = 0;
        for (int j = 1; j <= N; j++) {
            if (arr[trr[j]][trr[j + 1]] == 0) {
                ok = false;
                break;
            }
            val += arr[trr[j]][trr[j + 1]];
        }
        if (ok && max_val > val) {
            max_val = val;
        }
        next_number(N);
        trr[N + 1] = trr[1];
    }
    cout << max_val;
    return 0;
}