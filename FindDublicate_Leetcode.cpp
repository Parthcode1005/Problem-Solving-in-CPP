#include<bits/stdc++.h>
using namespace std;
    int findDuplicate(vector<int>& arr) {
      int i=0;
      int temp;
      while(i<arr.size()){
        if(arr[i]!=i){
          int correct=arr[i];
          if(arr[correct]!=arr[i]){
            temp=arr[correct];
                arr[correct]=arr[i];
                arr[i]=temp;
          }
          else{
            return arr[i];
          }
        }
        else{
          i++;
        }
        
      }
      return -1;
      
    }

int main() {
  vector<int>v;
  v.push_back(1);
  v.push_back(4);
  v.push_back(2);
  v.push_back(0);
  v.push_back(3);
  v.push_back(0);
  v.push_back(6);
  int a=findDuplicate(v);
  cout<<a<<endl;
  return 0;
}

