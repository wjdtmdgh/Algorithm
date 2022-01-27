#include <iostream>
#include <cstring>

using namespace std;

int T, test_case;
char str1[16], str2[16];

int main(int argc, char** argv) {
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> str1 >> str2;
        bool res = true;
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        str1[len1] = 'a';
        str1[len1 + 1] = '\0';
        if (strcmp(str1, str2) == 0) {
            cout << '#' << test_case << ' ' << 'N' << '\n';
        }
        else {
            cout << '#' << test_case << ' ' << 'Y' << '\n';
        }
    }
    return 0;
}