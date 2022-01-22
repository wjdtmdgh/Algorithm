#include<iostream>
using namespace std;
char arr[21][21];
int num;
int cnt;
bool check;
void reset(){
    check=false;
    cnt=0;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            arr[i][j]=0;
        }
    }
}
int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        reset();
        cin>>num;
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                cin>>arr[i][j];
            }
        }
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                if(arr[i][j]=='o'){
                    cnt=0;
                    for(int k=0;k<5;k++){
                        if(arr[i][j+k]=='o'){
                            cnt++;
                        }
                        if(cnt==5){
                            check=true;
                        }
                    }
                    cnt=0;
                    for(int k=0;k<5;k++){
                        if(arr[i+k][j]=='o'){
                            cnt++;
                        }
                        if(cnt==5){
                            check=true;
                        }
                    }
                    cnt=0;
                    for(int k=0;k<5;k++){
                        if(arr[i+k][j+k]=='o'){
                            cnt++;
                        }
                        if(cnt==5){
                            check=true;
                        }
                    }
                    cnt=0;
                    for(int k=0;k<5;k++){
                        if(arr[i+k][j-k]=='o'){
                            cnt++;
                        }
                        if(cnt==5){
                            check=true;
                        }
                    }
                }
            }
        }
        cout<<'#'<<i<<' ';
        if(!check){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}