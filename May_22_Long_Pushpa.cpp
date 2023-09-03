#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int v[n];
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    if(n==1){
	        cout<<v[0]<<endl;
	    }
	    else if(n==2){
	        if(v[0]>v[1]){
	            cout<<v[0]<<endl;
	        }
	        else{
	            cout<<v[1]<<endl;
	        }
	    }
	    else{
	        int m=v[0];
	        for(int i=0;i<n;i++){
	            int temp[n];
	            temp[i]=v[i];
	            int high=i;
	            for(int j=0;j<n;j++){
	                if(j!=high){
	                    temp[j]+=1;
	                }
	                if(temp[j]-temp[high]==1){
	                    high=j;
	                }
	                else{
	                    m=temp[high];
	                }
	            }
	        }
	        cout<<"Answer="<<m<<endl;
	    }
	}
	return 0;
}
