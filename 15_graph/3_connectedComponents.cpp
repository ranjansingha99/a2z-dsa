// https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1

/*
Connected Components in an Undirected Graph:
This code finds the number of connected components in an undirected graph using Depth First Search (DFS).
Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges.
Space Complexity: O(V) for the visited array and recursion stack.
*/

/*
Convert the edge list into an adjacency list before you run your traversal logic, 
*/

class Solution {
public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // Create an adjacency list of size V.
        vector<vector<int>> adj(V);

        // Populate the adjacency list from the provided edge list.
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            // Since the graph is undirected, add an edge from u to v AND v to u.
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);
        vector<vector<int>> result;

        for (int i = 0; i < V; i++) {
            
            if (!visited[i]) {
                vector<int> curr_comp(0);
                queue<int> q;

                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    curr_comp.push_back(u);

                    // Use the newly created 'adj' list for the traversal.
                    for (auto v : adj[u]) {
                        if (!visited[v]) {
                            q.push(v);
                            visited[v] = true;
                        }
                    }
                }
                result.push_back(curr_comp);   
            }
        }
        return result;
    }
};