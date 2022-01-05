#include<iostream>

using namespace std;

char arr[1000][1000];
int answer;

bool search_garo(int i, int j, int len) {
    for (int k = 0; k < len; k++) {
        if (arr[i][j + k] != arr[i][j + len - k - 1]) {
            return false;
        }
    }
    return true;
}

bool search_sero(int i, int j, int len) {
    for (int k = 0; k < len; k++) {
        if (arr[i + k][j] != arr[i + len - k - 1][j]) {
            return false;
        }
    }
    return true;
}

int main() {
    int count = 10;
    int num = 0;
    while (count--) {
        answer = 0;
        cin >> num;
        for (int i = 1; i <= 100; i++) {
            for (int j = 1; j <= 100; j++) {
                cin >> arr[i][j];
            }
        }

        for (int len = 100; len > 0; len--) {
            for (int i = 1; i <= 100; i++) {
                for (int j = 1; j <= 100; j++) {
                    if (search_garo(i, j, len)) {
                        answer = len;
                        i = j = 99999;
                        len = -1;
                        break;
                    }
                    if (search_sero(i, j, len)) {
                        answer = len;
                        i = j = 99999;
                        len = -1;
                        break;
                    }
                }
            }
        }
        cout << "#" << num << ' ' << answer << endl;
    }
    return 0;
}