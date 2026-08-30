/*
Count Subsequences Divisible by n
Given a numeric string s containing only digits and an integer n, count the number of non-empty subsequences of s whose numeric value is divisible by n. Return the answer modulo 1e9 + 7.

Examples:

Input: s = "1234", n = 4
Output: 4
Explanation: The subsequences 4, 12, 24 and 124 are divisible by 4.
Input: s = "330", n = 6
Output: 4
Explanation: The subsequences 30, 30, 330 and 0 are divisible by 6.
Constraints:
1 ≤ |s| * n ≤ 106
*/
class Solution {
  public:
    int fun(string& s,int ind ,int n, int rem ,vector<vector<int>>&dp )
    {
        if(ind==s.size())
        {
            if(rem ==0)
            {
                return 1;

            }
            else return 0;

        }
        if(dp[ind][rem]!=-1)
            return dp[ind][rem];

        //pick a element
        int digit = s[ind]-'0';
        int newrem = (rem*10 + digit)%n;
        int pick =fun(s,ind+1,n,newrem,dp);
        //not picking an element
        int notpick =fun(s,ind+1,n,rem,dp);
        return dp[ind][rem]= (pick + notpick)%1000000007;
    }
     int countSubsequences(string& s, int n) {
         vector<vector<int>>dp(s.size(),vector<int>(n,-1));
         return fun(s,0,n,0,dp)-1;


     }
};