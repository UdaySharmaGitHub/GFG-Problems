/*
Cutting Binary String
You are given a binary string s consisting only of characters '0' and '1'. Your task is to split this string into the minimum number of non-empty substrings such that:
Each substring represents a power of 5 in decimal (e.g., 1, 5, 25, 125, ...).
No substring should have leading zeros.
Return the minimum number of such pieces the string can be divided into.
Note: If it is not possible to split the string in this way, return -1.
Examples:
Input: s = "101101101"
Output: 3
Explanation: The string can be split into three substrings: "101", "101", and "101", each of which is a power of 5 with no leading zeros.
Input: s = "1111101"
Output: 1
Explanation: The string can be split into one binary string "1111101" which is 125 in decimal and a power of 5 with no leading zeros.
Input: s = "00000"
Output: -1
Explanation: There is no substring that can be split into power of 5.
Constraints:
1 ≤ s.size() ≤ 30
*/
class Solution {
  public:
    int cuts(string s) {
        // code here
         if (s[0] == '0') return -1;
    int n = s.size();

    const int maxi = n+1;
    unordered_set<int> powersOf5;

    // store power of 5
    int val = 1;
    while (val <= 1e9) {
        powersOf5.insert(val);
        val *= 5;
    }
    
    vector<int> dp(n + 1, maxi);
    
    // base case empty suffix requires 0 cuts
    dp[n] = 0; 

    for (int i = n - 1; i >= 0; --i) {
        
        // ensure there is no leading '0'
        if(s[i] == '0') continue;
        
        int num = 0;
        for (int j = i; j < n; ++j) {
            num = num * 2 + (s[j] == '1');

            // and the number is a power of 5
            if (powersOf5.count(num)) {
                if (dp[j + 1] != maxi) {
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
                }
            }
        }
    }

    return dp[0] >= maxi ? -1 : dp[0];
    }
};