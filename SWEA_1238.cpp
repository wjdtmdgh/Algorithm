#include<iostream>
using namespace std;
int arr[301][301];
int queue[990000];
int front,rear;
bool visit[301];
int N,start;
int x,y;
int answer[101];
int cnt;
int start2;
int cnt2;
int T;
int ANSWER;
//끝난걸 어떻게 알까...? 원타임사용해서 cnt값이랑 같으면 마지막 구간이라고 생각하면댐
void onetime(){
    cnt2=cnt;
    front=0;
    rear=0;
    for(int i=1;i<=300;i++){
        queue[i]=0;
        visit[i]=false;
    }
    visit[start2]=true;
    for(int i=1;i<=100;i++){
        if(arr[start2][i]==1){
            rear++;
            queue[rear]=i;
        }
    }
}
void reset(){
    ANSWER=0;
    front=0;
    rear=0;
    cnt=0;
    cnt2=0;
    T=0;
    for(int i=1;i<=300;i++){
        answer[i]=0;
        queue[i]=0;
        visit[i]=false;
    }
    for(int i=1;i<=300;i++){
        for(int j=1;j<=300;j++){
            arr[i][j]=0;
        }
    }
}
void input(){
    cin>>N>>start;
    for(int i=1;i<=N/2;i++){
        cin>>x>>y;
        arr[x][y]=1;
    }
    start2=start;
    visit[start]=true;
    for(int i=1;i<=100;i++){
        if(arr[start][i]==1){
            rear++;
            queue[rear]=i;
        }
    }
}
void bfs(){
    int count=1;
    while(front!=rear){
        cnt++;
        front++;
        cout<<rear<<' '<<front<<endl;
        if(rear==cnt2){
            answer[count]=queue[front];
            count++;
            T=count;
        }
        int cur=queue[front];
        if(!visit[cur]){
            visit[cur]=true;
            //cout<<cur<<' ';
            for(int i=1;i<=100;i++){
                if(arr[cur][i]==1){
                    if(!visit[i]){
                        rear++;
                        queue[rear]=i;
                    }
                }
            }
        }
    }
}
int main(){
    //freopen("input.txt", "r", stdin);
    int test=10;
    int num=0;
    while(test--){
        reset();
        num+=1;
        input();
        bfs();
        onetime();
        bfs();
        for(int i=1;i<T;i++){
            cout<<answer[i]<<' ';
            if(ANSWER<answer[i]){
                ANSWER=answer[i];
            }
        }
        cout<<"#"<<num<<' '<<ANSWER<<endl;
    }
    return 0;
}