/*
Equal Point in Brackets

Given a string s of opening and closing brackets '(' and ')' only, find an equal point in the string. An equal point is a position k (0-based) such that the number of opening brackets before position k is equal to the number of closing brackets from position k to the end of the string. If multiple such points exist, return the first valid position.

The string can be split at any position from 0 to n, where n is the length of the string.
If we split at 0, it means there is an empty string on left.
If we split at n, it means there is an empty string on right.
Examples:

Input: s = "(())))("
Output: 4
Explanation:
 
Input : s = "))"
Output: 2
Explanation: After index 2, the string splits into "))" and an empty string. The number of opening brackets in the first part is 0 and the number of closing brackets in the second part is also 0.
Constraints:
1 ≤ s.size() ≤ 105
*/
/*
    APPROACH:  
    1. Count the total number of closing brackets in the string and store it in a variable 'cl'.
    2. Initialize a variable 'op' to count the number of opening brackets encountered so far.
    3. Iterate through the string character by character:
       a. If the current character is an opening bracket '(', increment 'op'.
       b. If the current character is a closing bracket ')', decrement 'cl'.
       c. After updating 'op' and 'cl', check if 'op' is equal to 'cl'. If they are equal, return the current index as the equal point.
    4. If the loop ends and 'op' is equal to 'cl', return the length of the string as the equal point (indicating that all opening brackets are matched with closing brackets).
    5. If no equal point is found, return -1.

    Time Complexity: O(n), where n is the length of the string.
    Space Complexity: O(1), as we are using only a constant amount of extra space
*/
class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int n=s.length();
        int cl=0;
        for(int i=0; i<n; i++){
            if(s[i]==')') cl++;
        }

        int op=0;
        for(int i=0; i<n; i++){
            if(op==cl) return i;
            if(s[i]=='('){
                op++;
            }else cl--;
        }
        if(op==cl) return n;
        return -1; 
    }
};