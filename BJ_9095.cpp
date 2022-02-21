#include <iostream>

using namespace std;

int main(void) {
    int n, T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        int sum = 0;
        int count = 0;
        for (int x0 = 1; x0 <= 3; x0++) {
            sum = x0; // 1
            if (sum == n) count++;
            for (int x1 = 1; x1 <= 3; x1++) {
                sum += x1; // 2
                if (sum == n) count++;
                for (int x2 = 1; x2 <= 3; x2++) {
                    sum += x2; // 3
                    if (sum == n) count++;
                    for (int x3 = 1; x3 <= 3; x3++) {
                        sum += x3; // 4
                        if (sum == n) count++;
                        for (int x4 = 1; x4 <= 3; x4++) {
                            sum += x4; // 5
                            if (sum == n) count++;
                            for (int x5 = 1; x5 <= 3; x5++) {
                                sum += x5; // 6 
                                if (sum == n) count++;
                                for (int x6 = 1; x6 <= 3; x6++) {
                                    sum += x6; // 7
                                    if (sum == n) count++;
                                    for (int x7 = 1; x7 <= 3; x7++) {
                                        sum += x7; // 8
                                        if (sum == n) count++;
                                        for (int x8 = 1; x8 <= 3; x8++) {
                                            sum += x8; // 9
                                            if (sum == n) count++;
                                            for (int x9 = 1; x9 <= 3; x9++) {
                                                sum += x9; // 10
                                                if (sum == n) count++;
                                                sum -= x9;
                                            }
                                            sum -= x8;
                                        }
                                        sum -= x7;
                                    }
                                    sum -= x6;
                                }
                                sum -= x5;
                            }
                            sum -= x4;
                        }
                        sum -= x3;
                    }
                    sum -= x2;
                }
                sum -= x1;
            }
            sum -= x0;
        }
        cout << count << endl;
    }
    return 0;
}