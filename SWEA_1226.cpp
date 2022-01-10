#include<iostream>
using namespace std;
char stack[110000][2];
char arr[20][20];
int top;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool visit[20][20];
int num;
bool check;
int start_x,start_y,end_x,end_y;
void reset(){
    top=-1;
    check=false;
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            visit[i][j]=false;
        }
    }
}
void input(){
    cin>>num;
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='2'){
                start_x=i;
                start_y=j;
                top++;
                stack[top][0]=i;
                stack[top][1]=j;
            }
            if(arr[i][j]=='3'){
                end_x=i;
                end_y=j;
            }
        }
    }
}
void bfs(){
    while(top>-1){
        int curx=stack[top][0];
        int cury=stack[top][1];
        top--;
        if(curx==end_x&&cury==end_y){
            check=true;
            break;
        }
        if(!visit[curx][cury]){
            visit[curx][cury]=true;
            //cout<<curx<<' '<<cury<<endl;
            for(int d=0;d<4;d++){
                int new_x=curx+dx[d];
                int new_y=cury+dy[d];
                if(0<=new_x&&new_x<16&&0<=new_y&&new_y<16){
                    if(arr[new_x][new_y]=='0'||arr[new_x][new_y]=='3'){
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
        cout<<'#'<<num<<' '<<check<<endl;
    }
    return 0;
}