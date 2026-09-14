/*
Shortest Safe Route in Grid
Given a 2D matrix mat[][] of size n × m, where each cell is either 0 (landmine) or 1 (safe), find the minimum number of steps required to travel from any cell in the leftmost column to any cell in the rightmost column.
You can move only in four directions: up, down, left, and right.
A cell is unsafe if it contains a landmine or is directly adjacent (up, down, left, or right) to a landmine, and such cells must be avoided.
Return -1 if no safe path exists.
Examples:
Input: mat[][] = [[1, 0, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 0, 1], [1, 1, 1, 1, 0]]
Output: 6
Explanation: We can see that length of shortest safe route is 6. 
Input: mat[][] = [[1, 1, 1, 1, 1], [1, 1, 0, 1, 1], [1, 1, 1, 1, 1]]
Output: -1
Explanation: There is no possible path from first column to last column.
Constraints:
1 ≤ n, m ≤ 103
0 ≤ mat[i][j] ≤ 1
*/
class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat) {
            // code here
            int dr[4]={0, 1, 0, -1};
            int dc[4]={1, 0, -1, 0};

            int n=mat.size();
            int m=mat[0].size();

            for(int r=0; r<n; r++){
                for(int c=0; c<m; c++){
                    if(mat[r][c]==0){
                        for(int i=0; i<4; i++){
                            int nr=r+dr[i];
                            int nc=c+dc[i];

                            if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]==1){
                                mat[nr][nc]=-1;
                            }
                        }
                    }
                }
            }

            queue<pair<int, int>>q;
            set<pair<int, int>>vis;

            for(int r=0; r<n; r++){
                if(mat[r][0]==1){
                    q.push({r, 0});
                    vis.insert({r, 0});
                }
            }

            int steps=1;

            while(!q.empty()){
                int sz=q.size();
                while(sz--){
                    auto [r, c]=q.front();
                    q.pop();

                    if(c==m-1){
                        return steps;
                    }

                    for(int i=0; i<4; i++){
                        int nr=r+dr[i];
                        int nc=c+dc[i];

                        if(nr>=0 && nr<n && nc>=0 && nc<m && 
                        mat[nr][nc]==1 && vis.find({nr, nc})==vis.end()){
                            q.push({nr, nc});
                            vis.insert({nr, nc});
                        }
                    }
                }
                steps++;
            }

            return -1;
        }
};