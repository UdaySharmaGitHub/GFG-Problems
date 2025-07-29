/*
ASCII Range Sum
Given a string s consisting of lowercase English letters, for every character whose first and last occurrences are at different positions, calculate the sum of ASCII values of characters strictly between its first and last occurrence.
Return all such non-zero sums (order does not matter).
Examples:
Input: s = "abacab"
Output: [293, 294]
Explanation: characters 'a' and 'b' appear more than once:
'a' : between positions 1 and 5 → characters are b, a, c and ascii sum is 98 + 97 + 99 = 294.
'b' : between positions 2 and 6 → characters are a, c, a and ascii sum is 97 + 99 + 97 = 293.
Input: s = "acdac"
Output: [197, 199]
Explanation: characters 'a' and 'c' appear more than once:
'a' : between positions 1 and 4 → characters are c, d and ascii sum is 99 + 100 = 199.
'c' : between positions 2 and 5 → characters are d, a and ascii sum is 100 + 97 = 197.
Constraints:
1 ≤ s.size() ≤ 105
*/
class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        if(s.size()<3) return {};
        vector<pair<int,int>> p(26,{-1,-1});
        vector<int> res;
        for(int i =0 ;i<s.size();i++){
            char ch = s[i];
            if(p[ch-'a'].first == -1 && p[ch-'a'].second == -1){ p[ch-'a'].first = i;p[ch-'a'].second = i;}
            else p[ch-'a'].second = i;
        }
        for(int i=0;i<p.size();i++){
            int st = p[i].first , en  = p[i].second ,temp = 0;
            if(st!=en){for(int j=st+1;j<=en-1;j++) temp+=s[j];
           if(temp) res.push_back(temp);}
        }
        return res;
        // return {p[0].first,p[0].second};
    }
};