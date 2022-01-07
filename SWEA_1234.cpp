#include<iostream>
using namespace std;
char stack[11000];
int top=-1;
char arr[1001];
void reset(){
    top=-1;
    for(int i=0;i<1000;i++){
        stack[i]=0;
        arr[i]=0;
    }
}
void push(char val){
    top++;
    stack[top]=val;
    //cout<<stack[top];
}
void pop(){
    top--;
}
int main(){
     freopen("input.txt", "r", stdin);
    int count=10;
    int N;
    int num=0;
    while(count--){
        reset();
        num+=1;
        cin>>N;
        cin>>arr[0];
        push(arr[0]);
        for(int i=1;i<N;i++){
            cin>>arr[i];
            //cout<<top<<' '<<i<<endl;
            if(stack[top]==arr[i]){
                //cout<<top<<' ';
                pop();
            }
            else{
                push(arr[i]);
            }
        }
        cout<<"#"<<num<<' ';
        for(int i=0;i<=top;i++){
            cout<<stack[i];
        }
        cout<<endl;
    }
    return 0;
}