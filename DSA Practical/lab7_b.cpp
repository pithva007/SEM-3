#include<bits/stdc++.h>
using namespace std;

void dfs(int start, vector<bool>& visited, vector<vector<int>>& adj) {
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        if (!visited[v]) {
            visited[v] = true;
            cout << v << " ";
        }
        for (int i = adj[v].size() - 1; i >= 0; i--) {
            if (adj[v][i] == 1 && !visited[i]) {
                st.push(i);
            }
        }
    }
}

void bfs(int start,vector<bool>& visited,vector<vector<int>>& adj){
    queue<int> q;
    visited[start]=true;
    q.push(start);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        cout<<v<<" ";
        for(int i=0;i<adj[v].size();i++){
            if(adj[v][i]==1 && !visited[i]){
                visited[i]=true;
                q.push(i);
            }
        }
    }
}
int main(){
    vector<vector<int>> adj(5,vector<int>(5,0));
    // vector<char> adj={'A','B','C','D','E'};
    int n=adj.size();
    vector<pair<int,int>> p={{0,1},{0,2},{1,3},{3,4},{3,2},{0,4}};
    int u,v;
    for(int i=0;i<p.size();i++){
        u=p[i].first;
        v=p[i].second;
        adj[u][v]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
  
    vector<bool> visited(n,false);
    cout<<"DFS Traversal: "<<endl;
    dfs(0,visited,adj);
    cout<<endl<<"BFS Traversal: "<<endl;
    visited.assign(n,false);
    bfs(0,visited,adj);
    cout<<endl;
    return 0;
}