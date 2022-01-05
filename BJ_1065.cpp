#include<stdio.h>

int Hansu(int n) {
    int i, a, b, c;
    int cnt = 0;
    if (n < 100) {
        return n;
    }
    else {
        for (i = 100; i <= n; i++) {
            a = i / 100;
            b = i % 100 / 10;
            c = i % 10;
            if (a - b == b - c) {
                cnt++;
            }

        }
        return cnt + 99;
    }
}
int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d", Hansu(n));

    return 0;
}