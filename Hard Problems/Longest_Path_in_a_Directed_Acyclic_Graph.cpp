/*
Longest Path in a Directed Acyclic Graph
Given a weighted Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1, represented by edges[][], where edges[i] = [u, v, w] denotes a directed edge from u to v with weight w, and a source vertex src.

Return the distance array, where the value at index i represents the longest distance from s to vertex i.
If a vertex is unreachable from s, store INT_MIN for that vertex. The driver code will automatically display INT_MIN as INF.
Examples :

Input: V = 4, src = 0, edges[][] = [[0, 1, 1], [0, 2, 1], [1, 2, 5], [3, 1, 2], [3, 2, -1]]
Output: [0, 1, 6, INF]
Explanation: The longest distance of vertex 1 from 0 is 1, vertex 2 is 6 and vertex 3 is unreachable so INF.

Input: V = 5, src = 1, edges[][] = [[0, 1, 1], [0, 2, 2], [1, 4, 4], [3, 2, -1], [4, 2, 3], [4, 3, 6]]
Output: [INF, 0, 9, 10, 4]
Explanation: The vertex 0 is not reachable from vertex 1 so its distance is INF, for 2 it is 9, for 3 it is 10, and for 4 it is 4.

Constraints:
1 ≤ V ≤ 104
0 ≤ src ≤ V-1
1 ≤ edges.size() ≤ V * (V - 1) / 2
0 ≤ edges[i][0], edges[i][1] < V
-100 ≤ edges[i][2] ≤ 100
*/
class Solution {
  public:
    
    
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for (auto & edge : edges) {
            
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
        }
        
        vector<int> dist(V, INT_MIN);
        
        priority_queue<pair<int, int>> pq;
        
        pq.push({0, src});
        dist[src] = 0;
        
        while (!pq.empty()) {
            
            auto [w, u] = pq.top();
            pq.pop();
            
            for (auto & [v, d] : adj[u]) {
                
                int totalDistance = w + d;
                
                if (dist[v] < totalDistance) {
                    dist[v] = totalDistance;
                    pq.push({totalDistance, v});
                }
            }
        }
        
        return dist;
    }
};