#include<iostream>
using namespace std;
int recursive(int val,int mul){
    if(mul==0){
        return 1;
    }
    mul-=1;
    return val*recursive(val,mul);
}
int main(){
    freopen("input.txt", "r", stdin);
    int count=10;
    int num;
    int N,multiple;
    int answer;
    while(count--){
        cin>>num;
        cin>>N>>multiple;
        answer=recursive(N,multiple);
        cout<<"#"<<num<<' '<<answer<<endl;
    }
    return 0;
}