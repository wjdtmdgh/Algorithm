#include<iostream>
using namespace std;
int stack[5500000][2];
int top=-1;
int N,M,square_num;
int arr[101][101];
bool visit[101][101];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int x1,x2,y1,y2;
int area;
int square[101];
int cnt;
void input(){
  cin>>N>>M>>square_num;
  for(int k=0;k<square_num;k++){
    cin>>x1>>y1>>x2>>y2;
    for(int i=y1;i<y2;i++){
      for(int j=x1;j<x2;j++){
        arr[i][j]=1;
      }
    }
  }
}
void dfs(int x,int y){
  //cout<<"---------"<<endl;
  cnt=0;
  top++;
  stack[top][0]=x;
  stack[top][1]=y;
  while(top>-1){
    int curx=stack[top][0];
    int cury=stack[top][1];
    top--;
    if(!visit[curx][cury]){
      cnt++;
      square[area]=cnt;
      visit[curx][cury]=true;
      //cout<<curx<<' '<<cury<<' '<<area<<' '<<cnt<<endl;
      for(int d=0;d<4;d++){
        int newx=curx+dx[d];
        int newy=cury+dy[d];
        if(0<=newx&&newx<N&&0<=newy&&newy<M){
          if(arr[newx][newy]==0&&!visit[newx][newy]){
            top++;
            stack[top][0]=newx;
            stack[top][1]=newy;
          }
        }
      }
    }
  }
  area++;
}
int main(){
  input();
  for(int x=0;x<N;x++){
    for(int y=0;y<M;y++){
      if(arr[x][y]==0&&!visit[x][y]){
        dfs(x,y);
      }
    }
  }
  // for(int i=0;i<area;i++){
  //   cout<<square[i]<<' ';
  // }
  for(int i=0;i<area;i++){
    for(int j=0;j<area-1;j++){
      if(square[j]>square[j+1]){
        int tmp=square[j+1];
        square[j+1]=square[j];
        square[j]=tmp;
      }
    }
  }
  cout<<area<<endl;
  for(int i=0;i<area;i++){
    cout<<square[i]<<' ';
  }
  return 0;
}