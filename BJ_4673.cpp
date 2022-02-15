#include<iostream>
using namespace std;
bool visit[10001];
int selftnumbers(int val){
    int cnt;
    int a,b,c,d;
    a=val/1000;
    b=val/100-(a*10);
    c=(val%100)/10;
    d=val%10;
    //cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<cnt<<endl;
    cnt=a+b+c+d+val;
    visit[cnt]=true;
    return cnt;
}
void remove(int num){
    while(num<10000){
        num=selftnumbers(num);
        //cout<<num<<endl;
        // if(visit[num]==true){
        //     cout<<num<<endl;
        // }
    }
}
int main(){
    for(int i=1;i<=10000;i++){
        remove(i);
    }
    for(int j=1;j<=10000;j++){
        if(visit[j]==false){
            cout<<j<<endl;
        }
    }
    return 0;
}