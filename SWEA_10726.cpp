#include<iostream>
using namespace std;
int one_num,num;
int cnt;
int arr[500];
int qnt;
bool check;
void reset(){
    check=true;
    cnt=0;
    qnt=0;
    for(int i=0;i<500;i++){
        arr[i]=0;
    }
}
void ten_to_two_j(int n) {
    arr[qnt]=n%2;
    qnt++;
    if (n > 2) { // n==1 (이전 n이 2이거나 3)
        ten_to_two_j(n / 2);
    }
    //     printf("%d", n);
    // }
    // else {
    //     printf("%d", n % 2);
    // }
}
int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        reset();
        cin>>one_num>>num;
        ten_to_two_j(num);
        for(int j=0;j<one_num;j++){
            if(arr[j]==0){
                check=false;
                break;
            }
        }
        if(!check){
            cout<<'#'<<i<<' '<<"OFF"<<endl;
        }
        else{
            cout<<'#'<<i<<' '<<"ON"<<endl;       
        }
    }
    return 0;
}