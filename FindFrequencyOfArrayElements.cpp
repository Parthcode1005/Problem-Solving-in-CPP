#include<bits/stdc++.h>
using  namespace std;
int main(){
    int arr[20]={10,20,50,10,60,30,20,30,60,50,10,30,20,30,60,40,10,60,20,20};
    vector<int>b;
    sort(arr,arr+20);
    for(int i=0;i<20;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int m=0,j=0;
    while(j<=19){
        if(arr[j]==arr[j+1]){
            m++;     
        }
        else{
            b.push_back(m);
            m=0;
        }
        j++;
    }
    
    for(int k=0;k<b.size();k++){
        cout<<b[k]+1<<" ";
    }
    cout<<endl;
    return 0;
}