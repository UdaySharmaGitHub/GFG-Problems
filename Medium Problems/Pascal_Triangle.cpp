/*
Pascal Triangle

Given a positive integer n, return the nth row of pascal's triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.

Example:
      1
    1   1
  1   2   1
1   3   3   1

Examples:

Input: n = 4
Output: [1, 3, 3, 1]
Explanation: 4th row of pascal's triangle is [1, 3, 3, 1].
Input: n = 5
Output: [1, 4, 6, 4, 1]
Explanation: 5th row of pascal's triangle is [1, 4, 6, 4, 1].
Input: n = 1
Output: [1]
Explanation: 1st row of pascal's triangle is [1].
Constraints:
1 ≤ n ≤ 20
*/
class Solution {
    public:
      vector<int> nthRowOfPascalTriangle(int n) {
          // code here
          vector<int> res;
          int coef =1;
          for(int i =0;i<n;i++){
              if( i ==0 || i == n-1) coef = 1;
              else coef = coef *(n-i)/i;
              res.push_back(coef);
              
          }
          return res;
      }
  };