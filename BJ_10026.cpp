#include<iostream>
using namespace std;
int N;
char arr[101][101];
int top=-1;
int stack[5500000][2];
bool visit[100][100];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int area_a;
int area_b;
int front=-1;
int rear=-1;
int queue[50000][2];
void input(){
  cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>arr[i][j];
    }
  }
}
void dfs(char color){
  while(top>-1){
    int curx=stack[top][0];
    int cury=stack[top][1];
    top--;
    if(!visit[curx][cury]){
      visit[curx][cury]=true;
      //cout<<curx<<' '<<cury<<' '<<area_a<<endl;
      for(int d=0;d<4;d++){
        int new_x=curx+dx[d];
        int new_y=cury+dy[d];
        if(0<=new_x&&new_x<N&&0<=new_y&&new_y<N){
          if(arr[new_x][new_y]==color&&!visit[new_x][new_y]){
            top++;
            stack[top][0]=new_x;
            stack[top][1]=new_y;
          }
        }
      }
    }
  }
  area_a++;
}
void bfs(char color){
  while(front!=rear){
    front++;
    int curx=queue[front][0];
    int cury=queue[front][1];
    if(!visit[curx][cury]){
      visit[curx][cury]=true;
      //cout<<curx<<' '<<cury<<' '<<area_b<<endl;
      for(int d=0;d<4;d++){
        int new_x=curx+dx[d];
        int new_y=cury+dy[d];
        if(0<=new_x&&new_x<N&&0<=new_y&&new_y<N){
          if(color=='B'){
            if(arr[new_x][new_y]==color&&!visit[new_x][new_y]){
              rear++;
              queue[rear][0]=new_x;
              queue[rear][1]=new_y;
            }
          }
          else{
            if(arr[new_x][new_y]!='B'&&!visit[new_x][new_y]){
              rear++;
              queue[rear][0]=new_x;
              queue[rear][1]=new_y;  
            }
          }
        }
      }
    }
  }
  area_b++;
}
int main(){
  input();
  for(int x=0;x<N;x++){
    for(int y=0;y<N;y++){
      if(!visit[x][y]){
        top++;
        stack[top][0]=x;
        stack[top][1]=y;
        dfs(arr[x][y]);
      }
    }
  }
  for(int x=0;x<N;x++){
    for(int y=0;y<N;y++){
      visit[x][y]=false;
    }
  }
  for(int x=0;x<N;x++){
    for(int y=0;y<N;y++){
      if(!visit[x][y]){
        rear++;
        queue[rear][0]=x;
        queue[rear][1]=y;
        bfs(arr[x][y]);
      }
    }
  }
  cout<<area_a<<' '<<area_b;
  return 0;
}