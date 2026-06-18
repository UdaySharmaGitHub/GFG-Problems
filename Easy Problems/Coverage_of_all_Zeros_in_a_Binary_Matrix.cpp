/*
Coverage of all Zeros in a Binary Matrix
Given a binary matrix contains 0s and 1s only, we need to find the sum of coverage of all zeros of the matrix where coverage for a particular 0 is defined as a total number of ones around a zero in left, right, up and bottom directions.

Examples:

Input:
matrix = [[0, 1, 0],
          [0, 1, 1],
          [0, 0, 0]]
Output: 6
Explanation: There are a total of 6 coverage are there

Input: 
matrix = [[0, 1]]
Output: 1
Explanation: There are only 1 coverage.
Expected Time Complexity: O(n * m)
Expected Space Complexity: O(1)

Constraints:
1 <= matrix.size, matrix[0].size <= 100
*/

/*
    APPROACH
    Steps:
    1. We will iterate through the matrix and for each 0 we encounter, we will check its left, right, up and down neighbors to see if they are 1s. If they are, we will increment our total coverage count.
    2. Finally, we will return the total coverage count.

    Time Complexity: O(n * m) where n is the number of rows and m is the number of columns in the matrix.
    Space Complexity: O(1) as we are not using any extra space.

*/
class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), total = 0;
        vector<bool> up(n, false), left(m, false),
        right(m, false), down(n, false);
        
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[i].size(); j++) {
                if(mat[i][j] == 0) {
                    if(left[i]) total++;
                    if(up[j]) total++;
                }
                if(mat[i][j] == 1) {
                    left[i] = true;
                    up[j]   = true;
                }
                if(mat[m-i-1][n-j-1] == 0) {
                    if(right[m-i-1]) total++;
                    if(down[n-j-1]) total++;
                }
                if(mat[m-i-1][n-j-1] == 1) {
                    right[m-i-1] = true;
                    down[n-j-1] = true;
                }
            }
        } return total;
    }
};

/*
    APPROACH
    Steps:
    1. We will maintain 4 boolean arrays to keep track of whether we have seen a 1 in the left, right, up and down direction for each row and column.   
    2. We will iterate through the matrix from top-left to bottom-right and for each 0 we encounter, we will check if there is a 1 in the left and up direction using the left and up boolean arrays. If there is, we will increment our total coverage count.
    3. We will also iterate through the matrix from bottom-right to top-left and for each 0 we encounter, we will check if there is a 1 in the right and down direction using the right and down boolean arrays. If there is, we will increment our total coverage count.
    4. Finally, we will return the total coverage count.    

    Time Complexity: O(n * m) where n is the number of rows and m is the number of columns in the matrix.
    Space Complexity: O(n + m) for the boolean arrays used to keep track of the
*/


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int ans =0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    continue;
                }
                if(i-1>=0 and matrix[i-1][j]==1)
                ans++;
                if(i+1<n and matrix[i+1][j]==1)
                ans++;
                if(j-1>=0 and matrix[i][j-1]==1)
                ans++;
                if(j+1<m and matrix[i][j+1]==1)
                ans++;
            }
        }
        return ans;
        
    }
};