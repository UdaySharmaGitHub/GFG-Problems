/*
Count Numbers Containing Specific Digits
You are given an integer n representing the number of digits in a number, and an array arr[] containing digits from 0 to 9. Your have to count how many n-digit positive integers can be formed such that at least one digit from the array arr[] appears in the number.
Examples:
Input: n = 1, arr[] = [1, 2, 3]
Output: 3
Explanation: Only the single-digit numbers [1, 2, 3] satisfy the condition.
Input: n = 2, arr[] = [3, 5]
Output: 34
Explanation: There are a total of 34  two digit numbers which contain atleast  one out of  [3, 5].
Constraints:
  1 ≤ n ≤ 9
  1 ≤ arr.size() ≤ 10
  0 ≤ arr[i] ≤ 9
*/
class Solution {
  public:
    int fastPow(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}

int countValid(int n, vector<int> &arr) {

    // mark which digits are “good”
    bool good[10] = {};
    for (int d : arr) good[d] = true;

    // count forbidden digits overall (f) 
    // and for the first position (f0)
    int f = 0, f0 = 0;
    for (int d = 0; d < 10; d++) {
        if (!good[d]) {
            f++;
            if (d != 0) f0++;
        }
    }

    // total n-digit numbers = 9 * 10^(n-1)
    int total = 9 * fastPow(10, n - 1);
    
    // numbers with no good digit = f0 * f^(n-1)
    int noneAllowed = (n == 1 ? f0 : f0 * fastPow(f, n - 1));

    // valid = total − noneAllowed
    return total - noneAllowed;
}

};
