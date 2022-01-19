#include<iostream>

using namespace std;

int main() {
    int N;
    int val;
    cin >> N;
    int answer = N;

    for (int i = 1; i <= N; i++) {
        cin >> val;
        if (val == 1) {
            answer--;
        }
        for (int j = 2; j < val; j++) {
            if (val % j == 0) {
                answer--;
                break;
            }
        }
    }
    cout << answer;

    return 0;
}