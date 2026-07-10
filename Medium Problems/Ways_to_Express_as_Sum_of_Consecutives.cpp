/*
Ways to Express as Sum of Consecutives
Given a number n, find the number of ways to represent this number as a sum of 2 or more consecutive natural numbers.

Examples:

Input: n = 10
Output: 1
Explanation: There is only one way, 10 = 1+2+3+4.
Input: n = 15
Output: 3
Explanation: There are 3 ways, (15 = 1+2+3+4+5), (15 = 4+5+6) and (15 = 7+8).
Constraints:
1 ≤ n ≤ 108
*/
class Solution {
  public:
    int getCount(int n) {
        // code here
          int count = 0;
        // The sum of 1 to k is k*(k+1)/2. 
        // We stop when this sum exceeds n.
        for (long long k = 2; (k * (k + 1)) / 2 <= n; ++k) {
            // Check if (n - sum_of_0_to_k-1) is divisible by k
            long long numerator = n - (k * (k - 1)) / 2;
            if (numerator > 0 && numerator % k == 0) {
                count++;
            }
        }
        return count;
    }
};