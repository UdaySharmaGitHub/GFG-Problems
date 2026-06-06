/*
Non-Attacking Black and White Knights
Given two integers n and m representing the dimensions of a chessboard, find the number of ways to place one black knight and one white knight on the chessboard such that they cannot attack each other.

Note:

The knights have to be placed on different squares.
A knight can move two squares horizontally and one square vertically (L shaped), or two squares vertically and one square horizontally (L shaped).
The knights attack each other if one can reach the other in one move.
Examples:

Input: n = 2, m = 2
Output: 12 
Explanation: There are 12 ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.
Input: n = 2, m = 3
Output: 26
Explanation: There are 26 ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.
Constraints:
1 ≤ n ≤ 200
1 ≤ m ≤ 225
*/
/*
    APPROACH:
    Steps:
    1. We will iterate through each cell of the chessboard and for each cell, we will calculate the number of cells that are not attacked by the knight placed on that cell.
    2. We will use two nested loops to iterate through the chessboard and for each cell, we will use another two nested loops to calculate the number of cells that are attacked by the knight placed on that cell.
    3. We will keep a count of the total number of cells that are not attacked by the knight placed on that cell and add it to the final answer.        

    Time Complexity: O(n*m*8) = O(n*m)
    Space Complexity: O(1)
*/
class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
        int no=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int total=n*m-1;
                
                for(int x=-2;x<=2;x++){
                    for(int y=-2;y<=2;y++){
                        
                        if((abs(x)+abs(y))!=3)continue;
                        int pos_x=i+x;
                        int pos_y=j+y;
                        
                        if(pos_x>=0 && pos_x<n && pos_y>=0 && pos_y<m)total--;
                    }
                }
                
                no+=total;
            }
        }
        
        return no;
    }
};