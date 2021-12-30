#include<iostream>
using namespace std;
int arr[1001];
int qrr[101];
int main(){
    int test;
    cin>>test;
    while(test--){
        int num;
        int bignum=0;
        cin>>num;
        for(int i=0;i<=100;i++){
            qrr[i]=0;
        }
        for(int i=0;i<1000;i++){
            cin>>arr[i];
            qrr[arr[i]]++;
        }
        for(int i=100;i>=0;i--){
            if(bignum<qrr[i]){
                bignum=qrr[i];
            }
        }
        for(int i=100;i>=0;i--){
            if(bignum==qrr[i]){
                cout<<"#"<<num<<' '<<i<<endl;
                break;
            }
        }
    }
    return 0;
}