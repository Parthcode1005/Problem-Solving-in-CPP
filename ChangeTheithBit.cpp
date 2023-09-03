#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,k;
    cin>>a>>k;
    int b=1;
    while(k--){
        b=b<<1;
    }
    a=a&(~b);
    cout<<a<<endl;

}