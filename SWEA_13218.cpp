#include<iostream>
using namespace std;
int main(){
    int N;
    int num;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>num;
        cout<<'#'<<i<<' ';
        cout<<num/3<<endl;
    }
}