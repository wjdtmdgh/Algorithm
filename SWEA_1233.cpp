#include<iostream>
using namespace std;
int main(){
    //freopen("input.txt", "r", stdin);
    int count=10;
    int N;
    int potnum,left,right;
    char opt;
    int num=0;
    while(count--){
        cin>>N;
        num+=1;
        bool answer=true;
        for(int i=1;i<=N;i++){
            cin>>potnum>>opt;
            if(potnum<=N/2){
                if(i==N/2&&N%2==0){
                    cin>>left;
                }
                else{
                    cin>>left>>right;
                }
                if(opt>='0'&&opt<='9'){
                    answer=0;
                }
            }
            else{
                if(!(opt>='0'&&opt<='9')){
                    answer=0;
                }
            }
        }
        cout<<'#'<<num<<' '<<answer<<endl;
    }
    return 0;
}