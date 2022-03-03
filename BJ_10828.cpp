#include<iostream>
using namespace std;
int top=-1;
int arr[100000];
void push(int val){
    arr[++top]=val;
}
void pop(){
    if(arr[top]==0){
        cout<<-1<<endl;
    }
    else{
        cout<<arr[top--]<<endl;
    }
}
void size(){
    cout<<top+1<<endl;
}
void empty(){
    if(arr[top]==0){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
}
void Top(){
    if(arr[top]==0){
        cout<<-1<<endl;
    }
    else{
        cout<<arr[top]<<endl;
    }
}

int main(){
    int num;
    cin>>num;
    while(num--){
        string name;
        cin>>name;
        int val;
        if(name=="push"){
            cin>>val;
            push(val);
        }
        if(name=="pop"){
            pop();
        }
        if(name=="size"){
            size();
        }
        if(name=="top"){
            Top();
        }
        if(name=="empty"){
            empty();
        }

    }
    return 0;
}