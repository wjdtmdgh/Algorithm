#include<iostream>
using namespace std;
int arr[10001];
int CCnt;
int N;
void comfirm(int val){
    int cnt=0;
    int bignum=0;
    for(int i=val-2;i<=val+2;i++){
        if(i!=val){
            if(bignum<arr[i]){
                bignum=arr[i];
            }
        }
    }
    //for(int i=val-2;i<=val+2;i++){
    if(bignum>arr[val]){
        cnt+=0;
        CCnt+=cnt;
        //cout<<cnt<<' ';
    }
    else{
        cnt+=arr[val]-bignum;
        CCnt+=cnt;
        //cout<<cnt<<' ';
    }
    //}
}
int main(){
    freopen("input.txt", "r", stdin);
    int count=10;
    int k=0;
    while(count--){
        CCnt=0;
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        for(int i=2;i<N-2;i++){
            comfirm(i);
        }
        k++;
        cout<<"#"<<k<<' '<<CCnt<<endl;
    }
    return 0;
}