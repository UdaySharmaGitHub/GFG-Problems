/*
Largest Zigzag Sequence
Given a square matrix mat[][] of size n × n. A zigzag sequence starts from the top and ends at the bottom. Two consecutive elements of sequence cannot belong to the same column.
Return the maximum sum of such a zigzag sequence.
Examples

Input: mat[][] = [[3, 1, 2], [4, 8, 5], [6, 9, 7]]
Output: 18
Explanation:
One optimal zigzag sequence is: 3 -> 8 -> 7, where the sum = 3 + 8 + 7 = 18.
Input: mat[][] = [[1, 2, 4], [3, 9, 6], [11, 3, 15]]
Output: 28
Explanation:
One optimal zigzag sequence is: 4 -> 9 -> 15, where the sum = 4 + 9 + 15 = 28.
Constraints:
1 ≤ n ≤ 100
1 ≤ mat[i][j] ≤ 1000 
*/
class Solution {
  public:
    int zigzagSequence(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();

    // DP values for the previous row
    vector<int> prev = mat[0];

    for (int i = 1; i < n; i++)
    {
        int max1 = -1, max2 = -1, maxCol = -1;

        // Find the maximum and second maximum
        // values from the previous row
        for (int j = 0; j < n; j++)
        {
            if (prev[j] > max1)
            {
                max2 = max1;
                max1 = prev[j];
                maxCol = j;
            }
            else if (prev[j] > max2)
            {
                max2 = prev[j];
            }
        }

        vector<int> curr(n);

        for (int j = 0; j < n; j++)
        {

            // Use second maximum if the current column
            // is the same as the column of the maximum value
            curr[j] = mat[i][j] + (j == maxCol ? max2 : max1);
        }

        // Move to the next row.
        prev = curr;
    }

    // Find the maximum zigzag sum
    int res = 0;
    for (int x : prev)
    {
        res = max(res, x);
    }

    return res;
    }
};