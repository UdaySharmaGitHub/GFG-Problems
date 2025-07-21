/*
Count the Coprimes
You are given an array arr[] of positive integers. Your task is to count the number of pairs (i, j) such that:
0 ≤ i < j ≤ n-1
gcd(arr[i], arr[j]) = 1
In other words, count the number of unordered pairs of indices (i, j) where the elements at those positions are co-prime.
Examples:
Input: arr[] = [1, 2, 3]
Output: 3
Explanation: (0,1), (0,2), (1,2) are the pair of indices where gcd(arr[i], arr[j]) = 1
Input: arr[] = [4, 8, 3, 9]
Output: 4
Explanation: (0,2), (0,3), (1,2), (1,3) are the pair of indices where gcd(arr[i], arr[j]) = 1
Constraints:
2 ≤ arr.size() ≤ 104
1 ≤ arr[i] ≤ 104
*/
class Solution {
  public:
    int cntCoprime(vector<int>& arr) {
        // code here
        int n = arr.size(), m = 0;
        for(int i = 0; i < n; i++) m = max(m, arr[i]);
        vector<int> freq(m + 1, 0), dp(m + 1, 0);
        for(int i = 0; i < n; i++) freq[arr[i]]++;
        for(int i = m; i >= 1; i--) {
            int c = 0;
            for(int j = i; j <= m; j += i) {
                dp[i] -= dp[j];
                c += freq[j];
            }
            dp[i] += (c * (c - 1)) / 2;
        }
        return dp[1];
    }
};
