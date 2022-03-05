#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

bool next_permutation(int* arr, int n) {
    int i = n - 1;
    while (i > 0 && arr[i - 1] > arr[i]) {
        i--; 
    }
    if (i == 0) return false; // 사전상으로 가장 마지막 순열
    int j = n - 1;
    while (arr[i - 1] > arr[j]) {
        j--;
    }
    swap(arr[i - 1], arr[j]);
    j = n - 1;
    while (i < j) {
        swap(arr[i], arr[j]);
        i += 1;
        j -= 1;
    }
    return true;
}

int main(void) {
    int n;
    cin >> n;
    int* permutation = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
    }
    if (next_permutation(permutation, n)) {
        for (int i = 0; i < n; i++) {
            cout << permutation[i] << ' ';
        }
    }
    else {
        cout << -1;
    }
    return 0;
}