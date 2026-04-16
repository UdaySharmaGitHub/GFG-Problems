/*
Anagram Palindrome
Given a string s, determine whether its characters can be rearranged to form a palindrome. Return true if it is possible to rearrange the string into a palindrome; otherwise, return false.
Examples
Input: s = "baba"
Output: true
Explanation: Can be rearranged to form a palindrome "abba" 
Input: s = "geeksogeeks"
Output: true
Explanation: The characters of the string can be rearranged to form the palindrome "geeksoskeeg".
Input: s = "geeksforgeeks"
Output: false
Explanation: The given string can't be converted into a palindrome.
Constraints:
1 ≤ s.length ≤ 106
s consists of only lowercase English letters.
*/
class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        vector<int> freq(26,0);
        for(char ch:s){
            if(freq[ch-'a']) freq[ch-'a']--;
            else freq[ch-'a']++;
        }
        int count1 = 0 ;
        for(int i:freq) if(i==1) count1++;
        return count1>1?0:1;
                
    }
};