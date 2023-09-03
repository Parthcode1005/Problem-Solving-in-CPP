#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int i,int j){
    if(i<0){
        return;
    }
    if(j<i){
        if(arr[j]>arr[j+1]){
        int temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        }
        solve(arr,i,j+1);
    }
    else{
        solve(arr,i-1,0);
    }
}
int main(){
    int arr[7]={5,2,8,3,1,9,4};
    solve(arr,6,0);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}