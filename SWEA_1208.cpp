#include<iostream>
using namespace std;
int arr[101];
void largenum_smallnum(){
    int big=0;
    int small=1001;
    for(int i=0;i<100;i++){
        if(big<arr[i]){
            big=arr[i];
        }
    }
    for(int i=0;i<100;i++){
        if(small>arr[i]){
            small=arr[i];
        }
    }
    //cout<<big<<' '<<small<<endl;
    for(int j=0;j<100;j++){
        if(big==arr[j]){
            arr[j]--;
            break;
        }
    }
    for(int j=0;j<100;j++){
        if(small==arr[j]){
            arr[j]++;
            break;
        }
    }
    // for(int i=0;i<100;i++){
    //     cout<<arr[i]<<' ';
    // }
}
int main(){
    int count=10;
    int k=0;
    while(count--){
        int line;
        int Big=0;
        int Small=1001;
        cin>>line;
        for(int i=0;i<100;i++){
            cin>>arr[i];
        }
        for(int j=0;j<line;j++){
            largenum_smallnum();
            //cout<<endl;
        }
        for(int i=0;i<100;i++){
            if(Big<arr[i]){
                Big=arr[i];
            }
        }
        for(int i=0;i<100;i++){
            if(Small>arr[i]){
                Small=arr[i];
            }
        }
        k++;
        cout<<"#"<<k<<' '<<Big-Small<<endl;
    }
    return 0;
}