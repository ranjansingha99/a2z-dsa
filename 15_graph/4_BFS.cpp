// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

/*
BFS: Breadth-First Search
This code performs a breadth-first traversal of a graph represented by an adjacency list.
Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges.
Space Complexity: O(V) for the visited array and queue.
*/

/*
Steps:
1. Initialize a vector to store the BFS traversal, a visited array to keep track of visited nodes and a que for getting the next node to visit.
2. Loop through each vertex in the graph (handles disconnected components/ vertex in directed graph with no incoming edges).
3. If the vertex has not been visited, mark it as visited and enqueue it.
4. While the queue is not empty, dequeue a vertex, add it to the BFS traversal, and enqueue all its unvisited adjacent vertices.
5. Repeat until all vertices are processed.
*/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int V = adj.size();
        vector<int> bfs_traversal;
        vector<bool> visited(V, false);
        
        // This outer loop handles disconnected components in the graph
        for(int i=0; i<V; i++){
            // Start BFS only if the node has not been visited yet
            if(!visited[i]){
                // Start the traversal from the current node 'i'
                // This is to handle first element vertex of every component(Might be disconnected/ vertexs in directed graph with no incoming edge)
                queue<int> q;
                q.push(i);
                visited[i] = true;
                
                while(!q.empty()){
                    // Dequeue a vertex from the queue and add it to the traversal list
                    int u = q.front();
                    q.pop();
                    bfs_traversal.push_back(u);
                    
                    // Get all adjacent vertices of the dequeued vertex u.
                    // If an adjacent has not been visited, then mark it visited
                    // and enqueue it.
                    for(auto v : adj[u]){
                        // This works automatically when the graph in undirected /with no vertices in directed graph that do not have incoming edge
                        if(!visited[v]){
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
        }
        
        return bfs_traversal;
    }
};