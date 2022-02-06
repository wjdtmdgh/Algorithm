#include<iostream>
using namespace std;
int main(){
    int N;
    int sum_ct,sum_pt,ret;
    int ct_h,ct_m,ct_s,pt_h,pt_m,pt_s;
    cin>>N;
    for(int i=1;i<=N;i++){
        scanf("%d:%d:%d",&ct_h,&ct_m,&ct_s);
        sum_ct=(ct_h*3600)+(ct_m*60)+ct_s;
        scanf("%d:%d:%d",&pt_h,&pt_m,&pt_s);
        sum_pt=(pt_h*3600)+(pt_m*60)+pt_s;
        if(sum_ct>sum_pt){
            ret=sum_pt-sum_ct+86400;
        }
        else{
            ret=sum_pt-sum_ct;
        }
        printf("#%d %02d:%02d:%02d\n",i,(ret/3600),((ret%3600)/60),((ret%3600)%60));
    }
    return 0;
}