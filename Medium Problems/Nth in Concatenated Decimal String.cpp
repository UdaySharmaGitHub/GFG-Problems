/*
Nth in Concatenated Decimal String
Consider a string s formed by concatenating the decimal representations of all positive integers in order:

s = "12345678910111213141516171819202122232425262728293031..."

Given an integer n, find the nth character (1-based indexing) in the string s.

Examples:

Input: n = 10
Output: '1'
Explanation: The 10th in "1234567891.." character is '1'.
Input: n = 11
Output: '0'
Explanation: The 11th character in "12345678910.."  is '0'.
Constraints:
1 ≤ n ≤ 109
*/
class Solution {
  public:
     char nthCharacter(int n) {
         vector<long long> digit(11, 0);
         vector<long long> power(11, -1);

         long long prev = 1;
         long long curr = 10;
         int count = 1;

         for (int i = 1; i <= 10; i++) {
             digit[i] = (curr - prev) * count + digit[i - 1];
             power[i] = prev;
             prev = curr;
             curr *= 10;
             count++;
         }

         long long l = 1;
         long long r = n;

         while (l <= r) {
             long long mid = l + (r - l) / 2;
             string t = to_string(mid);
             int m = t.size();

             long long cnt = (mid - power[m] + 1) * m + digit[m - 1];

             if (cnt >= n) {
                 r = mid - 1;
             } else {
                 l = mid + 1;
             }
         }

         string y = to_string(l);
         int u = y.size();

         long long j = n - ((l - power[u]) * u + digit[u - 1]) - 1;

         return y[j];
     }
};