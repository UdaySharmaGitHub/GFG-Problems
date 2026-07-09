/*
Towers Reaching Both Stations
Given a matrix mat[][] of size n x m, where mat[i][j] represents the signal strength of a communication tower. Two control stations monitor the network:

Station P covers the top and left boundaries of the grid.
Station Q covers the bottom and right boundaries of the grid.
A signal can propagate from a tower to one of its neighbouring towers in the four directions (North, South, East, and West) only if the neighbouring tower has a signal strength less than or equal to that of the current tower.

Determine the number of towers (x, y) from which a signal can eventually reach both Station P and Station Q. Any tower located on a boundary covered by a station can transmit directly to that station.

Examples:

Input: mat[][] = [[1, 2, 2, 3, 5], [3, 2, 3, 4, 4], [2, 4, 5, 3, 1], [6, 7, 1, 4, 5], [5, 1, 1, 2, 4]]
Output: 7
Explanation: 

(0, 4) & (4, 0) are part of both P & Q 
(1, 3) reaches P using (1,3)->(0,3) and Q using (1,3)->(1,4)
(1, 4) reaches P using (1,4)->(1,3)->(1,2)->(0,2) and it is on Q
(2, 2) reaches P using (2,2)->(2,1)->(2,0) and Q using (2,2)->(2,3)->(2,4)
(3, 0) is on P and reaches Q using (3,0)->(4,0)
(3, 1) reaches P using (3,1)->(3,0) and Q using (3,1)->(4,1)
Input: mat[][] = [[2, 2], [2, 2]]
Output: 4
Explanation: In the following example, all cells allow signals to propagate to both the stations.
Constraints:
1 ≤ n, m ≤ 103
1 ≤ mat[i][j] ≤ 103 
*/
class Solution {
  public:
    int countCoordinates(vector<vector<int>>& mat) {
        //here we do multi-source BFS.
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> v(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i = 0;i<m-1;i++){
            q.push({0,i});
            v[0][i]++;
        }
        for(int i = 0;i<n-1;i++){
            q.push({i,0});
            v[i][0]++;
        }
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            if(a+1 < n){
               if(mat[a+1][b] >= mat[a][b] && v[a+1][b] == 0){
                   q.push({a+1,b});
                   v[a+1][b]++;
               }
            }
            if(a-1 >= 0){
               if(mat[a-1][b] >= mat[a][b] && v[a-1][b] == 0){
                   q.push({a-1,b});
                   v[a-1][b]++;
               }
            }
            if(b+1 < m){
               if(mat[a][b+1] >= mat[a][b] && v[a][b+1] == 0){
                   q.push({a,b+1});
                   v[a][b+1]++;
               }
            }
            if(b-1 >= 0){
               if(mat[a][b-1] >= mat[a][b] && v[a][b-1] == 0){
                   q.push({a,b-1});
                   v[a][b-1]++;
               }
            }
        }
        vector<vector<int>> v1(n,vector<int>(m,0));
        for(int i = 1;i<m;i++){
            q.push({n-1,i});
            v1[n-1][i]++;
        }
        for(int i = 1;i<n;i++){
            q.push({i,m-1});
            v1[i][m-1]++;
        }
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            if(a+1 < n){
               if(mat[a+1][b] >= mat[a][b] && v1[a+1][b] == 0){
                   q.push({a+1,b});
                   v1[a+1][b]++;
               }
            }
            if(a-1 >= 0){
               if(mat[a-1][b] >= mat[a][b] && v1[a-1][b] == 0){
                   q.push({a-1,b});
                   v1[a-1][b]++;
               }
            }
            if(b+1 < m){
               if(mat[a][b+1] >= mat[a][b] && v1[a][b+1] == 0){
                   q.push({a,b+1});
                   v1[a][b+1]++;
               }
            }
            if(b-1 >= 0){
               if(mat[a][b-1] >= mat[a][b] && v1[a][b-1] == 0){
                   q.push({a,b-1});
                   v1[a][b-1]++;
               }
            }
        }
        v[0][m-1]++;
        v1[0][m-1]++;
        v[n-1][0]++;
        v1[n-1][0]++;
        vector<vector<int>> v2(n,vector<int>(m,0));
        q.push({0,m-1});
        q.push({n-1,0});
        v2[0][m-1]++;
        v2[n-1][0]++;
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            if(a+1 < n){
               if(mat[a+1][b] >= mat[a][b] && v2[a+1][b] == 0){
                   q.push({a+1,b});
                   v2[a+1][b]++;
               }
            }
            if(a-1 >= 0){
               if(mat[a-1][b] >= mat[a][b] && v2[a-1][b] == 0){
                   q.push({a-1,b});
                   v2[a-1][b]++;
               }
            }
            if(b+1 < m){
               if(mat[a][b+1] >= mat[a][b] && v2[a][b+1] == 0){
                   q.push({a,b+1});
                   v2[a][b+1]++;
               }
            }
            if(b-1 >= 0){
               if(mat[a][b-1] >= mat[a][b] && v2[a][b-1] == 0){
                   q.push({a,b-1});
                   v2[a][b-1]++;
               }
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if((v[i][j] > 0 && v1[i][j] > 0) || v2[i][j] > 0){
                cnt++;
            }
        }
        }
        return cnt;
    }
};