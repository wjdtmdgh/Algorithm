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
  int a,b;
  cin>>a>>b;
  gcd(a,b);
  cout<<gcd(a,b)<<endl;
  int l=gcd(a,b);
  int q=l*(a/l)*(b/l);
  cout<<q<<endl;
  return 0;
}