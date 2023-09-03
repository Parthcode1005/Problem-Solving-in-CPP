#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int a1=a,b1=b;
    int rem;
    int gcd;
    while(rem>0){
            rem=a%b;
            a=b;
            b=rem;
    }            
    gcd=a;
    cout<<gcd<<endl;

    //Find the lowest fraction value like 20/10=2/1 , 25/10=5/2
    cout<<a1/gcd<<"/"<<b1/gcd<<endl;
}