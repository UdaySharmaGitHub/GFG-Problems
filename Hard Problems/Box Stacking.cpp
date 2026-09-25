/*
Box Stacking
Given three arrays height[], width[], and length[] of size n, where height[i], width[i], and length[i] represent the dimensions of the ith box, find the maximum possible height of a stack formed using these boxes.

A box can be rotated so that any of its dimensions becomes its height.
 A box can be placed on top of another only if both dimensions of its base are strictly smaller than those of the box below. 
Multiple instances of the same box can be used.
Examples:

Input: height[] = [4, 1, 4, 10], width[] = [6, 2, 5, 12], length[] = [7, 3, 6, 32]
Output: 60
Explanation: One possible arrangement of the boxes from bottom to top is shown below. Note that there can be multiple instances of a box type.
 
Hence, the total height of this stack is 10 + 32 + 4 + 4 + 6 + 1 + 3 = 60. No other combination of boxes produces a height greater than this.
Input: height[] = [1, 4, 3], width[] = [2, 5, 4], length[] = [3, 6, 1]
Output: 15
Explanation: One possible arrangement of the boxes from bottom to top is shown below: 

Hence, the total height of this stack is 4 + 6 + 1 + 1 + 3 = 15 No other combination of boxes produces a height greater than this.
Constraints:

1 ≤ height.size(), width.size(), length.size() ≤ 100
1 ≤ height[i], width[i], length[i] ≤ 106
*/
class Solution {
  public:
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        int n = height.size();
        vector<vector<int>> boxes;
        for (int i = 0; i < n; i++) {
            int a = height[i], b = width[i], c = length[i];
            boxes.push_back({max(b, c), min(b, c), a});
            boxes.push_back({max(a, c), min(a, c), b});
            boxes.push_back({max(a, b), min(a, b), c});
        }
        sort(boxes.begin(), boxes.end(), [](const vector<int>& x, const vector<int>& y) {
            if (x[0] != y[0]) return x[0] > y[0];
            return x[1] > y[1];
        });
        int m = boxes.size();
        vector<int> dp(m);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            dp[i] = boxes[i][2];
            for (int j = 0; j < i; j++) {
                if (boxes[j][0] > boxes[i][0] && boxes[j][1] > boxes[i][1]) {
                    dp[i] = max(dp[i], dp[j] + boxes[i][2]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};