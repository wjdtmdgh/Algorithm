#include<iostream>
using namespace std;
int sum[4][101];
int main(){
    freopen("input.txt", "r", stdin);
    int count=10;
    int cnt=0;
    int arr[101][101];
    int num;
    while(count--){
        cnt=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<100;j++){
                sum[i][j]=0;
            }
        }
        cin>>num;
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                cin>>arr[i][j];
            }
        }
        for(int i=0;i<100;i++){
            sum[2][i]+=arr[i][i];
            sum[3][i]+=arr[i][99-i];
            for(int j=0;j<100;j++){
                sum[0][i]+=arr[i][j];
                sum[1][i]+=arr[j][i];
            }
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<100;j++){
                if(cnt<sum[i][j]){
                    cnt=sum[i][j];
                }
            }
        }
        cout<<"#"<<num<<' '<<cnt<<endl;
    }
    return 0;
}