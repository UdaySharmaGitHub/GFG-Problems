/*
Trail of ones
Given an integer n, the task is to count the number of binary strings of length n that contains at least one pair of consecutive 1's.
Note: A binary string is a sequence made up of only 0's and 1's.
Examples:
Input: n = 2
Output: 1
Explanation: There are 4 strings of length 2, the strings are 00, 01, 10, and 11. Only the string 11 has consecutive 1's.
Input: n = 3
Output: 3
Explanation: There are 8 strings of length 3, the strings are 000, 001, 010, 011, 100, 101, 110 and 111. The strings with consecutive 1's are 011, 110 and 111.
Input: n = 5
Output: 19
Explanation: There are 19 strings having at least one pair of consecutive 1's.
Constraints:
2 ≤ n ≤ 30
*/
/*
    Using DP
Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
  public:
    int countConsec(int n) {
        // code here
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    // Iterate from i = n to 1
    for (int i = n; i >= 1; i--) {
        for (int prev = 0; prev <= 1; prev++) {
            if (prev == 0) {
                // place '0' or '1'
                dp[i][prev] = dp[i + 1][0] + dp[i + 1][1];
            } else {
                // place '0' after '1'
                dp[i][prev] = dp[i + 1][0];

                // place '1' after '1' → found one pair of consecutive '1's,
                // rest (n - i) bits can be anything: 2^(n - i)
                dp[i][prev] += (1 << (n - i));  // 2^(n - i)
            }
        }
    }

    // start from index 1, with prev = 0
    return dp[1][0];  
    }
};