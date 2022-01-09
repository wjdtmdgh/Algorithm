#include<iostream>
using namespace std;
int gcd(int a,int b){
  if(b==0){
    return a;
  }
  else{
    return gcd(b,a%b);
  }
}
int main(){
  int test;
  int a,b;
  int store;
  int prt;
  cin>>test;
  while(test--){
    cin>>a>>b;
    gcd(a,b);
    store=gcd(a,b);
    prt=store*(a/store)*(b/store);
    cout<<prt<<endl;
  }
  return 0;
}