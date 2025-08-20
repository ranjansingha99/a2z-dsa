// https://www.geeksforgeeks.org/problems/graph-and-vertices/1

/*
Number of vertices = n; Number of undirected graphs(connected + disconnected) = 2^n(n-1)/2 )
This is because for a graph with n vertices, there are (nC2) = n(n-1)/2 possible edges. 
For each of these possible edges, you have two choices: either include the edge in the graph or not.
*/

class Solution {
  public:
    long long count(int n) {
        // your code here
        long long exponent = (n * (n - 1)) / 2;
        
        return pow(2, exponent);
    }
};