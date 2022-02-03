#include<iostream>
using namespace std;
int main(){
    int test;
    int N;
    cin>>test;
    for(int i=1;i<=test;i++){
        cin>>N;
        double x,y,cnt=0;
        for(int j=0;j<N;j++){
            cin>>x>>y;
            cnt+=(x*y);
        }
        printf("%c%d %.6lf",'#',i,cnt);
    }
    return 0;
}