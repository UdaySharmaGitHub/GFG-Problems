/*
Implement Atoi
Given a string, s, the objective is to convert it into integer format without utilizing 
any built-in functions. If the conversion is not feasible, the function should return -1.
Note: Conversion is feasible only if all characters in the string are numeric 
or if its first character is '-' and rest are numeric.
Example 1:
Input:
s = "-123"
Output: 
-123
Explanation:
It is possible to convert -123 into an integer 
and is so returned in the form of an integer
Example 2:
Input:
s = "21a"
Output: 
-1
Explanation: 
The output is -1 as, due to the inclusion of 'a',
the given string cannot be converted to an integer.
Your Task:
You do not have to take any input or print anything. Complete the function atoi() 
which takes a string s as an input parameter and returns an integer value representing
 the given string. If the conversion is not feasible, the function should return -1.
|s| = length of string str.
Expected Time Complexity: O( |s| ), 
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ |s| ≤ 10
*/
//{ Driver Code Starts
//Initial template for C++
class Solution {
  public:
    int myAtoi(string s) {
        // Your code here
          // code here
        int sign = 1, r = 0, i = 0;
        while(s[i] == ' ')      i++;        // ignore whitespaces
        if(s[i] == '-' || s[i] == '+'){
            if(s[i++] == '-')       sign = -1;
        }
        while(s[i] >= '0' && s[i] <= '9'){ 
            if(r > INT_MAX/10 || r == INT_MAX/10 && s[i]-'0' > 7)     
                return      sign == 1 ? INT_MAX : INT_MIN;
            r = 10*r+(s[i++]-'0');
        }
        return  r*sign;
       
    }
};
