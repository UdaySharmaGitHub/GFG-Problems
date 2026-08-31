/*
Minimum Cost for n Characters
Given four integers n, i, d, and c, where:

i is the cost of inserting a single character,
d is the cost of deleting the last character,
c is the cost of copying the entire current string and pasting it immediately (thereby doubling its length).
Find the minimum cost required to obtain exactly n characters on the screen. Initially, the screen is empty.

Examples:

Input: n = 9, i = 1, d = 2, c = 1
Output: 5
Explanation: Perform the following operations:
Insert (1 character)
Insert (2 characters)
Copy-paste (4 characters)
Copy-paste (8 characters)
Insert (9 characters)
Total cost = 1 + 1 + 1 + 1 + 1 = 5.
Input: n = 9, i = 10, d = 1, c = 1
Output: 17
Explanation: Perform the following operations:
Insert (1 character)
Copy-paste (2 characters)
Copy-paste (4 characters)
Delete (3 characters)
Copy-paste (6 characters)
Delete (5 characters)
Copy-paste (10 characters)
Delete (9 characters)
Total cost = 10 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 17.
Since insertion is expensive, it is cheaper to use copy-paste operations and adjust the length using deletions.
Constraints:

1 ≤ n ≤ 106
1 ≤ i, d, c ≤ 100
*/
class Solution {
  public:
    int solve(int n, int i, int d, int c, vector<int>& dp) {

        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return i;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int ans = i * n;

        if (n % 2 == 0) {
            ans = min(ans, c + solve(n/2, i, d, c, dp));
        } else {
            // apply one extra add ko delete kiya then copy laga diya
            ans = min(ans, d + c + solve((n+1)/2, i, d, c, dp));
            // ek extra remove karka man liya fir add kar denga toh dono cost add kar de
            ans = min(ans, i + c + solve((n-1)/2, i, d, c, dp));
        }

        return dp[n] = ans;
    }
    int minCost(int n, int i, int d, int c) {
        // code here
        // vector<int> dp(n+1, -1);
        vector<int> dp(n+1, 0);

        dp[0] = 0;
        dp[1] = i;

        for (int x = 2; x <= n; x++) {

            dp[x] = i * x;

            if (x % 2 == 0) {
                dp[x] = min(dp[x], c + dp[x/2]);
            } else {
                dp[x] = min(dp[x], d + c + dp[(x+1)/2]);
                dp[x] = min(dp[x], i + c + dp[(n-1)/2]);
            }
        }

        return dp[n];
        // return solve(n, i, d, c, dp);
    }
};
