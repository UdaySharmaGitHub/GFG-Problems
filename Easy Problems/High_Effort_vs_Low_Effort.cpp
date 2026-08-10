/*
High Effort vs Low Effort
Given two integer arrays h[] and l[], where h[i] and l[i] denote the number of tasks that can be completed on the i-th day by performing a high-effort task and a low-effort task, respectively.
For each day, you may choose exactly one of the following:
Perform no task.
Perform a low-effort task.
Perform a high-effort task, which can only be performed on the first day or if no task was performed on the previous day.
Return the maximum total number of tasks that can be completed over all days.
Examples:
Input: h[] = [2, 8, 1], l[] = [1, 2, 1]
Output: 9
Explanation: Pick the high-effort task on day 1 and the low-effort task on day 2. Total = 8 + 1 = 9.
Input: h[] = [3, 6, 8, 7, 6], l[] = [1, 5, 4, 5, 3]
Output: 20
Explanation: Pick the high-effort task on day 0 and low-effort tasks on all remaining days. Total = 3 + 5 + 4 + 5 + 3 = 20.
Constraints:
1 ≤ h.size() ≤ 105
0 ≤ h[i] ≤ 103
1 ≤ l.size() ≤ 105
0 ≤ l[i] ≤ 103
l.size() = h.size()
*/
/*
        APPROACH: [Expected Approach] Using Space Optimized Dynamic Programming - O(n) Time and O(1) Space
        Steps:
        1. Create two variables prev1 and prev2 to store the maximum number of tasks that can be completed on the previous day and the day before that, respectively.
        2. Iterate through the days and for each day, calculate the maximum number of tasks that can be completed by either performing a low-effort task or a high-effort task.
        3. Update prev1 and prev2 accordingly.
        4. Return prev1 as the final answer, which will contain the maximum number of tasks that can be completed over all days.

        Time Complexity: O(n) - We are iterating through the days once.
        Space Complexity: O(1) - We are using only a constant amount of space for
*/
class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        int n = l.size();
        if(n==0) return 0;
        
        int prev2 = 0;
        int prev1 = max(h[0],l[0]);
        
        if(n==1) return prev1;
        
        int curr = max(h[1],l[1]+prev1);
        
        prev2 = prev1;
        prev1 = curr;
        
        for(int i =2;i<n;i++){
            curr = max(l[i]+prev1,h[i]+prev2);
            prev2 = prev1;
            prev1=curr;
        }
        return prev1;
    }
};