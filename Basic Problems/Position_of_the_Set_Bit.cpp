/*
Position of the Set Bit
Given an integer n, determine position of the only set bit (1) in its binary representation. The position is counted starting from 1 at the least significant bit (LSB).

If n contains exactly one set bit, return its position.
If n contains no set bits or more than one set bit, return -1.
Examples:

Input: n = 2
Output: 2
Explanation: 2 is represented as "10" in binary. It has only one set bit, which is at position 2.
Input: n = 5
Output: -1
Explanation: 5 is represented as "101" in binary. It has two set bits; therefore, the output is -1.
Constraints:
0 ≤ n ≤ 108
*/

/*
    APPROACH:
    1. Initialize a count variable to keep track of the position of bits, starting from 1.
    2. Initialize a variable oneSetBit to count the number of set bits encountered, and a variable res to store the position of the set bit.
    3. Use a while loop to iterate through the bits of n until n becomes 0:
        a. Check if the least significant bit (n & 1) is set (i.e., equals 1). If it is, update res to the current count and increment oneSetBit.
        b. Right shift n by 1 to check the next bit in the next iteration.
        c. Increment the count variable to move to the next bit position.
        d. If at any point oneSetBit exceeds 1, return -1 immediately, as it indicates that there are more than one set bits.
    4. After the loop, check if oneSetBit is 0 (indicating no set bits) and return -1. Otherwise, return the value of res, which holds the position of the single set bit.      

    Time Complexity: O(log n) - We are iterating through the bits of n, which takes logarithmic time in relation to the value of n.
    Space Complexity: O(1) - We are using a constant amount of space to store the count, oneSetBit, and res variables.
*/
class Solution {
  public:
    int findPosition(int n) {
        // code here
        int count =1,oneSetBit = 0 ,res=0;
        while(n){
            if(n&1) {res = count;oneSetBit++;}
            n>>=1;
            count++;
            if(oneSetBit>1) return -1;
        }
        return oneSetBit==0?-1:res;
    }
};