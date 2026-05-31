/*
Express as Consecutive Number Sum
Given a number n, find whether n can be expressed as sum of two or more consecutive positive numbers.
Examples :
Input: n = 10
Output: true
Explanation: 10 can be expressesd as 1 + 2 + 3 + 4.
Input: n = 8
Output: false
Explanation: 8 can't be expressesd sum of two or more consecutive numbers.
Input: n = 24
Output: true
Explanation: 24 can be expressesd as 7 + 8 + 9.
Constraints:
1 ≤ n ≤ 109
*/
class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        // code here
      if (n == 1) return 0;
    // Check if n is power of 2
    if ((n & (n - 1)) == 0)return 0;
    return 1;
    }
};