#include <iostream>

#define N 9

using namespace std;

int arr[9];

int main(void) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    for (int i = 0; i < N-1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (sum - arr[i] - arr[j] == 100) {
                for (int k = 0; k < N; k++) {
                    if (i == k || j == k) continue;
                    cout << arr[k] << '\n';
                }
                return 0;
            }
        }
    }

    return 0;
}