#include<iostream>
using namespace std;
int main(void){
    int N,M;
    int arr[101];
    int cmp=0;
    int cmp2=0;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=N;i++){
        cmp=0;
        for(int j=i+1;j<=N;j++){
            for(int k=j+1;k<=N;k++){
                cmp=arr[i]+arr[j]+arr[k];
                //cout<<cmp<<' ';
                if(M>=cmp){
                    if(cmp2<cmp){
                        cmp2=cmp;
                    }
                }
            }
        }
    }
    printf("%d",cmp2);
    return 0;
}