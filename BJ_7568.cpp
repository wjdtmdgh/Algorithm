#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N;
    int x,y;
    int x1=1,y1=1;
    int cnt;
    int storex1,storey1;
    vector<pair<int,int> > arr;
    vector<pair<int,int> > qrr;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x>>y;
        arr.push_back(make_pair(x,y));
    }
    for(int i=0;i<arr.size();i++){
        cnt=0;
        for(int j=0;j<arr.size();j++){
            if(arr[i].first<arr[j].first&&arr[i].second<arr[j].second){
                cnt++;
            }
        }
        cout<<cnt+1<<' ';
    }
    return 0;
}