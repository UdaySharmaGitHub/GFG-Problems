/*
Subsets with MEX in Range
Given an array arr[] of integers and a range [l, r], count the number of subsets whose Minimum Excluded (MEX) value lies within the given range, inclusive.

Minimum Excluded (or MEX) of a subset is the smallest non-negative integer that is not present in the subset.
An empty subset has Minimum Excluded as zero.
Since the answer can be very large, return the answer modulo 109 + 7.

Examples:

Input: arr[] = [2, 0, 1, 0], l = 1, r = 2
Output: 9
Explanation: The subsets whose MEX lies in the range [1, 2] are counted as follows:
MEX = 1: The subsets must contain at least one 0 and must not contain 1. These subsets are [0] (2 ways), [2, 0] (2 ways), [0, 0] (1 way), and [2, 0, 0] (1 way). Total = 6.
MEX = 2: The subsets must contain both 0 and 1 but must not contain 2. These subsets are [0, 1] (2 ways) and [0, 1, 0] (1 way). Total = 3.
The subsets [2, 0, 1] and [2, 0, 1, 0] have MEX = 3, which is outside the given range. Therefore, the total number of valid subsets is 6 + 3 = 9.
Input: arr[] = [2, 0, 1], l = 1, r = 2
Output: 3
Explanation: The subsets whose MEX lies in the range [1, 2] are [0] (MEX = 1), [2, 0] (MEX = 1), and [0, 1] (MEX = 2). Hence, the answer is 3.
Constraints:

2 ≤ arr.size() ≤ 105
0 ≤ arr[i], r ≤ arr.size()
0 ≤ l ≤ r
*/
class Solution {
  public:
    long long modpow(long long base, long long exp, long long mod) {
           long long res = 1;
           base %= mod;
           while (exp > 0) {
               if (exp & 1) res = res * base % mod;
               base = base * base % mod;
               exp >>= 1;
           }
           return res;
       }
       int cntSubsets(vector<int> &arr, int l, int r) {
           const long long MOD = 1000000007;
           int n = arr.size();
           vector<int> freq(n + 1, 0);
           for (int x : arr) if (x <= n) freq[x]++;
           vector<long long> p2(n + 1, 1);
           for (int i = 1; i <= n; i++) p2[i] = p2[i - 1] * 2 % MOD;
           long long ans = 0, cur_prod = 1, cum = 0;
           for (int k = 0; k <= r; k++) {
               if (k > 0) {
                   if (freq[k - 1] == 0) cur_prod = 0;
                   else cur_prod = cur_prod * (p2[freq[k - 1]] - 1 + MOD) % MOD;
               }
               cum += freq[k];
               if (cur_prod != 0) {
                   long long free = p2[n] * modpow(p2[cum], MOD - 2, MOD) % MOD;
                   long long ways = cur_prod * free % MOD;
                   if (k >= l) ans = (ans + ways) % MOD;
               }
           }
           return (int)ans;
       }
};