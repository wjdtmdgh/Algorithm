#include<iostream>
using namespace std;
int N,V;
int arr[1100][1100];
int stack[1100000];
bool visit[1100];
int top;
int x,y;
int start[1100];
int income[1100];
int cnt;
int qnt;
int num;
void reset(){
    top=-1;
    cnt=0;
    qnt=0;
    for(int i=1;i<=1000;i++) {
        visit[i] = false;
        income[i]=0;
        start[i] = 0;
        for (int j = 1; j <= 1000; j++) {
            arr[i][j] = 0;
        }
    }
}
void income_dfs(){
    while(top>-1){
        int cur=stack[top];
        top--;
        if(!visit[cur]){
            visit[cur]=true;
            cout<<cur<<' ';
            for(int i=N;i>=1;i--){
                cnt=0;
                qnt=0;
                if(arr[cur][i]==1){
                    for(int j=1;j<=N;j++){
                        //그 다음노드로 갈 수 있는것 들중에서 자기자신으로 들어오는 노드가 방문되어 끝난경우에 넣어주면 끝
                        if(arr[j][i]==1){//들어오는 노드가 전부다 트루일때만 스택에넣어주면되는데..쉽게가능할거같은데..
                            cnt++;
                        }
                    }
                    for(int k=1;k<=N;k++){
                        if(arr[k][i]==1&&visit[k]){
                            qnt++;
                        }
                    }
                }
                //cout<<qnt<<' '<<cnt<<endl;
                if(qnt==cnt&&qnt+cnt!=0){
                    top++;
                    stack[top]=i;
                }
            }
        }
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    int count=10;
    while(count--){
        num+=1;
        cin>>N>>V;
        reset();
        for(int i=1;i<=V;i++){
            cin>>x>>y; 
            arr[x][y]=1;
            start[y]=1; //자기 자신으로 들어오는 간선이 있는지 없는지 check
        }
        cout<<"#"<<num<<' ';
        for(int i=1;i<=N;i++){
            if(start[i]==0&&!visit[i]){ //자기자신으로 들어오는 간선 없는 노드 시작
                top++;
                stack[top]=i;
                income_dfs();
            }
        }
            cout<<endl;
    }
    return 0;
}