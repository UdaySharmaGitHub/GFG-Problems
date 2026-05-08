/*
Remove Invalid Parentheses
Given a string s consisting of lowercase letters and parentheses '(' and ')'.

A string is considered valid if:

Every opening parenthesis '(' has a corresponding closing parenthesis ')'.
Parentheses are properly nested.
Remove the minimum number of invalid parentheses from s so that the resulting string becomes valid.  Return all the possible distinct valid strings in lexicographically sorted order.

Examples :

Input:  = "()())()"
Output: ["(())()", "()()()"]
Explanation: 
The string "()())()" has one extra ')', making it invalid. By removing one ')', we can make it valid in two ways:
Remove the 3rd index ')' -> "(())()"
Remove the 4th index ')' -> "()()()"
Both are valid and require the minimum removals.
Input: s = "(a)())()"
Output: ["(a())()", "(a)()()"]
Explanation: 
We remove one ')' (minimum removals) to make it valid. Possible valid results:
Remove a ')' -> "(a())()"
Remove another ')' -> "(a)()()"
Input: s = ")("
Output: [""]
Explanation: The string ")(" is invalid. Removing both parentheses (minimum removals) gives an empty string "", which is valid.
Constraints:
1 ≤ |s| ≤ 20
s consists of lowercase English letters and parentheses '(' and ')'
*/
class Solution {
  public:
   unordered_set<string> mp;
bool isvalid(string &s){

    int cnt = 0;

    for(char ch : s){

        if(ch == '('){

            cnt++;
        }
        else if(ch == ')'){

            if(cnt == 0)
                return false;

            cnt--;
        }
    }

    return cnt == 0;
}
   
      void fun( int i , string& s , string temp , int c1 , int c2){
          int n = s.size();
          if( i>= n){
              if(c1 >0 || c2 >0) return ;
              if(isvalid(temp)){
                   mp.insert(temp);
              }
               return ;
          }
          
           if(c1!=0 && s[i]=='('){
                fun( i+1 , s , temp , c1-1, c2);
           }
            if( c2 !=0  && s[i]==')'){
                fun( i+1 , s , temp , c1 , c2-1);
            }
             fun( i+1 , s , temp + s[i] , c1 , c2);
      }
  
  
    vector<string> validParenthesis(string &s) {
        // code here
        
        vector<string>ans;
        if(isvalid(s)){
             return {s};
        }
         int n = s.size();
        stack<char> st;
 
        
        int c1 = 0, c2 = 0;

for(char ch : s){

    if(ch == '('){
        c1++;
    }
    else if(ch == ')'){

        if(c1 > 0)
            c1--;
        else
            c2++;
    }
}

if(c1==0 && c2==0){
     return {s};
}
           fun( 0 , s, "" , c1 , c2);
           for(auto it : mp){
                ans.push_back(it);
           }
        sort(ans.begin() , ans.end());
         return ans ;
    }
};