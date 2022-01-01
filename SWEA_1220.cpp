#include<iostream>
using namespace std;
int arr[101][101];
int N;
int cnt;
int main(){
    int ccnt=0;
    freopen("input.txt", "r", stdin);
    int count=10;
    while(count--){
        cnt=0;
        ccnt++;
        cin>>N;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>arr[i][j];
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(arr[i][j]==1){
                    if(arr[i+1][j]==2){
                        cnt++;
                    }
                    else if(arr[i+1][j]==0){
                        arr[i+1][j]=arr[i][j];
                    }
                }
            }
        }
        cout<<"#"<<ccnt<<' '<<cnt<<endl;
    }
    return 0;
}