/*
Choose and Swap
Given a string s of lowercase English letters, you can swap all occurrences of any two distinct characters at most once. Return the lexicographically smallest string after this operation.
Examples:

Input: s = "ccad"
Output: "aacd"
Explanation: In ccad, we choose a and c and after doing the replacement operation once, we get aacd and this is the lexicographically smallest string possible. 
Input: s = "abba"
Output: "abba"
Explanation: In abba, we can get baab after doing the replacement operation once for a and b but that is not lexicographically smaller than abba. So, the answer is abba. 
Constraints:
1 ≤ |s| ≤ 105
*/
class Solution {
  public:
    string chooseSwap(string &s) {
        int n = s.size();

        vector<int> first(26, -1);

        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
        }

        for (int i = 0; i < n; i++) {

            for (int ch = 0; ch < (s[i] - 'a'); ch++) {

                if (first[ch] > i) {

                    char c1 = s[i];
                    char c2 = char(ch + 'a');

                    for (int j = 0; j < n; j++) {
                        if (s[j] == c1)
                            s[j] = c2;
                        else if (s[j] == c2)
                            s[j] = c1;
                    }

                    return s;
                }
            }
        }

        return s;
    }
};