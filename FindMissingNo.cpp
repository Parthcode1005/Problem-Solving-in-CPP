#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int first=1;
    for(int i=2;i<=n+1;i++){
        first=first^i;
    }
    int second=a[0];
    for(int i=1;i<n;i++){
        second=second^a[i];
    }
    cout<<(first^second)<<endl;
    
}