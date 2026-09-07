class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        // adjacency list making (unidrected specifically)
        for(vector<int> v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        vector<bool> visited(n, false);

        bool b = dfs(0, -1, adj, visited);

        if(!b) return false;

        for(bool bo : visited){
            if(bo == false){
                return false;
            }
        }

        return true;
    }
    //  we need a visited array since this is not liked by pointers
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;

        for(int i : adj[node]){
            if(i == parent){
                continue;
            }
            if(visited[i]){
                return false;
            }
            if(!dfs(i, node, adj, visited)){
                return false;
            }
        }
        return true;
    }
};
