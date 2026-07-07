/*
Max Gap Between Two Same
Given a string s consisting of lowercase English letters, find the maximum number of characters between any two identical characters. If no character repeats, return -1.
Examples :
Input: s = "socks"
Output: 3
Explanation: There are 3 characters between the two occurrences of 's'.
Input: s = "for"
Output: -1
Explanation: No repeating character present.
Constraints:
1 ≤ |s| ≤ 105
*/
class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        int maxa = 0 ;
        vector<int> freq(26,-1);
        for(int i =0;i<s.size();i++){
            if(freq[s[i]-'a']>=0) maxa = max(maxa,abs(i- (freq[s[i]-'a'])));
            else freq[s[i]-'a']=i;
        }
        return maxa-1;
    }
};