/*
Rat Maze With Multiple Jumps
Given a matrix mat[][] of size n × n, where mat[i][j] represents the maximum number of steps a rat can jump either forward (right) or downward from that cell, find a path for the rat to reach from the top-left cell (0, 0) to the bottom-right cell (n - 1, n - 1). A cell containing 0 is blocked and cannot be used in the path. It is guaranteed that the cell mat[n-1][n-1] is not 0.

Return an n × n matrix where 1 represents the cells included in the path and 0 represents the remaining cells. If no valid path exists, return [[-1]].

Note: If multiple valid paths exist, choose the path with the shortest possible jumps first. For the same jump length, moving forward (right) should be preferred over moving downward.

Example:

Input: mat[][] = [[2, 1, 0, 0], [3, 0, 0, 1], [0, 1, 0, 1], [0, 0, 0, 1]]
Output: [[1, 0, 0, 0], [1, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 1]]
Explanation: 

The rat starts from cell (0, 0) which contains value 2, so it can jump at most 2 steps either right or downward. 
Steps:
-> Moves downward to (1, 0) which contains value 3.
-> Jumps 3 steps right to reach (1, 3).
-> Moves downward through (2, 3) and reaches the destination cell (3, 3).
Input: mat[][] = [[2, 1, 0, 0], [2, 0, 0, 1], [0, 1, 0, 1], [0, 0, 0, 1]]
Output: [[-1]]
Explanation: The rat starts at (0, 0) with value 2, but every possible path from there eventually reaches a cell containing 0. Since no sequence of jumps can reach the destination cell (3, 3), no valid path exists and the output is [[-1]].
Constraints:
1 ≤ n ≤ 50
0 ≤ mat[i][j] ≤ 20
*/
class Solution {
  public:
	vector<vector<int>> dp;
	
	bool withInMatrix(int i, int j, vector<vector<int>> & mat) {
		if (i >= mat.size() || j >= mat[0].size() || mat[i][j] == 0) {
			return false;
		}
		
		return true;
	}
	bool ratmaze(vector<vector<int>> & mat, vector<vector<int>> & ans, int i, int j) {
		if (!withInMatrix(i, j, mat))
			return false;
		
		if (i == mat.size() - 1 && j == mat[0].size() - 1) {
			ans[i][j] = 1;
			return true;
		}
		
		if (dp[i][j] == 0)
			return false;
		
		ans[i][j] = 1;
		
		for (int jump = 1; jump <= mat[i][j]; jump++) {
			if (ratmaze(mat, ans, i, j + jump))
				return true;
			
			if (ratmaze(mat, ans, i + jump, j))
				return true;
		}
		
		ans[i][j] = 0;
		dp[i][j] = 0;
		
		return false;
	}
	
	vector<vector<int>> shortestDist(vector<vector<int>> & mat) {
		// code here
		vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
		dp.assign(mat.size(), vector<int>(mat[0].size(), -1));
		if (!ratmaze(mat, ans, 0, 0)) {
			return {{-1}};
		}
		return ans;
	}
};