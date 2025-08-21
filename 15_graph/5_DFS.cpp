// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

/*
DFS: Depth-First Search
This code performs a depth-first traversal of a graph represented by an adjacency list.
Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges.
Space Complexity: O(V) for the visited array and recursion stack.
*/

class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        vector<bool> visited(V, false);
        vector<int> dfs_traversal;
        
        dfs_helper(V, adj, dfs_traversal, visited, 0);
        
        return dfs_traversal;
    }
    
    void dfs_helper(int nodes, vector<vector<int>>& adj, vector<int>& dfs_traversal, 
    vector<bool>& visited, int u){
        visited[u] = true;
        dfs_traversal.push_back(u);
        
        for(auto v : adj[u]){
            if(!visited[v]){
                dfs_helper(nodes, adj, dfs_traversal, visited, v);
            }
        }
    }
};