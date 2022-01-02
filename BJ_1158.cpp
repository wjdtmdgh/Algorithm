#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node* prev;
};
Node* head=NULL;
Node* tail=NULL;
void initmembers(int val,int last){
    Node* newnode=new Node;
    newnode->val=val;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
    }
    tail=newnode;
    if(tail->val==last){
        tail->next=head;
        head->prev=tail;
    }
}
void remove(int last,int k){
    Node* cursor=head->prev;
    int over=last;
    cout<<'<';
    while(over--){
        int good=k;
        while(good--){
            cursor=cursor->next;
        }
        if(over==0){
            cout<<cursor->val;
        }
        else{
            cout<<cursor->val<<','<<' ';
        }
        cursor->prev->next=cursor->next;
        cursor->next->prev=cursor->prev;
    }
    cout<<'>';
}
int main(){
    char arr[100000];
    int k;
    int abc;
    cin>>abc>>k;
    int len=abc;
    int cnt=0;
    for(int i=1;i<=len;i++){
        initmembers(i,len);
    }
    remove(len,k);
    return 0;
}