/*
Count Prefix-Balanced Binary Strings
Given an integer n, count the number of binary strings of length 2 * n that contain exactly n ones and n zeros such that every prefix of the string contains at least as many ones as zeros. Since the answer can be very large, return it modulo 109 + 7.

Examples:

Input: n = 2
Output: 2
Explanation: "1100", "1010" are two such strings of size 4 which have exactly two 1's in each.
Input: n = 3
Output: 5
Explanation: "111000", "101100", "101010", "110010", "110100" are such 5 strings which have exactly three 1's in each.
Constraints:

1 ≤ n ≤ 1000
*/
class Solution {
  public:
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;

        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % mod;
            }

            base = (base * base) % mod;
            exp >>= 1;
        }

        return result;
    }

    int prefixStrings(int n) {
        const long long MOD = 1000000007LL;
        long long factN = 1;
        long long fact2N = 1;

        for (int i = 1; i <= 2 * n; i++) {
            fact2N = (fact2N * i) % MOD;

            if (i <= n) {
                factN = (factN * i) % MOD;
            }
        }

        long long inverseFactN = power(factN, MOD - 2, MOD);

        long long inverseNPlusOne = power(n + 1, MOD - 2, MOD);

        long long answer = fact2N;
        answer = (answer * inverseFactN) % MOD;
        answer = (answer * inverseFactN) % MOD;
        answer = (answer * inverseNPlusOne) % MOD;

        return (int)answer;
    }
};