#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int N;
    string arr;
    int cnt=0;
    int answer=0;
    cin>>N;
    for(int test=1;test<=N;test++){
        cin>>arr;
        cnt=0;
        answer=0;
        for(int i=0;i<3;i++){
            for(int j=i+1;j<4;j++){
                if(arr[i]==arr[j]){
                    cnt+=2;
                }
            }
            if(cnt==2){
                answer++;
                cnt=0;
            }
        }
        if(answer==2){
            cout<<'#'<<test<<' '<<"Yes"<<endl;
        }
        else{
            cout<<'#'<<test<<' '<<"No"<<endl;
        }
    }
    return 0;
}