/*
Snake and Ladder Problem
Given an integer n such that there is n × n Snakes and Ladders board with cells numbered from 1 to n*n, find the minimum number of dice throws required to reach cell n*n starting from cell 1. Given two arrays of even lengths:

lad[], where each pair (lad[2*i], lad[2*i + 1]) represents the start and end of a ladder.
sn[], where each pair (sn[2*i], sn[2*i + 1]) represents the start and end of a snake.
If you land on the start cell of a snake or ladder, you must immediately move to its corresponding end cell.

You have complete control over the outcome of each dice throw i.e., in a single move,  you can move forward by any number of cells from 1 to 6. 

If it is impossible to reach cell n*n, return -1.

Examples:

Input: n = 6, lad[] = [3, 22, 5, 8, 11, 35, 20, 32], sn[] = [17, 4, 19, 7, 34, 1, 21, 9]
Output: 3
Explanation: For the 6 × 6 board, the minimum number of dice throws needed to reach cell 36 from cell 1 is 3.
One optimal path is:
Throw 4 to move from 1 to 5, then take the ladder to 8
Throw 3 to move from 8 to 11, then take the ladder to 35
Throw 1 to move from 35 to 36
So the destination is reached in 3 dice throws.

Input: n = 3, lad[] = [2, 8], sn[] = [7, 3]
Output: 2
Explanation: For the 3 × 3 board, the minimum number of dice throws needed to reach cell 9 from cell 1 is 2.
One optimal path is:
Throw 1 to move from 1 to 2, then take the ladder to 8.
Throw 1 to move from 8 to 9.
So the destination is reached in 2 dice throws.
Constraints:
1 ≤ n ≤ 103
1 ≤ lad.size(), sn.size(), lad[i], sn[i] ≤ n2 
*/
class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        // code here

        unordered_map<int, int> ladders;
        unordered_map<int, int> snacks;

        for (int i = 0; i + 1 < lad.size(); i+=2) {

            int st = lad[i];
            int end = lad[i+1];

            ladders[st] = end;
        }

        for (int i = 0; i + 1 < sn.size(); i+=2) {

            int st = sn[i];
            int end = sn[i+1];

            snacks[st] = end;
        }

        int ans = 0;
        queue<int> q;
        vector<bool> visited(n*n+1, false);
        visited[1] = true;
        q.push(1);

        while (!q.empty()) {

            int N = q.size();

            while (N--) {

                int curr = q.front();
                q.pop();


                if (curr == n*n) {
                    return ans;
                }


                for (int i=1; i<=6; i++) {

                    int newNum = curr + i;
                    if (newNum > n*n) continue;

                    if (ladders.count(newNum)) {
                        newNum = ladders[newNum];
                    } else if (snacks.count(newNum)) {
                        newNum = snacks[newNum];
                    }

                    if (!visited[newNum]) {
                        q.push(newNum);
                        visited[newNum] = true;
                    }
                }
            }

            ans++;
        }

        return -1;

    }
};