/*
Check Subset sum divisible by k
Given an array arr[] of positive integers and a value k. Return true if the sum of any non-empty subset of the given array is divisible by k otherwise, return false.

Examples:

Input: arr[] = [3, 1, 7, 5] , k = 6
Output: true
Explanation: If we take the subset {7, 5} then sum will be 12 which is divisible by 6.
Input: arr[] = [1, 2, 6] , k = 5
Output: false
Explanation: All possible subsets of the given set are {1}, {2}, {6}, {1, 2}, {2, 6}, {1, 6} and {1, 2, 6}. There is no subset whose sum is divisible by 5.
Constraints:
1 ≤ arr.size(), k ≤ 103
1 ≤ arr[i] ≤ 103
*/
class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        // code here
        vector<bool> dp(k, false);
    
    for(int &val: arr) {
        int rem = val % k;
        
        // Early stop
        if(rem == 0) {
            return true;
        }
        
        // In next marking all, curr and its sums as true
        vector<bool> next(dp);
        next[rem] = true;
        
        // Adding to others
        for(int i = 0; i < k; i++) {
            if(dp[i]) {
                int rem2 = (rem + i) % k;
                
                // Early stop
                if(rem2 == 0) {
                    return true;
                }
                
                next[rem2] = true;
            }
        }
        
        // Updation
        dp = next;
    }
    
    return dp[0];
    }
};