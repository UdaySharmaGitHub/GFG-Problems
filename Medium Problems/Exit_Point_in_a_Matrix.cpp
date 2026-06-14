/*
Exit Point in a Matrix
Given a matrix mat[][] of size n × m consisting of 0s and 1s. You start at the top-left cell (0, 0) and initially move in the left-to-right direction (i.e., towards the right).

While traversing the matrix, follow these rules:

If the current cell contains 0, continue moving in the same direction.
If the current cell contains 1, change your direction to the right (clockwise turn), and update the cell value to 0.
You continue this process until you move outside the boundaries of the matrix. Your task is to determine the coordinates (row and column index) of the cell from which you exit the matrix.

Examples:

Input: mat[][] = [[0, 1, 0],
               [0, 1, 1], 
               [0, 0, 0]]
Output: [1, 0]
Explanation: 

From the image we can see that, enter the matrix at (0, 0) 
-> then move towards (0, 1) ->  1 is encountered 
-> turn right towards (1, 1)  -> again 1 is encountered 
-> turn right again towards (1, 0) 
-> now, the boundary of matrix will be crossed. Hence, exit point reached at [1, 0].
Input: mat[][] = [[0, 0]]
Output: [0, 1]
Explanation: 
Enter the matrix at cell (0, 0).
Since the cell contains 0, we continue moving in the same direction.
We reach cell (0, 1), which also contains a 0. So, we continue moving in the same direction, we exit the matrix from cell [0, 1].
Constraints:
1 ≤ n, m ≤ 100
*/
/*
    APPROACH:
    1. We can use a map to store the direction change when we encounter a 1 in the matrix. The direction change is as follows:
        W -> S
        S -> E
        E -> N
        N -> W
    2. We can use another map to store the direction vectors for each direction. The direction vectors are as follows:
        W -> (0, 1)
        S -> (1, 0)
        E -> (0, -1)
        N -> (-1, 0)
    3. We can start from the top-left cell (0, 0) and initially move in the left-to-right direction (i.e., towards the right).
    4. While traversing the matrix, we can check the value of the current cell. If it is 0, we continue moving in the same direction. If it is 1, we change our direction to the right (clockwise turn), and update the cell value to 0.
    5. We continue this process until we move outside the boundaries of the matrix. We can return the coordinates (row and column index) of the cell from which we exit the matrix.

    Time Complexity: O(n*m) where n is the number of rows and m is the number of columns in the matrix.
    Space Complexity: O(1) as we are using only a constant amount of extra space.
*/
class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        map<char, char>dir_ch={{'W','S'}, {'S','E'}, {'E','N'}, {'N','W'}};
        map<char, pair<int, int>>dir={ {'W',{0, 1}}, {'S',{1, 0}}, {'E',{0, -1}}, {'N',{-1, 0}} };
        
        int r=0, c=0;
        char d='W';
        
        while(r<n && c<m){
            if(mat[r][c]==0){
                int nr=r+dir[d].first;
                int nc=c+dir[d].second;
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    r=nr;
                    c=nc;
                }else return {r, c};
            }else{
                d=dir_ch[d];
                mat[r][c]=0;
            }
        }
        return {-1, -1};
    }
};