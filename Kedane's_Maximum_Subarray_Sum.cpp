#include<bits/stdc++.h>
using namespace std;
int Kedane(vector<int> &arr){
    int sum=0;
    int maxi=0;
    int i=0;
    while(i<arr.size()){
        sum+=arr[i];
        if(sum<0){
        sum=0;
        i++;
        }
        else{
            maxi=max(sum,maxi);
            i++;
        }
    }
    if(maxi==0){
        return *max_element(arr.begin(), arr.end());
    }
    else{
        return maxi;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr[n];
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr->push_back(a);
    }
    int result=Kedane(*arr);
    cout<<result<<endl;
    return 0;
}