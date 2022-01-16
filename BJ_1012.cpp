#include<iostream>
using namespace std;
int arr[51][51];
bool visit[51][51];
int stack[3000][2];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int top;
int x,y;
int area;
void reset(){
    top=-1;
    area=0;
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            visit[i][j]=false;
            arr[i][j]=0;
        }
    }
}
int main(){
  int N,M;
  int a,b;
  int num;
  int test;
  cin>>test;
  while(test--){
    reset();
    cin>>N>>M>>num;
    for(int i=0;i<num;i++){
      cin>>a>>b;
      arr[a][b]=1;
    }
    for(int x=0;x<N;x++){
      for(int y=0;y<M;y++){
        if(arr[x][y]==1&&!visit[x][y]){
          top++;
          stack[top][0]=x;
          stack[top][1]=y;
          area++;
          while(top>-1){
            int curx=stack[top][0];
            int cury=stack[top][1];
            //cout<<curx<<' '<<cury<<endl;
            top--;
            visit[curx][cury]=true;
            for(int d=0;d<4;d++){
              int new_x=curx+dx[d];
              int new_y=cury+dy[d];
              if(0<=new_x&&new_x<N&&0<=new_y&&new_y<M){
                if(arr[new_x][new_y]==1){
                  if(!visit[new_x][new_y]){
                    top++;
                    stack[top][0]=new_x;
                    stack[top][1]=new_y;
                  }
                }
              }
            }
          }
        }
      }
    }
    cout<<area<<endl;
  }
  return 0;
}