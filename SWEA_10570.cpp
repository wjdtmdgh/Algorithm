#include<iostream>
#include<cmath>
using namespace std;
int allcount;
int cnt;
void returnmoon(int num, int val) {
    int test1 = num;
    int test2 = val;
    int size1 = 0;
    int size2 = 0;
    while (test1 > 0) {
        test1 = test1 / 10;
        size1++;
    }
    while (test2 > 0) {
        test2 = test2 / 10;
        size2++;
    }
    test1 = num;
    test2 = val;
    int result1 = 0;
    int result2 = 0;
    while (size1--) {
        result1 = result1 * 10 + test1 % 10;
        test1 /= 10;
    }
    while (size2--) {
        result2 = result2 * 10 + test2 % 10;
        test2 /= 10;
    }
    int test1_1 = num;
    int test2_2 = val;
    if (test1_1 == result1 && test2_2 == result2) {
        cnt += 1;
        allcount = cnt;
    }
}
void rootcheck(int val) {
    double num = sqrt(val);
    //cout<<num<<' '<<(int)num<<endl;
    if (num - (int)num == 0) {
        //cout<<num<<' '<<val;
        returnmoon(num, val);
    }
}
int main() {
    int N;
    int a, b;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        allcount = 0;
        cnt = 0;
        cin >> a >> b;
        for (int i = a; i <= b; i++) {
            rootcheck(i);
        }
        cout << '#' << i << ' ' << allcount << endl;
    }
    return 0;
}