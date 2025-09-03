/*
Smallest window containing all characters
Given two strings s and p. Find the smallest substring in s consisting of all the characters (including duplicates) of the string p. Return empty string in case no such substring is present.
If there are multiple such substring of the same length found, return the one with the least starting index.

Examples:

Input: s = "timetopractice", p = "toc"
Output: "toprac"
Explanation: "toprac" is the smallest substring in which "toc" can be found.
Input: s = "zoomlazapzo", p = "oza"
Output: "apzo"
Explanation: "apzo" is the smallest substring in which "oza" can be found.
Input: s = "zoom", p = "zooe"
Output: ""
Explanation: No substring is present containing all characters of p.
Constraints: 
1 ≤ s.length(), p.length() ≤ 106
s, p consists of lowercase english letters
*/
class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        // code here
        vector<int> freqs(26,0);
        vector<int> freqp(26,0);
        int unique=0;
        for(auto it:p){
            if(freqp[it-'a']==0)unique++;
            freqp[it-'a']++;
        }
        int start=0,end=0,minlen=INT_MAX,match=0;
        string ans="";
        while(end<s.size()){
            freqs[s[end]-'a']++;
            if(freqs[s[end]-'a']==freqp[s[end]-'a'] 
                && freqp[s[end]-'a'] >0 )match++;
            if(match>=unique){
                while(start<=end && 
                      freqs[s[start]-'a']>freqp[s[start]-'a']){
                      freqs[s[start]-'a']--;   
                      start++;
                }
                int len=end-start+1;
                if(len<minlen){
                    minlen=len;
                    ans=s.substr(start,len);
                }
            }
            end++;
        }
        return ans; 
    }
};