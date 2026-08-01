/*
Subsets with Products of Distinct Primes
Given an integer array arr[], count the number of different subsets whose product can be represented as a product of one or more distinct prime numbers.  Two subsets are considered different if the set of chosen array indexes are not same.

Return the count modulo 109 + 7.

Examples:

Input: arr[] = [1, 2, 3, 4]
Output: 6
Explanation: 
The subsets are:
[2], product = 2 = 2
[3], product = 3 = 3
[1, 2], product = 2 = 2
[1, 3], product = 3 = 3
[2, 3], product = 6 = 2 × 3
[1, 2, 3], product = 6 = 2 × 3
All these products can be expressed as a product of one or more distinct prime numbers. Hence, the count is 6.
Note that [4] or any other subset with 4 are not chosen because prducts having 4 have repeated primes 2.
Input: arr[] = [2, 2, 3]
Output: 5
Explanation: 
Since subsets formed using different indices are considered different, the chosen subsets are:
[2] (using the first 2)
[2] (using the second 2)
[3]
[2, 3] (using the first 2)
[2, 3] (using the second 2)
Each subset has a product that can be expressed as a product of one or more distinct prime numbers. 
Therefore, the answer is 5.

Constraints:

1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 30
*/
class Solution {
  public:
       int countSubsets(vector<int>& arr) {
        const int MOD = 1000000007;

        // 1. Count frequencies in O(N)
        int freq[31] = {0};
        for (int x : arr) {
            freq[x]++;
        }

        // 2. Hardcoded bitmasks for primes up to 30. -1 means the number has a square factor.
        // Primes represented: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29
        const int masks[31] = {
            0, 0, 1, 2, -1, 4, 3, 8, -1, -1, 5, 16, -1, 32, 9, 6,
            -1, 64, -1, 128, -1, 10, 17, 256, -1, -1, 33, -1, -1, 512, 7
        };

        // 3. DP array using fast stack memory
        int dp[1024] = {0};
        dp[0] = 1;

        // DP state transitions: O(30 * 1024)
        for (int x = 2; x <= 30; x++) {
            if (masks[x] == -1 || freq[x] == 0) continue;
            
            int m_x = masks[x];
            int count = freq[x];
            
            for (int m = 1023; m >= 0; m--) {
                // If there's no overlapping prime factors
                if ((m & m_x) == 0) {
                    dp[m | m_x] = (dp[m | m_x] + 1LL * dp[m] * count) % MOD;
                }
            }
        }

        // 4. Sum valid combinations (ignoring dp[0] which is the empty set)
        long long ans = 0;
        for (int m = 1; m < 1024; m++) {
            ans = (ans + dp[m]) % MOD;
        }

        // 5. Binary Exponentiation for 2^freq[1] in O(log N) time
        long long mul = 1;
        long long base = 2;
        int exp = freq[1];
        while (exp > 0) {
            if (exp % 2 == 1) mul = (mul * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }

        return (ans * mul) % MOD;
    }
};