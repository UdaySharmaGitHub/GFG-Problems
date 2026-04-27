/*
Smallest window containing 0, 1 and 2
Given a string s consisting only of the characters '0', '1' and '2', determine the length of the smallest substring that contains all three characters at least once.
If no such substring exists, return -1.
Examples :
Input: s = "10212"
Output: 3
Explanation: The substring "102" is the shortest substring that contains all three characters '0', '1', and '2', so the answer is 3.
Input: s = "12121"
Output: -1
Explanation: The character '0' is not present in the string, so no substring can contain all three characters '0', '1', and '2'. Hence, the answer is -1.
Constraints:
1 ≤ s.size() ≤ 105
*/
class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
           int n = s.size();
         int ans = 1e9;
         int i =0, j =0;
         unordered_map<char , int> mp;
          while(j<n){
              mp[s[j]]++;
               if( mp.size()==3){
ans = min( ans , j-i+1);
while(i<j && mp.size()==3){
                         mp[s[i]]--;
                          if(mp[s[i]]==0) {
                               mp.erase(s[i]);
                          
                          }
                           i++;
                           if( mp.size()==3){
                                ans = min( ans , j-i+1);
                           }
                           else break;
                     }
               }
               j++;
          }
          if( ans == 1e9) return -1;
           return ans ;
    }
};
