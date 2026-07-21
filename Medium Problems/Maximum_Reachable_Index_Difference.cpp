/*
Maximum Reachable Index Difference
Given a string s containing lowercase English alphabets.

Start from any index containing the character 'a' and perform jump operations.
In each jump operation, move to any index on the right side whose character is the immediate next letter of the current character in the alphabet (i.e., 'a' to 'b', 'b' to 'c', 'c' to 'd', and so on). 
Continue performing jumps until no further jump is possible.
Find the maximum possible difference between the starting index and the ending index. If it is not possible to choose a starting index, return -1.

Examples :

Input: s = "aaabcb"
Output: 5
Explanation: Start at index 0 ('a'), jump to index 5 ('b'). Difference = 5 - 0 = 5.
Input: s = "xynjir"
Output: -1
Explanation: The string does not contain any character 'a'. So, the answer is -1.
Input: s = "abcbzzd"
Output: 6
Explanation: Start from index 0 ('a'). Jump to index 1 ('b') because 'b' is the next alphabet character. Jump to index 2 ('c') because 'c' is the next character after 'b'. Jump to index 6 ('d') because 'd' is the next character after 'c'.
Constraints:
1 ≤ s.size() ≤ 105
*/
class Solution {
  public:
     int maxIndexDifference(string &s) {
        int ans = -1 , start = -1;
        bool vis[26] = {false};
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                if(vis[s[i] - 'a'])
                    continue;
                ans = 0 , start = i;
                vis[s[i] - 'a'] = true;
            }else{
                char prev = char((s[i] - 'a') + 96);
                if(vis[s[i] - 'a'] || vis[prev - 'a'])
                    ans = max(ans , i - start) , vis[s[i] - 'a'] = true;
            }
        }
        return ans;
    }
};
