/*
Largest Rectangle with Column Swaps
Given a binary matrix mat[][] of size n × m containing only 0s and 1s, any pair of columns may be swapped any number of times. Return the maximum area of a rectangle consisting entirely of 1's that can be formed after performing the column swaps.
Examples:
Input: mat[][] = [[0, 1, 0, 1, 0], [0, 1, 0, 1, 1], [1, 1, 0, 1, 0]]
Output: 6
Explanation: After swapping the 2nd and 3rd columns, the largest rectangle of 1s has an area of 6.
Input: mat[][] = [[0, 1, 1, 0, 0], [1, 1, 1, 0, 1], [1, 1, 1, 0, 1], [1, 1, 1, 1, 1]]
Output: 12
Explanation: After swapping the 4th and 5th columns, the largest rectangle of 1s has an area of 12.
Constraints:
1 ≤ n, m ≤ 103
0 ≤ mat[i][j] ≤ 1
mat.rows = n
mat.cols = m
*/
class Solution {
    public:
      int maxArea(vector<vector<int>>& mat) {
          // code here

          int n = mat.size();
          int m = mat[0].size();
          vector<int> heights(m, 0);
          int ans = 0;

          for (int i = 0; i < n; i++) {

              for (int j = 0; j < m; j++) {

                  if (mat[i][j] == 1) {
                      heights[j]++;
                  } else {
                      heights[j] = 0;
                  }
              }


              vector<int> sortedH = heights;
              sort(begin(sortedH), end(sortedH), greater<int>());

              for (int j = 0; j < m; j++) {

                  int w = sortedH[j];
                  int h = j+1;

                  ans = max(ans, w * h);
              }
          }

          return ans;
      }
  };