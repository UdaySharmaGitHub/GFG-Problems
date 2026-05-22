/*
1s Surrounded by 0s

Given an n × m binary matrix grid[][], find the total count of all cells containing 1 that are unable to move out of the grid through a path of adjacent 1s.

Adjacency means you can only move in four directions: Up, Down, Left, and Right. Diagonal moves are not allowed.
Assume that the space immediately outside the grid is an open path. Any 1 located directly on the outer boundary of the grid (first row, last row, first column, or last column) can immediately step out, and any 1 connected to it can follow and also step out of the grid.
Examples:

Input: grid[][] = [[0, 0, 0, 0],
		[1, 0, 1, 0],
		[0, 1, 1, 0],
		[0, 0, 0, 0]]
Output: 3
Explanation: The highlighted cells represent the land cells.
 
Input: grid[][] = [[1, 1, 0, 0, 0, 1]
		[0, 1, 1, 0, 1, 0],
		[0, 0, 0, 1, 1, 0],
		[0, 0, 0, 1, 1, 0],
		[0, 1, 0, 1, 0, 0],
		[1, 1, 0, 0, 0, 1]]
Output: 6
Explanation: The highlighted cells represent the land cells.
425537429
Constraints:
1 ≤ n, m ≤ 500
0 ≤ grid[i][j] ≤ 1
*/
class Solution {
  public:
    void dfs(int i, int j, vector<vector<int>>& arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        
        if(i < 0 || j < 0 || i >= n || j >= m || arr[i][j] == 0)
        {
            return;
        }
        
        arr[i][j] = 0;
        
        dfs(i+1, j, arr);
        dfs(i-1, j, arr);
        dfs(i, j+1, arr);
        dfs(i, j-1, arr);
    }
    
    int cntOnes(vector<vector<int>>& arr) 
    {
        int n = arr.size();
        int m = arr[0].size();
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i][0] == 1)
            {
                dfs(i, 0, arr);
            }
            
            if(arr[i][m-1] == 1)
            {
                dfs(i, m-1, arr);
            }
        }
        
        for(int j = 0; j < m; j++)
        {
            if(arr[0][j] == 1)
            {
                dfs(0, j, arr);
            }
            
            if(arr[n-1][j] == 1)
            {
                dfs(n-1, j, arr);
            }
        }
        
        int c = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j] == 1)
                {
                    c += 1;
                }
            }
        }
        
        return c;
    }
};