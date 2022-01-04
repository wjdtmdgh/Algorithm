#include<iostream>
using namespace std;
int main(){
    freopen("input.txt", "r", stdin);
    int count=10;
    int num;
    char search[101];
    char arr[100001];
    int len=0;
    int cnt=0;
    int allcount=0;
    while(count--){
        allcount=0;
        len=0;
        cin>>num;
        scanf("%s",search);
        for(int i=0;search[i]!='\0';i++){
            len++;
        }
        scanf("%s",arr);
        for(int i=0;arr[i]!='\0';i++){
            cnt=0;
            for(int j=0;j<len;j++){
                if(arr[i+j]==search[j]){
                    cnt++;
                }
            }
            if(cnt==len){
                allcount++;
            }
        }
        cout<<"#"<<num<<' '<<allcount<<endl;
    }
    return 0;
}