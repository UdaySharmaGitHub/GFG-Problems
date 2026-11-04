/*
Largest Sum Cycle
Given an array edge[] of size n, there are n cells numbered from 0 to n - 1. Each cell has at most one outgoing edge.

For every cell i:

edge[i] is the cell reached from i in one step.
edge[i] = -1 means that cell i has no outgoing edge.
A cycle is a sequence of cells where, by following the outgoing edges, we eventually return to the starting cell. The sum of a cycle is the sum of the indices of all cells in that cycle.

Return the maximum cycle sum. If there is no cycle, return -1.

Examples:

Input: edge[] = [1, 2, 0, -1]
Output: 3
Explanation: There is only one cycle in the graph i.e. 0 -> 1 -> 2 -> 0. Sum of the cell index in that cycle = 0 + 1 + 2 = 3.

Input: edge[] = [2, 0, -1, 2]
Output: -1
Explanation: There is no cycle in the graph. The edges are 1 -> 0 -> 2 <- 3. Hence, 2 has no outgoing edge, so no cycle exists.

Constraints:

2 ≤ edge.size() ≤ 105
-1 ≤ edge[i] < edge.size()
edge[i] != i
*/
class Solution {
  public:

      int DFS(int u,vector<bool> &path,vector<bool> &visited,vector<int>& edge,int &ans,int &temp){

          path[u] = 1;
          visited[u]=1;
          int v = edge[u];

          if(v==-1){ 
              path[u]=0;
              return 0;
          }
          else if(path[v]){
              path[v]=0;
              temp+=u;
              return 1;
          }
          else if(visited[v]){
              path[u]=0;
              return 0;

          }
          else{

             int num =  DFS(v,path,visited,edge,ans,temp);

             if(num){
                 temp+=u;
                 if(!path[u]){ans = max(ans,temp);return 0;}
                 return 1;
             }
             else {
                 path[u]=0;
                 return 0;
             }    
          }
      }

      int largestSumCycle(vector<int>& edge) {
          // code here
          int n = edge.size();
          vector<bool>path(n,0);
          vector<bool>visited(n,0);
          int ans = -1;
          int temp = 0;

          for(int i=0;i<n;i++){
              if(!visited[i]){
                  temp = 0;
                  DFS(i,path,visited,edge,ans,temp);
              }
          }

          return ans;
      }
};