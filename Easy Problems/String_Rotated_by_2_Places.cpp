/*
String Rotated by 2 Places
Given two strings s1 and s2. Return true if the string s2 can be obtained by rotating (in any direction) string s1 by exactly 2 places, otherwise, false.
Note: Both rotations should be performed in same direction chosen initially.
Examples:
Input: s1 = "amazon", s2 = "azonam"
Output: true
Explanation: "amazon" can be rotated anti-clockwise by two places, which will make it as "azonam".
Input: s1 = "geeksforgeeks", s2 = "geeksgeeksfor"
Output: false
Explanation: If we rotate "geeksforgeeks" by two place in any direction, we won't get "geeksgeeksfor".
Input: s1 = "ab", s2 = "ab"
Output: true
Explanation: If we rotate "ab" by two place in any direction, we always get "ab".
Challenge: Try doing it in O(1) space complexity
Constraints:
1 ≤ s1.length, s2.length ≤ 105
*/
class Solution {
  public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    string reverseBy2(string s,int k){
        reverse(s.begin(),s.begin()+k);
        reverse(s.begin()+k,s.end());
        reverse(s.begin(),s.end());
        
        return s;
    }
    bool isRotated(string& s1, string& s2) {
        // Your code here
        if(s1.size() <=2) return (s1==s2)?1:0;
        string s2lr = reverseBy2(s2,2) , s2rr = reverseBy2(s2,s2.size()-2);
        return s2rr == s1 || s2lr == s1; 
        
    }
};
