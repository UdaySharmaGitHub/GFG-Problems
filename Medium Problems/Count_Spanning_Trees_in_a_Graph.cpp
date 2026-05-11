/*
Count Spanning Trees in a Graph
Given a connected undirected graph with n vertices and m edges, where each edge is represented as edges[i]=[u,v]  indicating an edge between vertices u and v.

Determine the total number of distinct spanning trees that can be formed from the graph.

Note: A spanning tree is a subgraph of the given graph that includes all n vertices, has exactly n-1 edges, is connected, and contains no cycles; therefore, every connected undirected graph always has at least one spanning tree.

Examples:

Input: n = 6, edges = [[0, 3], [0, 1], [1, 2], [1, 5], [3, 4]]
Output: 1
Explanation: The graph has 6 vertices and 5 edges, and it is connected, so it is already a tree (m = n-1). A tree has only one spanning tree, which is the graph itself, so the answer is 1.
  
Input: n = 3, edges = [[0, 1], [0, 2], [1, 2]]
Output: 3
Explanation: There are exactly 3 possible spanning trees for the given graph. 
 
Input: n = 1, edges = []
Output: 1
Explanation: With 1 vertex, a spanning tree needs 0 edges. The graph already satisfies this, so the answer is 1.
Constraints:
1 ≤ n ≤ 10
n -1  ≤ m ≤ n*(n-1)/2
0 ≤ edges[i][0], edges[i][1] ≤ n-1
*/
/*
    Approach:
    1. We can use Kirchhoff's theorem to count the number of spanning trees in
         a graph. According to Kirchhoff's theorem, the number of spanning trees
         in a graph is equal to any cofactor of the Laplacian matrix of the graph.
    2. The Laplacian matrix L of a graph is defined as L = D - A, where D is the degree matrix and A is the adjacency matrix of the graph.
    3. The degree matrix D is a diagonal matrix where D[i][i] is the degree of vertex i, and all other entries are 0.
    4. The adjacency matrix A is a matrix where A[i][j] is 1 if there is an edge between vertices i and j, and 0 otherwise.
    5. To find the number of spanning trees, we can compute the determinant of any cofactor of the Laplacian matrix. A common choice is to remove the last row and last column of the Laplacian matrix to get the cofactor matrix, and then compute its determinant.
    6. The determinant can be computed using Gaussian elimination.

    Time Complexity: O(n^3) for computing the determinant using Gaussian elimination.
    Space Complexity: O(n^2) for storing the Laplacian matrix and its co
*/
class Solution {
  public:
     long long determinant(vector<vector<double>>& mat, int size) {
        
        double det = 1;
        
        for (int i = 0; i < size; i++) {
            
            int pivot = i;
            
            for (int j = i; j < size; j++) {
                if (abs(mat[j][i]) > 1e-9) {
                    pivot = j;
                    break;
                }
            }
            
            if (abs(mat[pivot][i]) < 1e-9)
                return 0;
            
            if (pivot != i) {
                swap(mat[pivot], mat[i]);
                det *= -1;
            }
            
            det *= mat[i][i];
            
            for (int j = i + 1; j < size; j++) {
                
                double factor = mat[j][i] / mat[i][i];
                
                for (int k = i; k < size; k++) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }
        
        return round(det);
    }
  
    int countSpanTree(int n, vector<vector<int>>& edges) {
        
        if (n == 1)
            return 1;
        
        vector<vector<double>> lap(n, vector<double>(n, 0));
        
        for (auto &e : edges) {
            
            int u = e[0];
            int v = e[1];
            
            lap[u][u]++;
            lap[v][v]++;
            
            lap[u][v]--;
            lap[v][u]--;
        }
        
        vector<vector<double>> cof(n - 1, vector<double>(n - 1));
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                cof[i][j] = lap[i][j];
            }
        }
        
        return determinant(cof, n - 1);   // code here
        
    }
};