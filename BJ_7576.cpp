#include<iostream>
using namespace std;
int arr[1001][1001];
int queue[5500000][3];
int front=-1;
int rear=-1;
bool visit[1001][1001];
int N,M;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int cnt;
int allthat;
void reset(){
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      visit[i][j]=false;
    }
  }
  front=rear=-1;
  allthat=0;
  cnt=0;
}
void input(){
  cin>>N>>M;
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      cin>>arr[i][j];
      if(arr[i][j]==0||arr[i][j]==1){
        allthat++;
      }
      if(arr[i][j]==1){
      ++rear;
      queue[rear][0]=i;
      queue[rear][1]=j;
      queue[rear][2]=0;
      }
    }
  }
}
void bfs(){
  while(front!=rear){
    ++front;
    int curx=queue[front][0];
    int cury=queue[front][1];
    int curh=queue[front][2];
    cnt=curh;
    if(!visit[curx][cury]){
      allthat--;
      visit[curx][cury]=true;
      for(int d=0;d<4;d++){
        int new_x=curx+dx[d];
        int new_y=cury+dy[d];
        if(0<=new_x&&new_x<M&&0<=new_y&&new_y<N){
          if(arr[new_x][new_y]==0){
             arr[new_x][new_y]=1;
            if(!visit[new_x][new_y]){
              ++rear;
              queue[rear][0]=new_x;
              queue[rear][1]=new_y;
              queue[rear][2]=curh+1;
            }
          }
        }
      }
    }
  }
}
int main(void){
  input();
  bfs();
  if(allthat>0){
    cout<<-1;
  }
  else{
    cout<<cnt;
  }
  return 0;
}