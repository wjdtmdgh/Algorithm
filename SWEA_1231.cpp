#include<iostream>
using namespace std;
int num=0;
int N;
char val;
char arr[1001];
void inorder(int cnt){
    if(1<=cnt&&cnt<=N){
        inorder(cnt*2);
        cout<<arr[cnt];
        inorder(cnt*2+1);
    }
}
int main(){
    //freopen("input.txt", "r", stdin);
    int count=10;
    int node,Left,Right;
    while(count--){
        num+=1;
        cin>>N;
        for(int i=1;i<=N;i++){
            cin>>node>>val;
            arr[node]=val;
            if(node<=N/2){
                if(i==N/2&&N%2==0){
                    cin>>Left;
                }
                else{
                    cin>>Left>>Right;
                }
            }
        }
        cout<<'#'<<num<<' ';   
        inorder(1);
        cout<<endl;
    }
    return 0;
}