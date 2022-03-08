#include<iostream>
using namespace std;
void swap(int* a,int* b){
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}
bool next_permutation(int* arr, int n) {
    int i = n - 1;
    while (i > 0 && arr[i - 1] <= arr[i]) {
        i--; 
    }
    if (i == 0) return false;
    int j = n - 1;
    while (arr[i - 1] <= arr[j]) {
        j--;
    }
    swap(arr[i - 1], arr[j]);
    j = n - 1;
    while (i < j) {
        swap(arr[i], arr[j]);
        i += 1;
        j -= 1;
    }
    return true;
}
int main(){
  int n;
  cin>>n;
  int* arr=new int[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  if(next_permutation(arr,n)){
    for(int i=0;i<n;i++){
      cout<<arr[i]<<' ';
    }
  }
  else{
    cout<<-1;
  }
  return 0;
}