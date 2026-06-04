/*
Substring with Max Zero-One Diff
Given a binary string s consisting of 0s and 1s. Find the maximum difference of the number of 0s and the number of 1s (number of 0s – number of 1s) in a substring of the string.

Note: In the case of all 1s, the answer will be -1.

Examples:

Input : s = "11000010001" 
Output : 6 
Explanatio: From index 2 to index 9, there are 7 0s and 1 1s, so number of 0s - number of 1s is 6. 
Input: s = "111111"
Output: -1
Explanation: s contains 1s only 
Constraints:
1 ≤ s.size() ≤ 105
*/
class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int n = s.size();
        int zero = 0;
        int ans = -1;
        
        for(int i=0;i<n;i++){
            
            if(s[i]=='1')zero--;
            else zero++;
            
            if(zero<=0)zero=0;
            else ans = max(ans,zero);
            
        }
        
        return ans;
    }
};