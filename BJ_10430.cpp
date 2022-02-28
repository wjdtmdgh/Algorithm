#include<iostream>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int a1=(a+b)%c;
  int a2=((a%c)+(b%c))%c;
  int a3=(a*b)%c;
  int a4=((a%c)*(b%c))%c;
  cout<<a1<<endl;
  cout<<a2<<endl;
  cout<<a3<<endl;
  cout<<a4<<endl;
  return 0;
}