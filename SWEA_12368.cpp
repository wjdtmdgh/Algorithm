#include<iostream>
using namespace std;
int main(){
    int N;
    int x,y;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>x>>y;
        if(x+y>=24){
            cout<<'#'<<i<<' '<<x+y-24<<'\n';
        }
        else{
            cout<<'#'<<i<<' '<<x+y<<'\n';
        }
    }
    return 0;
}