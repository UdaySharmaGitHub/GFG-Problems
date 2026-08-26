/*
Negative Weight Cycle
Given a weighted directed graph containing V vertices numbered from 0 to V - 1 and a list of E directed edges edges[][], determine whether the graph contains a negative weight cycle or not.
Each edge is represented as: [u, v, w], where there is a directed edge from vertex u to vertex v having the given weight w.
Note: A negative-weight cycle is a cycle in a graph whose edges sum to a negative value.
Examples:
Input: V = 4, E = 4, edges[][] = [[0, 3, 6], [1, 0, 4], [1, 2, 6], [3, 1, 2]]
Output: fals
Explanation: Cycle 1 -> 0 -> 3 -> 1 has total weight 6 + 4 + 2 = 12, which is positive, so no negative weight cycle exists.
Input: V = 4, E = 4, edges[][] = [[1, 0, 4], [3, 1, -2], [1, 2, -6], [2, 3, 5]]
Output: true
Explanation: There is a cycle 1 -> 2 -> 3 -> 1 with total weight -3, which is negative, so a negative weight cycle exists.
 Constraints:
1 ≤ V ≤ 103
0 ≤ E ≤ 105
0 ≤ u, v < V
-106 ≤ w ≤ 106
*/
class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        // code here
        // code here
        vector<long long>dist(V, 0);

        for(int i=0; i<V-1; i++){
            for(auto &it:edges){
                int u=it[0];
                int v=it[1];
                int w=it[2];

                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];

            if(dist[u]+w<dist[v]){
                return true;
            }
        }

        return false;
    }
};