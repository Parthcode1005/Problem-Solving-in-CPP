#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    int count=0;
    while(a>0){
        a=a^(a-1);
        count++;
    }
    cout<<count<<endl;
}