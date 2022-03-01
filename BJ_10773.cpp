#include<iostream>
using namespace std;
int stack[50000000];
int top=-1;
int cnt;
void push(int val){
  cnt++;
  stack[++top]=val;
}
int pop(){
  if(top>-1){
    cnt--;
    return stack[top--];
  }
  return -1;
}
int main(){
  int sum=0;
  int N;
  int num;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>num;
    if(num==0){
      pop();
    }
    else{
      push(num);
    }
  }
  for(int i=0;i<cnt;i++){
    sum+=stack[i];
  }
  cout<<sum;
  return 0;
}