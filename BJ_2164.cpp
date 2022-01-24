#include<iostream>
using namespace std;
int store;
struct Node{
  int val;
  Node* next;
  Node* prev;
};
Node* head;
Node* tail;
Node* cursor;
void push(int val){
  Node* newnode=new Node;
  newnode->val=val;
  if(head==NULL){
    head=newnode;
  }
  else{
    tail->next=newnode;
    newnode->prev=tail;
  }
  tail=newnode;
}
void pop(){
  head=head->next;
  store=head->val;
  //cout<<'#'<<store<<endl;
}
void card(int N){
  int K=N-1;
  while(K--){
    pop();
    push(store);
    pop();
  }
  cout<<head->val;
}
int main(){
  int N;
  cin>>N;
  for(int i=1;i<=N;i++){
    push(i);
  }
  card(N);
  return 0;
}