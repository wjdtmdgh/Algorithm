#include<iostream>
 
using namespace std;
 
char map[4][5];
bool p1, p2;
int cnt;
 
void crossCheck() {
    int p1_cnt = 0;
    int p2_cnt = 0;
    for (int i = 0; i < 4; i++) {
        if (map[i][i] == 'X') {
            p1_cnt++;
        }
        else if (map[i][i] == 'O') {
            p2_cnt++;
        }
        else if (map[i][i] == 'T') {
            p1_cnt++;
            p2_cnt++;
        }
    }
    if (p1_cnt == 4) {
        p1 = true;
    }
    if (p2_cnt == 4) {
        p2 = true;
    }
    p1_cnt = 0;
    p2_cnt = 0;
    for (int i = 0; i < 4; i++) {
        if (map[i][3 - i] == 'X') {
            p1_cnt++;
        }
        else if (map[i][3 - i] == 'O') {
            p2_cnt++;
        }
        else if (map[i][3 - i] == 'T') {
            p1_cnt++;
            p2_cnt++;
        }
    }
    if (p1_cnt == 4) {
        p1 = true;
    }
    if (p2_cnt == 4) {
        p2 = true;
    }
}
 
void verticalCheck() {
    for (int i = 0; i < 4; i++) {
        int p1_cnt = 0;
        int p2_cnt = 0;
        for (int j = 0; j < 4; j++) {
            if (map[j][i] == 'X') {
                p1_cnt++;
            }
            else if (map[j][i] == 'O') {
                p2_cnt++;
            }
            else if (map[j][i] == 'T') {
                p1_cnt++;
                p2_cnt++;
            }
        }
        if (p1_cnt == 4) {
            p1 = true;
        }
        if (p2_cnt == 4) {
            p2 = true;
        }
    }
}
 
void horizontalCheck() {
    for (int i = 0; i < 4; i++) {
        int p1_cnt = 0;
        int p2_cnt = 0;
        for (int j = 0; j < 4; j++) {
            if (map[i][j] == 'X') {
                p1_cnt++;
            }
            else if (map[i][j] == 'O') {
                p2_cnt++;
            }
            else if (map[i][j] == 'T') {
                p1_cnt++;
                p2_cnt++;
            }
        }
        if (p1_cnt == 4) {
            p1 = true;
        }
        if (p2_cnt == 4) {
            p2 = true;
        }
    }
}
 
void countDot() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (map[i][j] == '.') {
                cnt++;
            }
        }
    }
}
 
int main(int argc, char** argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        p1 = p2 = false;
        cnt = 0;
        for (int i = 0; i < 4; i++) {
            cin >> map[i];
        }
        horizontalCheck();
        verticalCheck();
        crossCheck();
        countDot();
 
        if (p1 && p2) {
            cout << '#' << test_case << ' ' << "Draw\n";
        }
        else if (p1) {
            cout << '#' << test_case << ' ' << "X won\n";
        }
        else if (p2) {
            cout << '#' << test_case << ' ' << "O won\n";
        }
        else {
            if (cnt == 0) {
                cout << '#' << test_case << ' ' << "Draw\n";
            }
            else {
                cout << '#' << test_case << ' ' << "Game has not completed\n";
            }
        }
    }
    return 0;
}