#include<iostream>
using namespace std;

int test_case, len, top, idx;
char* infix, * postfix, * k_stack;
int* k_int_stack;

bool k_is_digit(char c) {
    return '0' <= c && c <= '9';
}

int k_get_priority(char c) {
    // 0: trivial
    //      ~
    // 9: important
    switch (c) {
    case '+':
        return 1;
    case '*':
        return 2;
    case '(':
        return 3;
    case ')':
        return 0;
    }
}

bool k_can_push(char c1, char c2) {
    // c1: stack top
    // c2: token
    int priority_c1 = k_get_priority(c1);
    int priority_c2 = k_get_priority(c2);
    if (priority_c1 == 3 || priority_c2 == 3) return true;
    return priority_c1 < priority_c2;
}

int k_calc(int a, int b, char c) {
    switch (c) {
    case '+':
        return a + b;
    case '*':
        return a * b;
    }
}

int main(int argc, char** argv)
{
    for (test_case = 1; test_case <= 10; ++test_case)
    {
        cin >> len;
        infix = new char[len + 1];
        postfix = new char[len + 1];
        k_stack = new char[len + 1];
        k_int_stack = new int[len + 1];
        top = -1;
        idx = -1;
        cin >> infix;
        for (int i = 0; i < len; i++) { // infix to postfix
            if (k_is_digit(infix[i])) { // if token is operand
                postfix[++idx] = infix[i];
            }
            else { // if token is operator
                if (infix[i] == ')') {
                    while (top > -1 && k_stack[top] != '(') {
                        postfix[++idx] = k_stack[top--];
                    }
                    top--;
                }
                else {
                    while (top > -1 && !k_can_push(k_stack[top], infix[i])) {
                        postfix[++idx] = k_stack[top--];
                    }
                    k_stack[++top] = infix[i];
                }
            }
        }
        while (top > -1) {
            postfix[++idx] = k_stack[top--];
        }
        top = -1;
        for (int i = 0; i <= idx; i++) {
            if (k_is_digit(postfix[i])) {
                k_int_stack[++top] = postfix[i] - '0';
            }
            else {
                char op = postfix[i];
                int n1 = k_int_stack[top--];
                int n2 = k_int_stack[top--];
                k_int_stack[++top] = k_calc(n1, n2, op);
            }
        }
        cout << '#' << test_case << ' ' << k_int_stack[top] << '\n';
        delete[] k_stack;
        delete[] postfix;
        delete[] infix;
    }
    return 0;
}