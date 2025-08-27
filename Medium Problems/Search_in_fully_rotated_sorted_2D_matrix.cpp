/*
Search in fully rotated sorted 2D matrix
You are given a 2D matrix mat[][] of size n x m that was initially filled in the following manner:
Each row is sorted in increasing order from left to right.
The first element of every row is greater than the last element of the previous row.
This implies that if the matrix is flattened row-wise, it forms a strictly sorted 1D array.
Later, this sorted 1D array was rotated at some unknown pivot. The rotated array was then written back into the matrix row-wise to form the current matrix.
Given such a matrix mat[][] and an integer x, determine whether x exists in the matrix.
Examples:
Input: x = 3,
mat[][] = [[7, 8, 9, 10],           
          [11, 12, 13, 1],
          [2, 3, 4, 5]] 
Output: true
Explanation: 3 is located at the 3rd row and 2nd column.
Input: x = 10,
mat[][] = [[6, 7, 8],                         
          [9, 1, 2],
          [3, 4, 5]]
Output: false
Explanation: The value 10 does not exist in the matrix.
Constraint:
1 ≤ n × m ≤ 105
1 ≤ mat[i][j], x ≤ 106
*/
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
         int m = mat.size();
        int n = mat[0].size();
        int i = 0;
        int j = (n*m)-1;
        while(i<=j){
            int mid = (i+j)/2;
            int lowr = i/n;
            int lowc = i%n;
            int highr = j/n;
            int highc = j%n;
            int midr = mid/n;
            int midc = mid%n;
            if(mat[midr][midc]==x) return true;
            if(mat[lowr][lowc]<=mat[midr][midc]){
                
            
                if(mat[lowr][lowc]<=x && mat[midr][midc]>=x){
                    j = mid-1;
                }   
                else {
                    i = mid+1;
                }
            
                
                
            }
            else{
                if(mat[midr][midc]<=x && x<=mat[highr][highc]){
                    i = mid+1;
                }
                else{
                    j=mid-1;
                }
            }
            
        }
        return false;
    }
};
