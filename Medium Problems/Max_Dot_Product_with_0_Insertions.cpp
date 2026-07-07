/*
Max Dot Product with 0 Insertions

Given two arrays a[] and b[] of positive integers of size n and m respectively, where m ≤ n.  You are allowed to insert zeros anywhere into the second array b so that its length becomes equal to n.

The dot product of two arrays of equal length n is defined as: a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1].
Return the maximum possible dot product of the two arrays.
Examples :

Input: a[] = [2, 3, 1, 7, 8], b[] = [3, 6, 7]
Output: 107
Explanation: Maximum dot product is obtained after inserting 0 at the first and third positions in array b.
Therefore b becomes [0, 3, 0, 6, 7]. 
Maximum dot product = 2*0 + 3*3 + 1*0 + 7*6 + 8*7 = 107. Therefore answer for this test case is 107.
Input: a[] = [1, 2, 3], b[] = [4] 
Output: 12 
Explanation: Maximum dot product is obtained after inserting 0 at the first and second positions in array b.
Therefore b becomes [0, 0, 4]. 
Maximum Dot Product = 1*0 + 2*0 + 3*4 = 12. Therefore answer for this test case is 12.
Constraints:
1 ≤ m ≤ n ≤ 103
1 ≤ a[i], b[i] ≤ 103
*/
class Solution {
    public:
  int solve(vector<int>&a,vector<int>&b,int i,int j, vector<vector<int>>& dp){
        int n = a.size() , m = b.size();
        
        // Initially I solved with 3 dp state but then I realised that k can be derieved from i,j
        int k = n - i - m + j;
        
        if(i >= n || j >= m || k < 0)return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(k == 0){
            int ans = 0;
            for(;j<m && i<n;i++){
                ans += a[i] * b[j];
                j++;
            }
            return dp[i][j] = ans;
        }
        
        // take i
        int t1 = a[i] * b[j] + solve(a,b,i+1,j+1,dp);
        
        // leave i
        int t2 = solve(a,b,i+1,j,dp);
        
        return dp[i][j] = max(t1,t2);
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size();int m = b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(a,b,0,0,dp);
    }
};
