#include<bits/stdc++.h> 
using namespace std; 
  
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
   
void printGraph(vector<int> adj[], int V) 
{ 
    for (int i = 0; i < V; i++) 
    { 
        for (int x : adj[i]) 
           cout << x <<" "; 
        cout<<"\n"; 
    } 
} 

void BFS(vector<int>adj[], int v, int s){
    bool visited[v+1];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    queue<int>q;
    visited[s]=true;
    q.push(s);
    while(!q.empty()){
        int u= q.front();
        cout<<u<<" ";
        q.pop();
        for(int v: adj[u]){
            if(visited[v]==false){
                visited[v]=true;
                q.push(v);
            }
        }
    }
}
void DFSRecord(vector<int>adj[], int s, bool visited[]){
    visited[s]=true;
    cout<<s<<" ";
    for(int u:adj[s]){
        if(visited[u]==false){
            DFSRecord(adj,u,visited);
        }
    }
}
void DFS(vector<int>adj[], int v, int s){
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    DFSRecord(adj,s,visited);
}

// Driver code 
int main() 
{ 
    int V = 4; 
    vector<int> adj[V]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    
    printGraph(adj, V);
    //BFS 
    cout << "Following is Breadth First Traversal: "<< endl; 
	BFS(adj,V,0);
    cout<<endl;
    //DFS 
    cout << "Following is Depth First Traversal: "<< endl; 
	DFS(adj,V,0);
    cout<<endl;
    return 0; 
} 