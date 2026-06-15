/*
Minimum Cost to Fill Given Weight
Given a bag of size w kg and you are provided costs of packets different weights of oranges in array cost[], find the minimum total cost to buy exactly w kg oranges

The cost of 1 kg orange is present at index 0 and in general arr[i] has cost of (i+1) kg orange.
cost[i] = -1 means that 'i+1' kg packet of orange is unavailable.
If it is not possible to buy exactly w kg oranges then return -1. It may be assumed that there is an infinite supply of all available packet types.
Examples:

Input: cost[] = [20, 10, 4, 50, 100], w = 5
Output: 14
Explanation: The minimum cost is 14 by purchasing a 2kg packet for 10 and a 3kg packet for 4.
Input: cost[] = [-1, -1, 4, 3, -1], w = 5
Output: -1
Explanation: It is not possible to buy 5 kgs.
Constraints:
1 ≤ cost.size(), w ≤ 2*103
1 ≤ cost[i] ≤ 105
*/
class Solution {
  public:
     int solve(vector<int> &cost,int n,int w,int idx,vector<vector<int>>&dp){
      if(w==0) return 0;
        
      if(idx>=n||w<0) return INT_MAX;
        
      if(dp[idx][w]!=-1) return dp[idx][w];
        
      int take=INT_MAX;
      if(cost[idx]!=-1){
        int result=solve(cost,n,w-(idx+1),idx,dp);
        if(result!=INT_MAX){
            take=cost[idx]+result;
        }
      }
        
        int notTake=solve(cost,n,w,idx+1,dp);
        
        return dp[idx][w]=min(take,notTake);
        
    }
    int minimumCost(vector<int> &cost, int w) {
        // code here
        int n=cost.size();
        
        vector<vector<int>>dp(n,vector<int>(w+1,-1));
        int result=solve(cost,n,w,0,dp);
        
        return result!=INT_MAX?result:-1;
        
    }
};
