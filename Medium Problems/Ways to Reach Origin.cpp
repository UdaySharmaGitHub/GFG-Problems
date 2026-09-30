/*
Ways to Reach Origin
Geek is standing at a point (x, y) on a 2D grid and wants to reach the origin (0, 0).
From any point, Geek can move in only two directions: left, from (x, y) to (x - 1, y), or down, from (x, y) to (x, y - 1).
Find the total number of distinct paths for Geek to reach (0, 0) from (x, y). Since the answer can be very large, return it modulo 109+7.
Examples:
Input: x = 3, y = 0
Output: 1
Explanation: The only possible path is (3, 0) -> (2, 0) -> (1, 0) -> (0, 0), since y = 0, there is no option to move down at any step.
Input: x = 3, y = 6
Output: 84
Explanation: There are a total of 84 distinct paths from (3, 6) to (0, 0) using only left and down moves.
Constraints:
0 ≤ x, y ≤ 500
*/
class Solution {
  public:
    int ways(int x, int y) {
        // code here
        vector<int>dp(y+1,1);
        int mod = 1e9 + 7;

        for(int i=1;i<=x;i++){
            int pre = 1;
            for(int j=1;j<=y;j++){
                dp[j] = (pre+dp[j])%mod;
                pre = dp[j];
            }
        }

        return dp[y];
    }
};