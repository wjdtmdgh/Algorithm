#include<iostream>
using namespace std;
int num;
int N;
int arr[101][101];
int top;
int stack[11000];
bool visit[101];
int answer;
void dfs(){
    while(top>-1){
        int cur=stack[top];
        top--;
        if(!visit[cur]){
            visit[cur]=true;
            //cout<<cur<<endl;
            if(cur==99){
                answer=1;
            }
            for(int i=99;i>=0;i--){
                if(arr[cur][i]==1){
                    if(!visit[i]){
                        top++;
                        stack[top]=i;
                    }
                }
            }
        }
    }
}
void reset(){
    for(int i=0;i<100;i++){
        visit[i]=false;
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            arr[i][j]=0;
        }
    }
    answer=0;
}
int main(){
    freopen("input.txt", "r", stdin);
    int count=10;
    while(count--){
        reset();
        int x,y;
        cin>>num>>N;
        for(int i=0;i<N;i++){
            cin>>x>>y;
            arr[x][y]=1;
        }
        top=-1;
        top++;
        stack[top]=0;
        dfs();
        if(answer==1){
            cout<<"#"<<num<<' '<<answer<<endl;
        }
        else{
            cout<<"#"<<num<<' '<<answer<<endl;
        }
    }
    return 0;
}