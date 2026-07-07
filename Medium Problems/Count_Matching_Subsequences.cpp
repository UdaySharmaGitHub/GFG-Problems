/*
Count Matching Subsequences
Given two strings, s1 and s2, count the number of subsequences of string s1 equal to string s2.

Return the total count modulo 1e9+7.

Examples :

Input: s1 = "geeksforgeeks", s2 = "gks"
Output: 4
Explanation: We can pick characters from s1 as a subsequence from indices [0, 3, 4], [0, 3, 12], [0, 11, 12] and [8, 11, 12]. So total 4 subsequences of s1 that are equal to s2.
Input: s1 = "problemoftheday", s2 = "geek"
Output: 0
Explanation: No subsequence of string s1 is equal to string s2.
Constraints:
1 ≤ s1.size(), s2.size() ≤ 103
*/
class Solution {
  public:
    int mod=1e9+7;
    int solve(int i, int j, int n, int m, string  &s, string &t, vector<vector<int>>&dp){

        if(j==m){
            return 1;
        }
        if(i==n){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;

        if(s[i]==t[j]){
            ans=(ans+solve(i+1, j+1, n, m, s, t, dp))%mod;
        }

        ans=(ans+solve(i+1, j, n, m, s, t, dp))%mod;

        return dp[i][j]=ans;
    }

    int countWays(string &s1, string &s2) {
        // code here
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(0, 0, n, m, s1, s2, dp);

    }
};
