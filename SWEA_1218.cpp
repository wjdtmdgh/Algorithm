#include<iostream>
using namespace std;
int N;
int num=0;
char arr[1001];
int stack[1001];
int top=-1;
bool value=true;
int cnt;
void push(char val){
    top++;
    stack[top]=val;
    cnt++;
}
void pop(int check){
    if(arr[check]==')'){
        if(stack[top]!='('){
            //cout<<check<<' ';
            value=false;
        }
    }
    else if(arr[check]=='}'){
        if(stack[top]!='{'){
            //cout<<check<<' ';
            value=false;
        }
    }
    else if(arr[check]==']'){
        if(stack[top]!='['){
            //cout<<check<<' ';
            value=false;
        }
    }
    else if(arr[check]=='>'){
        if(stack[top]!='<'){
            //cout<<check<<' ';
            value=false;
        }
    }
    top--;
    cnt--;
    //cout<<"value"<<value<<' ';
}
void reset(){
    for(int i=0;i<300;i++){
        arr[i]=0;
    }
    top=-1;
    cnt=0;
    value=true;
}
int main(){
    freopen("input.txt", "r", stdin);
    int count=10;
    while(count--){
        reset();
        num++;
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>arr[i];
            //cout<<value<<' ';
            if(arr[i]=='('||arr[i]=='{'||arr[i]=='['||arr[i]=='<'){
                push(arr[i]);
                //cout<<top<<' ';
            }
            else if(arr[0]==')'||arr[0]=='}'||arr[0]==']'||arr[0]=='>'){
                value=false;
                break;
            }
            else{
                pop(i);
                //cout<<top<<' ';
            }
        }
        if(cnt==0){
            cout<<"#"<<num<<' '<<value<<endl;
        }
        else{
            value=false;
            cout<<"#"<<num<<' '<<value<<endl;
        }
    }
    return 0;
}