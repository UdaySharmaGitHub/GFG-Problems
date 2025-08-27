/*
Median in a row-wise sorted Matrix
Given a row-wise sorted matrix mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.
Examples:
Input: mat[][] = [[1, 3, 5], 
                [2, 6, 9], 
                [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.
Input: mat[][] = [[2, 4, 9],
                [3, 6, 7],
                [4, 7, 10]]
Output: 6
Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. Hence, 6 is median.
Input: mat = [[3], [4], [8]]
Output: 4
Explanation: Sorting matrix elements gives us [3, 4, 8]. Hence, 4 is median.
Constraints:
1 ≤ n, m ≤ 400
1 ≤ mat[i][j] ≤ 200
*/
class Solution {
  public:
      int median(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        int count;
        int l=INT_MAX;
        int h=INT_MIN;
        for(int i=0;i<n;i++)
        {
            l=min(l,mat[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            h=max(h,mat[i][m-1]);
        }
        int ans=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            count=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(mat[i][j]<=mid)
                    {
                        count++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if(n*m-count<=count)
            {
                ans=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
