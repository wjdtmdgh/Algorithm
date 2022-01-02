#include<iostream>
using namespace std;
int main(){
    int N,S;
    int arr[50];
    int count=0;
    cin>>N>>S;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    for(int i=1;i<(1<<N);i++){
        int sum=0;
        for(int j=0;j<N;j++){
            if((i>>j)&1){
                sum+=arr[j];
            }
        }
        if(sum==S){
            count++;
        }
    }
    cout<<count;
    return 0;
}