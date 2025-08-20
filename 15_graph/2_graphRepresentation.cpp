// https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

/*
Access pair things with .first and .second.
This code constructs an adjacency list representation of a graph given the number of vertices and a list of edges.
Each vertex's adjacency list is stored in a vector of vectors.
Time Complexity: O(E) where E is the number of edges.
Space Complexity: O(V + E) where V is the number of vertices and E is the number of edges.
*/

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // Code here
        vector<vector<int>> adjList(V);
        
        for(auto edge : edges){
            int v = edge.first;
            int u = edge.second;
            
            adjList[v].push_back(u);
            adjList[u].push_back(v);
        }
        
        return adjList;
    }
};