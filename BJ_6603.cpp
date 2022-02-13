#include<iostream>
using namespace std;
int arr[500000];
int trr[5000000];

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

bool next_number(int N) {
    int i = N - 1;
    while (trr[i - 1] >= trr[i]) {
        i--;
    }
    if (i == 0)return false;
    int j = N - 1;
    while (trr[i - 1] >= trr[j]) {
        j--;
    }
    swap(trr[i - 1], trr[j]);
    j = N - 1;
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
    while (true) {
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < 6; i++) {
            trr[i] = 1;
        }
        for (int i = 6; i < N; i++) {
            trr[i] = 2;
        }
        while (true) {
            for (int j = 0; j < N; j++) {
                if (trr[j] == 1) {
                    cout << arr[j] << ' ';
                }
            }
            cout << endl;
            if (!next_number(N)) {
                break;
            }
        }
        cout << '\n';
    }
    return 0;
}