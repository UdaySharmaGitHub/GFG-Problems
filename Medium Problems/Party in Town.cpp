/*
Party in Town
Geek Town has n houses numbered from 1 to n, choose a house to host a party such that its distance from its farthest house is as small as possible. Return this minimum possible distance.
The houses are connected by n − 1 bidirectional roads, forming a tree. 
The connections are given as an adjacency list adj, where adj[i] contains all houses directly connected to house i + 1. 
Examples:

Input: adj[][] = [[2], [1, 4, 3], [2], [2]] 

Output: 1
Explanation: Party should take place at house number 2. Maximum distance from house number 2 is 1.
Input: adj[][] = [[2], [1, 3], [4, 2], [3]]

Output: 2
Explanation: Party should take place at house number 2 or 3. The minimum distance is 2.
Constraints:

1 ≤ n ≤ 105
1 ≤ adj[i][j]
adj.size() = n
*/
class Solution {
  public:
    pair<int,int> func(vector<vector<int>> &adj,int i){
          //wanna give the farthest node as well as its distance
          int n = adj.size();
          queue<int> q;
          q.push(i);
          vector<int> dist(n,-1);
          dist[i] = 0;
          int last_dist = 0;
          int last_node = 0;
          while(!q.empty()){
              int size = q.size();
              for(int i = 0;i<size;i++){
                  int curr = q.front();
                  q.pop();
                //   last_dist = dist[curr];
                //     last_node = curr;
                  for(int x : adj[curr]){
                      if(dist[x-1] == -1){
                          dist[x-1] = dist[curr] + 1;
                          q.push(x-1);
                      }
                  }
                    if(dist[curr] > last_dist){
                         last_dist = dist[curr];
                        last_node = curr;
                    }
              }
          }
          return {last_node,last_dist};
      }

        int partyHouse(vector<vector<int>> &adj) {
            // code here
            pair<int,int> p1 = func(adj,0);
            pair<int,int> p2 = func(adj,p1.first);
            return (p2.second + 1) / 2;
        }
};