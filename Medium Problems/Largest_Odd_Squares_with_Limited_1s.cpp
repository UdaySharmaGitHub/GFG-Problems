/*
Largest Odd Squares with Limited 1s
Given a binary matrix mat[][] of size n*m and an integer k, process a list of queries queries[][]. Each query contains coordinates [i, j] of the center of a square.

For every query, find the side length of the largest odd-sized square centered at cell (i, j) such that the square contains at most k ones.
 A square centered at (i, j) expands outward symmetrically in all four directions by the same number of cells, so its side length is always odd.
Note: If no odd-sized square centered at the given cell satisfies the condition of containing at most k ones, return -1 for that query.

Examples:

Input: mat[][] = [[1, 0, 1, 0, 0], [1, 0, 1, 1, 1], [1, 1, 1, 1, 1], [1, 0, 0, 1, 0]], queries[][] = [[1, 2]], k = 9
Output: [3]
Explanation: The largest odd-sized square centered at (1, 2) is the 3 × 3 square spanning rows 0 to 2 and columns 1 to 3. 
It contains 6 ones, which is at most k = 9. Hence, the answer is 3.
Input: mat[][] = [[1, 1, 1], [1, 1, 1], [1, 1, 1]], queries[][] = [[1, 1], [2, 2]], K = 9
Output: [3, 1]
Explanation: For query (1, 1), the largest valid square is the entire 3 × 3 matrix, which contains 9 ones. Hence, the answer is 3.
For query (2, 2), no expansion is possible without going outside the matrix, so only the 1 × 1 square centered at (2, 2) is valid. Hence, the answer is 1.
Constraints:
1 ≤ mat.size(), mat[0].size() ≤ 500
1 ≤ queries.size() ≤ 104
0 ≤ queries[q][0] < mat.size()
0 ≤ queries[q][1] < mat[0].size()
0 ≤ k ≤ mat.size() * mat[0].size()
*/
class Solution {
  public:
   int n;
   int m;
   bool check(int i,int j){
       return i>=0 && j>=0 && i<n && j<m;
   }
    
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries,int p) {
        // code here
        n = mat.size();
        m = mat[0].size();
        int q = queries.size();
        vector<int>temp;
        vector<vector<int>>sum(n+1,vector<int>(m+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                sum[i][j] = mat[i][j]+sum[i][j+1]+sum[i+1][j]-sum[i+1][j+1];
            }
        }
        
        for(int k=0;k<q;k++){
            
            int i = queries[k][0];
            int j = queries[k][1];
            
            int r = min({i,n-i-1,j,m-j-1});
            int l = 0;
            int ans = -1;
            
            while(l<=r){
                
                int mid = l+((r-l)/2);
                int i1 = i-mid;
                int j1 = j-mid;
                
                int count = sum[i1][j1] - ((check(i+mid+1,j1))?sum[i+mid+1][j1]:0) - ((check(i-mid,j+mid+1))?sum[i-mid][j+mid+1]:0) + ((check(i+mid+1,j+mid+1))?sum[i+mid+1][j+mid+1]:0);
                
                if(count<=p){
                    
                    ans = (2*mid)+1;
                    l = mid+1;
                }
                else r = mid-1;
                
            }
            
            temp.push_back(ans);
            
        }
        
        return temp;
        
    }
};