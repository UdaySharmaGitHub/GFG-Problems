/*
Numbers Without d as Digit
Given a number n, count the numbers from 1 to n that don’t contain digit d in their decimal representation.

Examples:

Input: n = 25, d = 3
Output: 22
Explanation: From 1 to 25, the numbers 3, 13, and 23 contain the digit 3, so the answer is 25 - 3 = 22.
Input: n = 5, d = 3
Output: 4
Explanation: From 1 to 5, only 3 contains the digit 3, so the count of numbers without digit 3 is 4.
Constraints:

0 ≤ n ≤ 109
0 ≤ d ≤ 9
*/
class Solution {
    int f(int i, int t, int c, int m, int &d, vector<int> &digits, vector<vector<vector<int>>> &dp) {
        if(i == m) return c;
        if(dp[i][t][c] != -1) return dp[i][t][c];
        int ans = 0;
        for(int k = 0; k < 10; k++) {
            if((k != 0 || c != 0) && ((k == d) || (t == 0 && k > digits[i]))) continue;
            ans += f(i + 1, t | (k < digits[i]), c | (k != 0), m, d, digits, dp);
        }
        return dp[i][t][c] = ans;
    }
  public:
    int countWithout(int &n, int &d) {
        // code here
        vector<int> digits;
        for(int i = n; i > 0; i /= 10) digits.push_back(i % 10);
        vector<vector<vector<int>>> dp(digits.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        reverse(digits.begin(), digits.end());
        int ans = f(0, 0, 0, digits.size(), d, digits, dp);
        return ans;
    }
};