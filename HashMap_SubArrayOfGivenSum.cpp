//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        unordered_map<long long,int>map;
        vector<int>v;
        long long current_sum=0;
        int start=0;
        int end=-1;
        for(int i=0;i<n;i++){
            current_sum+=arr[i];
            if(current_sum-s==0){
                start=0;
                end=i;
                break;
            }
            if(map.find(current_sum-s) != map.end()){
                start=map[current_sum-s]+1;
                end=i;
                break;
            }
            map[current_sum]=i;
        }
        if(end==-1){
            return {-1}; 
        }
        else{
            v.push_back(start);
            v.push_back(end);
            return v;
        }
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends