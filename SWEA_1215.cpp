#include<iostream>
using namespace std;
int len;
char arr[9][9];
int qnt=0;
int cnt=0;
int allcount=0;
void search_garo(int i,int j){
    int LEN=(len/2)+(len%2);
    for(int k=j;k<=j+LEN-1;k++){
        qnt++;
        if(0<=i&&i<=8&&0<=k&&k<=8){
            if(arr[i][k]==arr[i][len+j-qnt]){
                cnt++;
                //cout<<i<<' '<<k<<"("<<arr[i][k]<<")"<<' '<<i<<' '<<len+j-qnt<<' '<<"("<<arr[i][len+j-qnt]<<")"<<' '<<cnt<<endl;
            }
        }
    }
    if(cnt==(len/2)+(len%2)){
        allcount++;
    }
}
void search_sero(int j,int i){
    int LEN=(len/2)+(len%2);
    for(int k=j;k<=j+LEN-1;k++){
        qnt++;
        if(0<=i&&i<=8&&0<=k&&k<=8){
            if(arr[k][i]==arr[len+j-qnt][i]){
                cnt++;
                //cout<<k<<' '<<i<<"("<<arr[k][i]<<")"<<' '<<len+j-qnt<<' '<<i<<' '<<"("<<arr[len+j-qnt][i]<<")"<<' '<<cnt<<endl;
            }
        }
    }
    //cout<<"#"<<cnt<<endl;
    if(cnt==(len/2)+(len%2)){
        //cout<<(len/2)+(len%2);
        allcount++;
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    int count=10;
    int num=0;
    while(count--){
        allcount=0;
        num++;
        cin>>len;
        for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                cin>>arr[i][j];
            }
        }
        for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                //cout<<"-------"<<endl;
                cnt=0;
                qnt=0;
                search_garo(j,i);
            }
        }
        for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                //cout<<"-------"<<endl;
                cnt=0;
                qnt=0;
                search_sero(j,i);
            }
        }
        cout<<"#"<<num<<' '<<allcount<<endl;
    }
    return 0;
}