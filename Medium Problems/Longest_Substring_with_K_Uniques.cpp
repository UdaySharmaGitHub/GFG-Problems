/*
Longest Substring with K Uniques
You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.
Note : If no such substring exists, return -1. 
Examples:
Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.
Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.
Constraints:
1 ≤ s.size() ≤ 105
1 ≤ k ≤ 26
*/
/*
Using Sliding window
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char,int> map;
        for(char ch:s) map[ch]++;
        if(map.size()<k) return -1;
        map.clear();
        int i =0 , j =0  ,res= 0;
        while(j<s.size()){
            map[s[j]]++;
            while(map.size()>k){
                map[s[i]]--;
                if(map[s[i]] == 0) map.erase(s[i]);
                i++;
            }
            res = max(res , j - i +1);
            j++;
        }
        return res;
    }
};