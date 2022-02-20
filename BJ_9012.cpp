#include<iostream>
#include<cstring>
using namespace std;
int top=-1;
int cnt=0;
bool isEmpty(){
    return top==-1;
}
void push(char* pack){
    pack[++top]=++cnt;
}
void pop(char *pack){
    pack[top--]=0;
    cnt--;
}
int main(){
    char* pack=new char[100000];
    int num;
    int len=0;
    cin>>num;
    while(num--){
        top=-1;
        cnt=0;
        cin>>pack;
        len=strlen(pack);
        for(int i=0;i<len;i++){
            if(pack[i]=='('){
                push(pack);
            }
            else{
                if(!isEmpty()){
                    pop(pack);
                }
                else{
                    cnt=1;
                }
            }
        }
            if(cnt==0){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        
    }
    return 0;
}