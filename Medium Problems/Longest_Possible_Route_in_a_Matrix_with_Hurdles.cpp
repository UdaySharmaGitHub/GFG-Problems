/*
Longest Possible Route in a Matrix with Hurdles
Given a binary matrix mat[][] of size n × m containing values 0 and 1, and four integers xs, ys, xd, and yd representing the source cell (xs, ys) and destination cell (xd, yd), find the length of the longest possible path from the source cell to the destination cell. From any cell, you can move to its adjacent cells in the up, down, left, and right directions.

1 represents a traversable cell.
0 represents a blocked cell that cannot be visited.
A cell can be visited at most once in a path.
If the destination cannot be reached from the source, return -1.
Examples:

Input: mat[][] = [[1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [1, 1, 0, 1, 1, 0, 1, 1, 0, 1],[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]], xs = 0, ys = 0, xd = 1, yd = 7
Output: 24 
Explanation: The longest valid path from (0, 0) to (1, 7) without revisiting any cell has length 24. 

Input: mat[][] = [[1, 0, 0, 1, 0],[0, 0, 0, 1, 0],[0, 1, 1, 0, 0]], xs = 0, ys = 3, xd = 2, yd = 2
Output: -1
Explanation: The destination cell (2, 2) cannot be reached from the source cell (0, 3), so the answer is -1.
 
Constraints:
1 ≤ n, m ≤ 10
mat[i][j] == 0 or mat[i][j] == 1
The source and destination cells are always inside the matrix.
*/
class Solution {
   public:
    int n, m;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int dfs(vector<vector<int>>& mat, vector<vector<bool>>& vis,
            int x, int y, int xd, int yd) {

        if (x == xd && y == yd)
            return 0;

        vis[x][y] = true;

        int ans = -1;

        for (int k = 0; k < 4; k++) {

            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                mat[nx][ny] == 1 &&
                !vis[nx][ny]) {

                int cur = dfs(mat, vis, nx, ny, xd, yd);

                if (cur != -1)
                    ans = max(ans, cur + 1);
            }
        }

        vis[x][y] = false;

        return ans;
    }

    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {

        n = mat.size();
        m = mat[0].size();

        if (mat[xs][ys] == 0 || mat[xd][yd] == 0)
            return -1;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        return dfs(mat, vis, xs, ys, xd, yd);
    }
};