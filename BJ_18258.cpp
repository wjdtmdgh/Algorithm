#include<iostream>
using namespace std;
int queue[2000001];
int front=-1;
int rear=-1;
int N;
int val;
int head;
int sizee;
bool empty(){
    if(front==rear){
        return false;
    }
    else{
        return true;
    }
}
void push(int val){
    sizee++;
    rear++;
    queue[rear]=val;
}
int pop(){
    head++;
    sizee--;
    front++;
    return queue[front];
}
int main(){
    cin.tie(NULL);
	cin.sync_with_stdio(false);
    string arr;
    cin>>N;
    while(N--){
        cin>>arr;
        if(arr=="push"){
            cin>>val;
            push(val);
        }
        else if(arr=="front"){
            if(!empty()){
                cout<<-1<<'\n';
            }
            else{
                cout<<queue[head]<<'\n';
            }
        }
        else if(arr=="back"){
            if(!empty()){
                cout<<-1<<'\n';
            }
            else{
                cout<<queue[rear]<<'\n';
            }
        }
        else if(arr=="size"){
            cout<<sizee<<'\n';
        }
        else if(arr=="empty"){
            if(!empty()){
                cout<<1<<'\n';
            }
            else{
                cout<<0<<'\n';
            }
        }
        else{
            if(!empty()){
                cout<<-1<<'\n';
            }
            else{
                cout<<pop()<<'\n';
            }
        }
    }
    return 0;   
}