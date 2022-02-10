#include<iostream>
using namespace std;
int arr[41];
void reset(){
    for(int i=1;i<=40;i++){
        arr[i]=0;
    }
}
int main(){
    int test;
    int max;
    int N,M;
    cin>>test;
    for(int i=1;i<=test;i++){
        reset();
        max=0;
        cin>>N>>M;
        for(int t=1;t<=N;t++){
            for(int q=1;q<=M;q++){
                arr[t+q]++;
            }
        }
        for(int j=2;j<=40;j++){
            if(max<arr[j]){
                max=arr[j];
            }
        }
        cout<<'#'<<i<<' ';
        for(int j=2;j<=40;j++){
            if(max==arr[j]){
                cout<<j<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}