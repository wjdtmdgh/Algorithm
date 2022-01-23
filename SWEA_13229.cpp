#include<iostream>
using namespace std;
void search(char val){
    switch (val)
    {
    case 'O':
        cout<<6<<endl;
        break;
    case 'E':
        cout<<4<<endl;
        break;
    case 'H':
        cout<<3<<endl;
        break;
    case 'R':
        cout<<2<<endl;
        break;
    case 'A':
        cout<<1<<endl;
        break;
    default:
        break;
    }
}
void search2(char val){
    switch (val)
    {
    case 'T':
        cout<<5<<endl;
        break;
    case 'S':
        cout<<7<<endl;
        break;
    default:
        break;
    }
}
int main(){
    char val[10];
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>val;
        cout<<'#'<<i+1<<' ';
        if(val[1]=='U'){
            search2(val[0]);
        }
        else if(val[1]!='S'){
            search(val[1]);
        }
    }
    return 0;
}