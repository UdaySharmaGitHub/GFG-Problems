/*
Divisible by 13
Given a number represented as a string s (which may be very large), check whether it is divisible by 13 or not.
Examples:
Input : s = "2911285"
Output : true
Explanation: 2911285 ÷ 13 = 223945, which is a whole number with no remainder.
Input : s = "27"
Output : false
Explanation: 27 / 13 ≈ 2.0769..., which is not a whole number (there is a remainder).
Constraints:
1 ≤  s.size()  ≤ 105
*/
class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int i =0 , temp = 0 ;
        bool res = 0;
        while(i<s.size()){
            while(temp<13 && i<s.size()) temp = temp*10 + (s[i++]-'0');
            temp%=13;
        }
        return temp%13 == 0;
    }
};