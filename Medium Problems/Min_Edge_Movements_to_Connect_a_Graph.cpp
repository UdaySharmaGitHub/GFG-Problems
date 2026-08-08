/*
Min Edge Movements to Connect a Graph
Given a graph with n vertices (0 to n-1) and m edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation.
Find the minimum number of operations required to connect the graph. If it is not possible to connect the graph, return -1.
Examples: 
Input: n = 4, edges[][] = [[0, 1], [0, 2], [1, 2]]
Output: 1
Explanation: Remove edge between vertices 1 and 2 and add between vertices 1 and 3.
Input: n = 6, edges[][] = [[0,1], [0,2], [0,3], [1,2], [1,3]]
Output: 2
Explanation: Remove edge between (1,2) and (0,3), and add edge between (1,4) and (3,5)
Constraints:
1 ≤ n ≤ 105
1 ≤ m ≤ 105
2 ≤ m (cols) ≤ 2
edges[i][j] < n
edges.rows ≤ m
There are no multi-edges in the graph.
*/
class Solution {
  public:
    
    void dfs(int u, vector<bool>& visited, unordered_map<int, vector<int>>& adj) {
        
        visited[u] = true;
        
        for (int& v : adj[u]) {
            
            if (!visited[v]) {
                dfs(v, visited, adj);
            }
        }
    }
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        int E = edges.size();
        int need = n-1; // need minimum edges to connect a graph
        
        if (need > E) return -1;
        
        unordered_map<int, vector<int>> adj;
        
        for (auto& edge : edges) {
            
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        int components = 0;
        
        for (int i = 0; i < n; i++) {
            
            if (!visited[i]) {
                components++;
                dfs(i, visited, adj);
            }
        }
        
        return components - 1;
    }
};