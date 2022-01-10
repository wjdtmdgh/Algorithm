#include<iostream>
using namespace std;
int num;
int arr[9];
struct Node{
    int val;
    Node* prev;
    Node* next;
};
Node* head;
Node* tail;
void init(int val,int last){
    Node* newnode=new Node;
    newnode->val=val;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->prev=tail;
        tail->next=newnode;
    }
    tail=newnode;
    if(last==7){
        tail->next=head;
        head->prev=tail;
    }
}
void input(){
    cin>>num;
    for(int i=0;i<8;i++){
        cin>>arr[i];
        init(arr[i],i);
    }
}
void spin(){
    while(head->prev->val!=0){
        for(int i=1;i<=5;i++){
            head->val-=i;
            if(head->val<=0){
                head->val=0;
                head=head->next;
                break;
            }
            else{
                head=head->next;
            }
            //cout<<head->val<<' ';
        }
        //cout<<endl;
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    int count=10;
    while(count--){
        head=NULL;
        input();
        spin();
        cout<<'#'<<num<<' ';
        for(Node* p=head;p->val!=0;p=p->next){
            cout<<p->val<<' ';
        }
        cout<<0<<endl;
    }
    return 0;
}