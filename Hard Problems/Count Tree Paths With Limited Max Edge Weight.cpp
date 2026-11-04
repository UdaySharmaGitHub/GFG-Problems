/*
Count Tree Paths With Limited Max Edge Weight
Given a weighted tree with n nodes, numbered from 1 to n and n - 1 edges, where each edge is represented as [u, v, w] indicating an edge between nodes u and v with weight w.

You are also given an array queries[], where each queries[i] represents a maximum allowed edge weight.

For each query x, find the number of distinct paths in the tree such that the maximum edge weight along the path is less than or equal to x.

Return an array containing the number of valid paths for each query.

Note:

A path from node u to node v and the path from node v to node u are considered the same path.
A path must contain at least one edge. A path from a node to itself is not considered.
Examples:

Input: n = 3, edges[][] = [[1, 2, 1], [2, 3, 4]], queries[] = [3]
Output: [1]
Explanation:
For x = 3, only the edge [1, 2, 1] has weight less than or equal to 3.
Therefore, the only valid path is: 1 -> 2
The path 1 -> 3 contains an edge of weight 4, so it is not valid.
Hence, the answer is 1.
Input: n = 7, edges[][] = [[1, 2, 3], [2, 3, 1], [2, 4, 9], [3, 6, 7], [3, 5, 8], [5, 7, 4]], queries[] = [1, 3, 5]
Output: [1, 3, 4]
Explanation: For x = 1, only the edge [2, 3, 1] satisfies the condition. 
Therefore, the only valid path is 2 -> 3, giving an answer of 1.
For x = 3, the edges [2, 3, 1] and [1, 2, 3] can be used. 
They form three valid paths: 1 -> 2, 2 -> 3, and 1 -> 3. 
For x = 5, the edges with weights 1, 3, and 4 can be used. 
They form four valid paths: 1 -> 2, 2 -> 3, 1 -> 3, and 5 -> 7.
Constraints:

2 ≤ n ≤ 104
1 ≤ queries.size() ≤ 104
0 ≤ queries[i] ≤ 105
edges.size() = n-1
edges[i].size() = 3
1 ≤ edges[i][0], edges[i][1] ≤ n
edges[i][0] != edges[i][1]
0 ≤ edges[i][2] ≤ 105
*/
class Solution {
  public:

    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    long long unite(int u, int v) {

        u = find(u);
        v = find(v);

        if (u == v)
            return 0;

        if (sz[u] < sz[v])
            swap(u, v);

        // New paths formed between two components
        long long paths = 1LL * sz[u] * sz[v];

        parent[v] = u;
        sz[u] += sz[v];

        return paths;
    }

    vector<int> maximumWeight(int n, vector<vector<int>> edges, vector<int>& queries) {

        // Initialize DSU
        parent.resize(n + 1);
        sz.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] < b[2];
             });

        // Store queries with original indices
        vector<pair<int, int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());

        int j = 0;
        long long total = 0;

        // Process queries in increasing order
        for (auto &query : q) {

            int x = query.first;
            int idx = query.second;

            // Add edges with weight <= x
            while (j < edges.size() && edges[j][2] <= x) {

                int u = edges[j][0];
                int v = edges[j][1];

                total += unite(u, v);

                j++;
            }

            ans[idx] = total;
        }

        return ans;
    }
};