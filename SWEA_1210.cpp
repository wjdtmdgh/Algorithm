#include<iostream>
using namespace std;
int num;
int arr[101][101];
int stack[110000][2];
int top;
bool visit[101][101];
int dx[3]={-1,0,0};
int dy[3]={0,1,-1};
int answer;
void reset(){
    top=-1;
    answer=0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            visit[i][j]=false;
        }
    }
}
void input(){
    cin>>num;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(arr[i][j]==2){
                top++;
                stack[top][0]=i;
                stack[top][1]=j;
                //cout<<i<<' '<<j;
            }
        }
    }
}
void bfs(){
    while(top>-1){
        int curx=stack[top][0];
        int cury=stack[top][1];
        if(curx==0){
            answer=cury;
            break;
        }
        top--;
        if(!visit[curx][cury]){
            visit[curx][cury]=true;
            //cout<<curx<<' '<<cury<<endl;
            for(int d=0;d<3;d++){
                int new_x=curx+dx[d];
                int new_y=cury+dy[d];
                if(0<=new_x&&new_x<100&&0<=new_y&&new_y<100){
                    if(arr[new_x][new_y]==1&&!visit[new_x][new_y]){
                        top++;
                        stack[top][0]=new_x;
                        stack[top][1]=new_y;
                    }
                }
            }
        }
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    int count=10;
    while(count--){
        reset();
        input();
        bfs();
        cout<<'#'<<num<<' '<<answer<<endl;
    }
    return 0;
}