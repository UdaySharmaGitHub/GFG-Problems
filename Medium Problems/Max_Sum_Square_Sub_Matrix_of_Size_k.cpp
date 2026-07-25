/*
Max Sum Square Sub-Matrix of Size k
Given a n × n grid mat[][] of integers where values can be negative, find the maximum sum among all possible k × k sub-grids.
Examples:
Input: k = 3, mat[][] = [[1, 2, -1, 4], [-8, -3, 4, 2], [3, 8, 10, -8], [-4, -1, 1, 7]]
Output: 20
Explanation: The 3 × 3 sub-grid [[-3, 4, 2], [8, 10, -8], [-1, 1, 7]] highlighted in red has the maximum sum of 20. 
Input: k = 1, mat[][] = [[4]]
Output: 4
Explanation: Only one 1×1 sub-grid exists with sum 4.
Constraints:
1 ≤ n ≤ 1000
1 ≤ k ≤ n
-1000 ≤ mat[i][j] ≤ 1000
*/
/*
    Appraoch:- [Expected Approach] Using Sliding Window - O(n^2) Time and O(n) Space
    Steps:
    1. **Initialize Memory:**
        Create a 1D array (`colSum`) of size $n$ initialized to 0, and a result variable (`res`) set to the smallest possible integer.
    2. **Start the Row-by-Row Scan:**
        Begin moving down the matrix one row at a time using an outer loop (index `i`). This row acts as the bottom edge of your sliding band.
    3. **Add the New Row:**
        For every element in the current row, add its value to the corresponding column sum in the `colSum` array.
    4. **Remove the Old Row:**
        If you have moved past the $k$-th row (`i >= k`), subtract the values of the row that just left the top of your vertical window (`i - k`). Your `colSum` array now perfectly represents a horizontal band of height $k$.
    5. **Check for Minimum Height:**
        Before calculating horizontal squares, check if you have accumulated at least $k$ rows (`i >= k - 1`). If not, move to the next row.
    6. **Slide Horizontally:**
        If the vertical band is exactly height $k$, initialize a `windowSum` to 0 and begin scanning left-to-right across the `colSum` array (index `j`).
    7. **Maintain Window Width:**
        Add the current column's sum (`colSum[j]`) to `windowSum`. If your horizontal window grows wider than $k$ columns (`j >= k`), subtract the column sum that just fell off the left edge (`colSum[j - k]`).

    8. **Record the Maximum:**
    Once your horizontal window is exactly $k$ columns wide (`j >= k - 1`), you have found the sum of a valid $k \times k$ submatrix. Update `res` if this `windowSum` is the largest one you have seen so far.
    
    Time Complexity: O(n^2) for iterating through all rows and columns, resulting in an overall time complexity of O(n^2).
    Space Complexity: O(n) for the
*/
class Solution {
  public:
    int maximumSum(vector<vector<int>> &mat, int k)
{
    int n = mat.size();

    // 1D column sum array — O(n) space
    vector<int> colSum(n, 0);
    int res = INT_MIN;

    for (int i = 0; i < n; i++)
    {

        // Update column sums with new row entering and old row leaving window
        for (int j = 0; j < n; j++)
        {
            colSum[j] += mat[i][j];
            if (i >= k)
                colSum[j] -= mat[i - k][j];
        }

        // Slide horizontal window of size k over colSum
        if (i >= k - 1)
        {
            int windowSum = 0;
            for (int j = 0; j < n; j++)
            {
                windowSum += colSum[j];
                if (j >= k)
                    windowSum -= colSum[j - k];
                if (j >= k - 1)
                    res = max(res, windowSum);
            }
        }
    }
    return res;
}
};

/*
    Approach:- [Better Approach] Using 2D Prefix Sum - O(n^2) Time and O(n^2) Space
    Steps:
    1. Create a 2D prefix sum array of size (n+1) x (n+1) and initialize it with 0.
    2. Fill the prefix sum array such that prefix[i][j] contains the sum of elements from mat[0][0] to mat[i-1][j-1].
    3. Iterate through all possible k x k sub-matrices using two nested loops. For each sub-matrix, calculate its sum using the prefix sum array.
    4. Keep track of the maximum sum encountered during the iterations.

    Time Complexity: O(n^2) for creating the prefix sum array and O(n^2) for iterating through all possible k x k sub-matrices, resulting in an overall time complexity of O(n^2).
    Space Complexity: O(n^2) for the prefix sum array.
*/
class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        // code here
        int n = mat.size();
     vector<vector<int>> prefix(n+1,vector<int>(n+1,0));
     for(int i =1;i<=n;i++){
         for(int j =1;j<=n;j++)
         prefix[i][j] = mat[i-1][j-1]+prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
    }
    int maxa = 0;
    for(int i =k;i<=n;i++){for(int j =k;j<=n;j++){
     maxa = max(maxa,(prefix[i][j] + prefix[i-k][j-k] -prefix[i-k][j] - prefix[i][j-k]));   
    }
    }
    return maxa;
    }
};