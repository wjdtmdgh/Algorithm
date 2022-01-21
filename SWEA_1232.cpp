#include <iostream>
 
#define PLUS -2147483648
#define MINUS -2147483647
#define MUL -2147483646
#define DIV -2147483645
 
using namespace std;
 
char val[11];
int test_case, N, idx;
// 0: val, 1: left child index, 2: right child index
int tree[1001][3];
 
int search(char val) {
    switch (val) {
    case '+':
        return PLUS;
    case '-':
        return MINUS;
    case '*':
        return MUL;
    case '/':
        return DIV;
    }
}
 
 
void get_input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> idx;
        cin >> val;
        if (val[0] >= '0' && val[0] <= '9') {
            int num = 0;
            for (int i = 0; val[i] != '\0'; i++) {
                num *= 10;
                num += val[i] - '0';
            }
            tree[idx][0] = num;
        }
        else {
            tree[idx][0] = search(val[0]);
            cin >> tree[idx][1] >> tree[idx][2];
        }
    }
}
 
double postorder(int node_index) {
    double answer = 0;
    if (tree[node_index][0] <= DIV) { // 연산자인 경우
        double operand1 = postorder(tree[node_index][1]);
        double operand2 = postorder(tree[node_index][2]);
        switch (tree[node_index][0]) {
        case PLUS:
            answer = operand1 + operand2;
            break;
        case MINUS:
            answer = operand1 - operand2;
            break;
        case MUL:
            answer = operand1 * operand2;
            break;
        case DIV:
            answer = operand1 / operand2;
            break;
        }
    }
    else { // 숫자 노드인 경우
        answer = (double)tree[node_index][0];
    }
    return answer;
}
 
int main(void) {
    for (test_case = 1; test_case <= 10; ++test_case) {
        get_input();
 
 
        cout << '#' << test_case << ' ' << postorder(1) << endl;
    }
    return 0;
}