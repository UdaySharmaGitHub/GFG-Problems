/*
Check for Power
Given two positive integers x and y, determine if y is a power of x. If y is a power of x, return true. Otherwise, return false.
Examples:
Input: x = 2, y = 8
Output: true 
Explanation: 23 is equal to 8.
Input: x = 1, y = 8
Output: false
Explanation: Any power of 1 is not equal to 8.
Input: x = 46, y = 205962976
Output: true
Explanation: 465 is equal to 205962976.
Input: x = 50, y = 312500000
Output: true
Explanation: 505 is equal to 312500000.
Constraints:
1 ≤ x ≤ 103
1 ≤ y ≤ 109
*/
class Solution {
  public:
    bool isPower(int x, int y) {
        // code here
        if(y==1)return true;
        if(x==0)return false;
        if(x==1)return y==1;
        while(y%x==0)   y=y/x;
        return y==1;
    }
};