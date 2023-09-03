#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& arr){
    int min=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i]<arr[min]){
            min=i;
        }
    }
    int buy=arr[min];
    int max=min;
    for(int i=min+1;i<arr.size();i++){
        if(arr[i]>arr[max]){
            max=i;
        }
    }
    int sell=arr[max];
    return sell-buy;
    
}
int main(){
    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    int ans=solve(prices);
    cout<<ans<<endl;
    return 0;
}