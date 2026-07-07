/*
N-Digit Numbers with Increasing Digits
Given an integer n, return all the n digit numbers in increasing order, such that their digits are in strictly increasing order(from left to right).

Examples :

Input: n = 1
Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
Explanation: Single digit numbers are considered to be strictly increasing order.
Input: n = 2
Output: [12, 13, 14, 15, 16, 17, 18, 19, 23....79, 89]
Explanation: For n = 2, the correct sequence is 12 13 14 15 16 17 18 19 23 and so on up to 89.
Input: n = 15
Output: []
Explanation: No such number exist. 
Constraints:
1 ≤ n ≤ 105
*/
class Solution {
  public:
    void solve(int digit, int n, string current, vector<int>& result) {
        if (current.length() == n) {
            result.push_back(stoi(current));
            return;
        }
        for (int i = digit; i <= 9; ++i) {
            solve(i + 1, n, current + to_string(i), result);
        }
    }
    vector<int> increasingNumbers(int n) {
        vector<int> result;
        if (n == 1) {
            result.push_back(0);
        }
        for (int i = 1; i <= 9; ++i) {
            solve(i + 1, n, to_string(i), result);
        }
        return result;
    }
};