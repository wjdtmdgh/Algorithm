#include<iostream>
using namespace std;
char arr[51][51];
int N;
int x,y;
int cnt;
bool check;
void reset(){
    check=true;
    cnt=0;
}
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        reset();
        cin>>x>>y;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                cin>>arr[i][j];
            }
        }
        for(int i=0;i<x;i++){
            cnt=0;
            for(int j=0;j<y;j++){
                if(arr[i][j]=='#'){
                    cnt+=1;
                }
                else{
                    if(cnt%2!=0){
                        check=false;
                        break;
                    }
                }
            }
            if(cnt%2!=0){
                check=false;
                break;
            }
        }  
        for(int i=0;i<y;i++){
            cnt=0;
            for(int j=0;j<x;j++){
                if(arr[j][i]=='#'){
                    cnt+=1;
                }
                else{
                    if(cnt%2!=0){
                        check=false;
                        break;
                    }
                }
            }
            if(cnt%2!=0){
                check=false;
                break;
            }
        } 
        if(!check){
             cout<<'#'<<i<<' '<<"NO"<<'\n';
        } 
        else{
             cout<<'#'<<i<<' '<<"YES"<<'\n';
        }
       
    }
    return 0;
}