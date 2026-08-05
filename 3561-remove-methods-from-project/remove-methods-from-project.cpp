class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis){
        vis[u]= true;
        for(auto it: adj[u]){
            if(!vis[it]) dfs(it,adj,vis);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        vector<vector<int>> adj(n);
        for(auto it: inv){
            int u= it[0];
            int v= it[1];
            adj[u].push_back(v);
        }
        vector<bool> vis(n, false);
        dfs(k,adj,vis);
        for(auto it: inv){
            int u= it[0];
            int v= it[1];
            if(!vis[u] && vis[v]){
                vector<int> ans;
                for(int i=0;i<n;i++){
                   ans.push_back(i); 
                }
                return ans;
            }
        }
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(!vis[i]) ans.push_back(i);
        }
        
        return ans;
    }
};