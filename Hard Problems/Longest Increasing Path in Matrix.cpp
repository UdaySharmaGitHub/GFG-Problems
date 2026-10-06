/*
Longest Increasing Path in Matrix
Given a matrix with n rows and m columns, find the length of the longest path such that:

The path can start and end at any cell.
A cell cannot be visited more than once.
The values in path are strictly increasing. 
From each cell,  you can move left, right, up, or down.
Diagonal moves and moves outside the matrix are not allowed.
Examples:

Input: n = 3, m = 3, matrix[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: 5
Explanation: One such path is 1 -> 2 -> 3 -> 6 -> 9, where each number is strictly greater than the previous.

Input: n = 3, m = 3, matrix[][] = [[3, 4, 5], [6, 2, 6], [2, 2, 1]]
Output: 4
Explanation: One of the longest increasing paths is 3 -> 4 -> 5 -> 6.

Input: n = 2, m = 2, matrix[][] = [[1, 1], [1, 1]]
Output: 1
Explanation: There can at most one vertex as all vertices are same.
Constraints:

1 ≤ n, m ≤ 1000
0 ≤ matrix[i][j] ≤ 230
*/
class Solution {
public:
    vector<vector<int>> dirs = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
    };
    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        function<int(int, int)> dfs = [&](int x, int y) -> int {
            if (dp[y][x] != -1)
                return dp[y][x];
            int mx = 1;
            for (auto &dir: dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (0 <= nx && nx < m && 0 <= ny && ny < n && matrix[ny][nx] > matrix[y][x])
                    mx = max(mx, dfs(nx, ny) + 1);
            }

            return dp[y][x] = mx;
        };

        int ans = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++)
                ans = max(ans, dfs(x, y));
        }
        return ans;
    }
};
