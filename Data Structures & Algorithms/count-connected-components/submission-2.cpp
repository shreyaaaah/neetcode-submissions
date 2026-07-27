class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
        visited[node] = true;
        for(int neighbour:adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour,adj,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool>visited(n,false);
        vector<vector<int>>adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int comp = 0;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                comp++;
                dfs(i,adj,visited);
            }
        }
        return comp;


    }
};
