#include<iostream>
using namespace std;
int main(){
    int N;
    int x,sum,cnt,max,min;
    int arr[11];
    cin>>N;
    for(int i=1;i<=N;i++){
        cnt=0;
        max=0,min=2147483647;
        for(int j=1;j<=10;j++){
            sum=0;
            cin>>x;
            while(x>0){
                sum+=x%10;
                x/=10;
            }
            arr[cnt]=sum;
            cnt++;
        }
        for(int t=0;t<cnt;t++){
            if(max<arr[t]){
                max=arr[t];
            }
            if(min>arr[t]){
                min=arr[t];
            }
        }
        cout<<'#'<<i<<' '<<max<<' '<<min<<endl;
    }
    return 0;
}