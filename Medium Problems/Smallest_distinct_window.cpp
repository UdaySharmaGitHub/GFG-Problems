/*
Smallest distinct window

Given a string str, your task is to find the length of the smallest window that contains all the characters of the given string at least once.
Example:
Input: str = "aabcbcdbca"
Output: 4
Explanation: Sub-String "dbca" has the smallest length that contains all the characters of str.
Input: str = "aaab"
Output: 2
Explanation: Sub-String "ab" has the smallest length that contains all the characters of str.
Input: str = "geeksforgeeks"
Output: 7
Explanation: There are multiple substring with smallest length that contains all characters of str, "eksforg" and "ksforge". 
Constraints:
1 ≤ str.size() ≤ 105
str contains only lower-case english alphabets.
*/


class Solution {
    public:
      int findSubString(string& str) {
          // code here
          int n = str.length() ;
          int ans = n ;
          
          int distinct = 0 ;
          for(char ch : str){
              distinct = distinct | (1 << (ch - 'a')) ;
          }
          int i = 0 ; 
          int j = 0 ; 
          
          vector<int>alph(26 , 0) ;
          int present = 0 ;
          while(i < n){
              int ch = str[i] - 'a' ; 
              alph[ch] ++ ;
              present = present | (1 << ch) ;
              
              while(j <= i && present == distinct){
                  ans = min(i - j + 1 , ans) ;
                  int temp = str[j] - 'a' ;
                  alph[temp] -- ;
                  if(alph[temp] == 0) present = present & (~(1 << temp)) ;
                  j ++ ;
              }
              
              i ++ ;
          }
          return ans ;
      }
  };