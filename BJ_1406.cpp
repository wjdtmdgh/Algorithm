#include <iostream>
#include <string.h>
using namespace std;

struct Node {
    char val;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;
Node* cursor = NULL;

void addNode(char c) {
    Node* newNode = new Node;
    newNode->val = c;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        head = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
    }
    tail = newNode;
}

int main() {
    char buf[100001];
    cin >> buf;

    int len = strlen(buf);
    for (int i = 0; i < len; i++) {
        addNode(buf[i]);
    }
    addNode('$');
    cursor = tail;
    int M;
    cin >> M;
    char cmd;
    char val;
    for (int i = 0; i < M; i++) {
        cin >> cmd;
        if (cmd == 'L') {
            if (cursor->prev != NULL) {
                cursor = cursor->prev;
            }
        }
        else if (cmd == 'D') {
            if (cursor->next != NULL) {
                cursor = cursor->next;
            }
        }
        else if (cmd == 'B') {
            if (cursor != head) {
                Node* tmp = cursor->prev;
                if (tmp == head) {
                    head = cursor;
                    head->prev = NULL;
                }
                else {
                    tmp->prev->next = cursor;
                }
                cursor->prev = tmp->prev;
                delete tmp;
            }
        }
        else {
            cin >> val;
            Node* newNode = new Node;
            newNode->val = val;
            newNode->next = cursor;
            newNode->prev = cursor->prev;
            if (cursor == head) {
                head = newNode;
            }
            else {
                cursor->prev->next = newNode;
            }
            cursor->prev = newNode;
        }
    }
    for (Node* p = head; p->val != '$'; p = p->next) {
        cout << p->val;
    }


    return 0;
}