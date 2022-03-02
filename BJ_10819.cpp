#include<iostream>
#include<cmath>

using namespace std;

int arr[9];

long long int factorial(int N) {
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
    int i = N - 1;
    while (i > 0 && arr[i - 1] >= arr[i]) {
        i--;
    }
    if (i == 0) return false;
    int j = N - 1;
    while (arr[i - 1] >= arr[j]) {
        j--;
    }
    swap(arr[i - 1], arr[j]);
    j = N - 1;
    while (i < j) {
        swap(arr[i], arr[j]);
        i += 1;
        j -= 1;
    }
    return true;
}

int main(void) {
    int N;
    long long int F;
    int val;
    int max_val = 0;
    int cnt;
    int qnt;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    F = factorial(N);
    for (int i = 0; i < F; i++) {
        qnt = 0;
        for (int j = 0; j < N - 1; j++) {
            val = arr[j] - arr[j + 1];
            cnt = abs(val);
            qnt += cnt;
        }
        if (next_number(N)) {
            if (max_val < qnt) {
                max_val = qnt;
            }
        }
    }
    cout << max_val;
    return 0;
}