/*
Transform String
Given two strings s1 and s2. Find the minimum number of steps required to transform string s1 into string s2. The only allowed operation for the transformation is selecting a character from string s1 and inserting it in the beginning of string s1.
If transformation is not possible return -1.
Examples:
Input: s1 = "abd", s2 = "bad"
Output: 1
Explanation: The conversion can take place in 1 operation: Pick 'b' and place it at the front.
Input: s1 = "GeeksForGeeks", s2 = "ForGeeksGeeks"
Output: 3
Explanation: The conversion can take place in 3 operations: 
Pick 'r' and place it at the front.
s1 = "rGeeksFoGeeks"
Pick 'o' and place it at the front.
s1 = "orGeeksFGeeks"
Pick 'F' and place it at the front.
s1 = "ForGeeksGeeks"
Constraints:
1<= s1.length(), s2.length() <= 104
*/
class Solution {
  public:
    int transform(string &s1, string &s2) {
        int n = s1.size();

        if (n != (int)s2.size()) {
            return -1;
        }

        int freq[256] = {0};

        for (int i = 0; i < n; i++) {
            freq[(unsigned char)s1[i]]++;
            freq[(unsigned char)s2[i]]--;
        }

        for (int i = 0; i < 256; i++) {
            if (freq[i] != 0) {
                return -1;
            }
        }

        int i = n - 1;
        int j = n - 1;
        int operations = 0;

        while (i >= 0 && j >= 0) {
            if (s1[i] == s2[j]) {
                i--;
                j--;
            } else {
                operations++;
                i--;
            }
        }

        return operations;
    }
};
