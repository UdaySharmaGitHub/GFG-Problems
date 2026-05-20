/*
Check if All Bits Set
Given a number n, check whether every bit in the binary representation of the given number is set or not.

Return true if yes, otherwise false.

Examples :

Input: n = 7
Output: true
Explanation: Binary for 7 is 111 all the bits are set so the output is true.
Input: n = 8
Output: false
Explanation: Binary for 8 is 1000 all the bits are not set so the output is false.
Input: n = 0
Output: false
Explanation: All the bits are 0 so the output is false.
Constraints:
0 ≤ n ≤ 105
*/
/*
    APPROACH: 
    1. We can check if n is of the form 2^k - 1, which means all bits are set.
    2. To check if n is of the form 2^k - 1, we can use the property that (n + 1) & n should be 0.
    3. If n is 0, we should return false since all bits are not set.

    Time Complexity: O(1)
    Space Complexity: O(1)
*/
class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(n==0) return 0;
        return (((n+1)&n) == 0);
    }
};