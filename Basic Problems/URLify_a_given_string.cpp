/*
URLify a given string
Given a string s, replace all the spaces in the string with '%20'.

Examples:

Input: s = "i love programming"
Output: "i%20love%20programming"
Explanation: The 2 spaces are replaced by '%20'
Input: s = "Mr Benedict Cumberbatch"
Output: "Mr%20Benedict%20Cumberbatch"
Explanation: The 2 spaces are replaced by '%20'
Constraints:
1 ≤ s.size() ≤ 104
*/
/*
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
class Solution {
  public:
    string URLify(string &s) {
        // code here
        for(int i = 0 ; i<s.size();i++){
            if(s[i] == ' ')s.replace(i,1,"%20");
        }
        return s;
    }
};

/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/
class Solution {
  public:
    string URLify(string &s) {
        // code here
        string res ="" ;
        for(char ch:s){
            if(ch == ' ')res+="%20";
            else res+=ch;
        }
        return res;
    }
};