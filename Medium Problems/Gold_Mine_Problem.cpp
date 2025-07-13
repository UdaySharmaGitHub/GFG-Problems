/*
Gold Mine Problem
Given a gold mine called mat[][]. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially, the miner can start from any row in the first column. From a given cell, the miner can move -

to the cell diagonally up towards the right
to the right
to the cell diagonally down towards the right
Find out the maximum amount of gold that he can collect until he can no longer move.

Examples:

Input: mat[][] = [[1, 3, 3], [2, 1, 4], [0, 6, 4]]
Output: 12
Explaination: The path is (1, 0) -> (2, 1) -> (2, 2). Total gold collected is 2 + 6 + 4 = 12.
Input: mat[][] = [[1, 3, 1, 5], [2, 2, 4, 1], [5, 0, 2, 3], [0, 6, 1, 2]]
Output: 16
Explaination: The path is (2, 0) -> (3, 1) -> (2, 2) -> (2, 3) or (2, 0) -> (1, 1) -> (1, 2) -> (0, 3). 
Total gold collected is (5 + 6 + 2 + 3) or (5 + 2 + 4 + 5) = 16.
Input: mat[][] = [[1, 3, 3], [2, 1, 4], [0, 7, 5]]
Output: 14
Explaination: The path is (1,0) -> (2,1) -> (2,2). Total gold collected is 2 + 7 + 5 = 14.
Constraints:
1 ≤ mat.size(), mat[0].size() ≤ 500
0 ≤ mat[i][j] ≤ 100
*/
class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        // code here
          int n=mat.size(),m=mat[0].size(),ans=0;
        for(int j=n-2;j>=0;j--){
            for(int i=0;i<n;i++){
                int curr=0;
                curr=max(curr,mat[i][j]+mat[i][j+1]);
                if(i<n-1){
                    curr=max(mat[i][j]+mat[i+1][j+1],curr);
                }
                if(i>0){
                    curr=max(mat[i][j]+mat[i-1][j+1],curr);
                }
                mat[i][j]=curr;
                if(j==0){
                    ans=max(ans,curr);
                }
            }
        }
    return ans;
    }
};