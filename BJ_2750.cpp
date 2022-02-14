#include<iostream>
using namespace std;
int main(){
    int n;
    int tmp;
    int arr[1000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j+1]<arr[j]){
                tmp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=tmp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}