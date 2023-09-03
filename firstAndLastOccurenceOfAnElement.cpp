//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int>a;
    a.push_back(first_occ(arr,n,x));
    a.push_back(last_occ(arr,n,x));
    return a;
   
}
public:
 int first_occ(int arr[],int n,int x){
    int l=0,h=n-1;
    int result;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]==x){
            result=mid;
            h=mid-1;
        }
        else if(arr[mid]>x){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return result;
}
public:
    int last_occ(int arr[],int n,int x){
    int l=0,h=n-1;
    int result;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]==x){
            result=mid;
            l=mid+1;
        }
        else if(arr[mid]>x){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return result;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends