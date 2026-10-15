/*
Maximum Without 3 Consecutive Set Bits
Given a non-negative integer n, you can only change a set bit (1) to an unset bit (0). Find the maximum possible value of n such that its binary representation does not contain three consecutive set bits (111) after performing zero or more allowed operations.

Examples:

Input: n = 2
Output: 2
Explanation: The binary representation of 2 is 10, which does not contain three consecutive set bits. Therefore, no change is required.
Input: n = 7
Output: 6
Explanation: The binary representation of 7 is 111, which contains three consecutive set bits. Changing the rightmost set bit to 0 gives: 111 -> 110. Thus, the maximum possible value is 6.
Constraints:

0 ≤ n ≤ 109
*/
class Solution {
  public:
    int maxValue(int n) {
        // code here
        int i=31;
               int c = 0;
               while(i >= 0){
                   if(n&(1<<i))
                       c++; //set bit found
                   else
                       c = 0; //unset bit found
                   if(c == 3){
                       n = (n&(~(1<<i))); // clearing the current bit
                       c = 0;
                   }
                   i--;
               }
               return n;
    }
};