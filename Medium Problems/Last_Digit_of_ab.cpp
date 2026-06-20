/*
Last Digit of a^b
Given two integers a and b in the form of strings. Return the last digit of ab.

Examples:

Input: a = "3", b = "10"
Output: 9
Explanation: 310 = 59049. Last digit is 9.
Input: a = "6", b = "2"
Output: 6
Explanation: 62 = 36. Last digit is 6.
Constraints:
1 ≤ a.size(), b.size() ≤ 1000
a and b consist only of numeric digits ('0' - '9')
a and b do not contain any leading zeros, except when number itself is "0"
*/

class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        // code here
        if(b=="0")return 1;
         int last_digit= a.back()-'0';
         int mod= 0;
         for(char ch: b){
            mod= (mod*10 + (ch-'0'))%4;
         }
         if(mod==0){
            mod=4; 
         }
         int ans=1;
        for(int i=0; i<mod; i++){
            ans= (ans*last_digit) %10;
        } 
        
        return ans;
    }
};