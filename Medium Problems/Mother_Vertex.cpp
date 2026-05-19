/*
Mother Vertex
Given a directed graph with V vertices labeled from 0 to V-1 and a list of edges edges[][], where each edge is represented as [u, v] indicating a directed edge from vertex u to vertex v, find a Mother Vertex of the graph.

A Mother Vertex is a vertex from which all other vertices can be reached.

If multiple such vertices exist, return the one with the smallest value.
If no such vertex exists, return -1.
Examples:

Input: V = 5, edges[][] = [[0, 2], [0, 3], [1, 0], [2, 1], [3, 4]]
Output: 0
Explanation: Vertices 0, 1, and 2 can each reach all other vertices in the graph. Among them, 0 is the smallest, so the output is 0.
  
Input: V = 3, edges[][] = [[0, 1], [2, 1]]
Output: -1
Explanation: No vertex can reach all other vertices in the graph. Hence, there is no Mother Vertex, and the output is -1.
 
Constraints:
1 ≤ V ≤ 105
1 ≤ edges[i][0], edges[i][1] ≤ V-1
*/


class Solution {
public:

    vector<vector<int>> adjListHelper(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adjList(V);

        for (auto &i : edges) {
            adjList[i[0]].push_back(i[1]);
        }

        return adjList;
    }

    void dfs(int node, vector<int>& visited, vector<vector<int>>& adjList) {

        visited[node] = 1;

        for (auto nbr : adjList[node]) {
            if (!visited[nbr]) {
                dfs(nbr, visited, adjList);
            }
        }
    }

    int findMotherVertex(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adjList = adjListHelper(V, edges);

        vector<int> visited(V, 0);

        int candidate = -1;

        for (int i = 0; i < V; i++) {

            if (!visited[i]) {
                dfs(i, visited, adjList);
                candidate = i;
            }
        }

        fill(visited.begin(), visited.end(), 0);

        dfs(candidate, visited, adjList);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                return -1;
            }
        }

        return candidate;
    }
};