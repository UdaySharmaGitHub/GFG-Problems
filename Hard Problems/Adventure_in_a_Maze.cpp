/*
Adventure in a Maze
Given a maze represented as an n x n grid, grid[][], using 0-based indexing. Each cell contains one of the values 1, 2, or 3, which determines the direction(s) you are allowed to move from that cell:

1 - you may move Right only.
2 - you may move Down only.
3 - you may move Right or Down (both directions are available).
You start at the top-left cell (0, 0) (the Entry) and must reach the bottom-right cell (n-1, n-1) (the Exit), following the movement rule of each cell you pass through. You are never allowed to move outside the boundaries of the grid.

The Adventure of a path is the sum of the values of all cells visited along that path (including both the entry and exit cells).

Find the total number of distinct valid paths from Entry to Exit, and among all such paths, the maximum possible Adventure. Return the answer as [totalPaths, maxAdventure].

Note: Return totalPaths modulo 109 + 7, maxAdventure needs no modulo, as it stays small regardless of grid size.

Examples:

Input: grid[][] = [[3, 2], [1, 3]]
Output: [2, 8]
Explanation:
There are 2 valid paths from [0, 0] to [1, 1]:
Path 1: [0, 0] -> [0, 1] -> [1, 1], values 3 + 2 + 3 = 8
Path 2: [0,0] -> [1, 0] -> [1, 1], values 3 + 1 + 3 = 7
The maximum Adventure among these is 8, so the output is [2, 8].
Input: grid[][] = [[1, 1, 3, 2, 1], [3, 2, 2, 1, 2], [1, 3, 3, 1, 3], [1, 2, 3, 1, 2], [1, 1, 1, 3, 1]]
Output: [4, 18]
Explanation: There are 4 valid paths from Entry to Exit, with total Adventures 
18, 17, 17, and 16 respectively. The maximum among these is 18, so the output is [4, 18].
Constraints:
1 ≤ n ≤ 100
*/
class Solution {
  public:
    vector<int> findWays(vector<vector<int>> &grid)
{
    const int MOD = 1e9 + 7;
    int n = grid.size();

    // Arrays to store the data of the "next" row below (i + 1)
    vector<int> nextWays(n, 0);

    // Initialize as unreachable (-1)
    vector<int> nextAdv(n, -1);

    // Iterate backwards from the bottom row to the top row
    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> currWays(n, 0);
        vector<int> currAdv(n, -1);

        for (int j = n - 1; j >= 0; j--)
        {
            // Base Case: Bottom-right cell (The Exit)
            if (i == n - 1 && j == n - 1)
            {
                currWays[j] = 1;
                currAdv[j] = grid[i][j];
                continue;
            }

            long long totalWays = 0;
            int maxAdventure = -1;
            int cellValue = grid[i][j];

            // Option 1: Move Right (Valid for cell values 1 and 3)
            if (cellValue == 1 || cellValue == 3)
            {
                // Check if right neighbor is within boundaries and reachable
                if (j + 1 < n && currAdv[j + 1] != -1)
                {
                    totalWays = (totalWays + currWays[j + 1]) % MOD;
                    maxAdventure = max(maxAdventure, grid[i][j] + currAdv[j + 1]);
                }
            }

            // Option 2: Move Down (Valid for cell values 2 and 3)
            if (cellValue == 2 || cellValue == 3)
            {

                // Check if bottom neighbor is within boundaries and reachable
                if (i + 1 < n && nextAdv[j] != -1)
                {
                    totalWays = (totalWays + nextWays[j]) % MOD;
                    maxAdventure = max(maxAdventure, grid[i][j] + nextAdv[j]);
                }
            }

            currWays[j] = totalWays;
            currAdv[j] = maxAdventure; // Remains -1 if no valid path exists
        }

        // Move row states upwards efficiently using std::move
        nextWays = move(currWays);
        nextAdv = move(currAdv);
    }

    // Results are aggregated back at the entry point (0, 0)
    int finalPaths = nextWays[0];
    int finalAdv = (nextAdv[0] == -1) ? 0 : nextAdv[0];

    return {finalPaths, finalAdv};
}

};