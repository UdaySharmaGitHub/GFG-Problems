/*
Longest Repeating Character Replacement
Given a string s of length n consisting of uppercase English letters and an integer k, you are allowed to perform at most k operations.  In each operation, you can change any character of the string to any other uppercase English letter.

Determine the length of the longest substring that can be transformed into a string with all identical characters after performing at most k such operations.

Examples:

Input: s = "ABBA", k = 2 
Output: 4 
Explanation: The string "ABBA" can be fully converted into the same character using at most 2 changes. By replacing both 'A' with 'B', it becomes "BBBB". Hence, the maximum length is 4.
Input: s = "ADBD", k = 1
Output: 3
Explanation: In the string "ADBD", we can make at most 1 change. By changing 'B' to 'D', the string becomes "ADDD", which contains a substring "DDD" of length 3.
Constraints:
1 ≤ n, k ≤ 105
s consists of only uppercase English letters.
*/
class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
         int ans =0;
         int n = s.size();
          for(char c = 'A' ;c <= 'Z'; c++){
              int i =0 , j = 0,temp = k;
              while( j<n){
                  if( s[j] != c && temp ==0){
                       while( i<=j && s[i]==c) i++;
                        i++;
                        temp++;
                  } 
                  if( s[j] != c && temp >0){
                      temp--;
                  }
                   j++;
                    ans = max ( ans , j-i);
              }
          }
           return ans;

    }
};