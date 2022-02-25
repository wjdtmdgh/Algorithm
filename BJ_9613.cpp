#include<iostream>
using namespace std;
int* stack;
int top = -1;
long long int sum;
int gcd;
int len;
void reset() {
    sum = 0;
    gcd = 0;
    len = 0;
    top = -1;
}
void input(int val) {
    len++;
    stack[++top] = val;
}
int GCD(int val1, int val2) {
    if (val2 == 0) {
        return val1;
    }
    else {
        return GCD(val2, val1 % val2);
    }
}
void GCD_search(int len, int* stack) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            gcd = GCD(stack[i], stack[j]);
            sum += gcd;
        }
    }
}
int main() {
    stack = new int[101];
    int test;
    int k;
    int n;
    cin >> test;
    while (test--) {
        cin >> k;
        while (k--) {
            cin >> n;
            input(n);
        }
        GCD_search(len, stack);
        cout << sum << endl;
        reset();
    }
}