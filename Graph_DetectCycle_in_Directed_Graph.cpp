#include<bits/stdc++.h>
using namespace std;

bool detect(vector<int>adj[], int s, bool visited[], bool dfsVisited[]){
    visited[s]=true;
    dfsVisited[s]=true;
    for(int u:adj[s]){
        if(!visited[u] && detect(adj,u,visited,dfsVisited)){
                return true;
            }
        else if(dfsVisited[u]){
            return true;
        }
    }
    dfsVisited[s]=false;
    return false;
}
bool DFS(vector<int>adj[], int V){
    bool visited[V];
    bool dfsVisited[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    for(int i=0;i<V;i++){
        dfsVisited[i]=false;
    }
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(detect(adj,i,visited,dfsVisited)){
                return true;
            }
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main() 
{ 
	int V=6;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,2,1); 
	addEdge(adj,2,3); 
	addEdge(adj,3,4); 
	addEdge(adj,4,5);
	addEdge(adj,5,3);

	if(DFS(adj,V))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";

	return 0; 
}  