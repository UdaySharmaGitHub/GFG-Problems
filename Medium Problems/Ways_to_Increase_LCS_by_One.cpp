/*
Ways to Increase LCS by One
Given two strings s1 and s2 consisting of lowercase English letters of length n1 and n2 respectively, find the number of ways to insert exactly one character into string s1 such that the length of the Longest Common Subsequence (LCS) of both strings increases by exactly 1.

Examples :

Input: s1 = "abab", s2 = "abc"
Output: 3
Explanation: The LCS length of the given two strings is 2. There are 3 valid insertions in s1 which increase the LCS length to 3:
"abcab" -> LCS = 3
"abacb" -> LCS = 3
"ababc" -> LCS = 3
Input: s1 = "abcabc", s2 = "abcd"
Output: 4
Explanation: The LCS length of the given two strings is 3. There are 4 valid insertions in s1 which increase the LCS length to 4:
"abcdabc" -> LCS = 4
"abcadcb" -> LCS = 4
"abcabdc" -> LCS = 4
"abcabcd" -> LCS = 4
Constraints:
1<= n1, n2 <=100
*/
class Solution {
  public:
     int waysToIncreaseLCSBy1(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();

        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    pref[i][j] = pref[i - 1][j - 1] + 1;
                else
                    pref[i][j] = max(pref[i - 1][j], pref[i][j - 1]);
            }
        }

        int lcs = pref[n][m];

        vector<vector<int>> suff(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j])
                    suff[i][j] = suff[i + 1][j + 1] + 1;
                else
                    suff[i][j] = max(suff[i + 1][j], suff[i][j + 1]);
            }
        }

        int ans = 0;

        for (int pos = 0; pos <= n; pos++) {

            for (char ch = 'a'; ch <= 'z'; ch++) {

                bool ok = false;

                for (int j = 0; j < m && !ok; j++) {

                    if (s2[j] != ch)
                        continue;

                    if (pref[pos][j] + 1 + suff[pos][j + 1] == lcs + 1)
                        ok = true;
                }

                if (ok)
                    ans++;
            }
        }

        return ans;
    }
};
