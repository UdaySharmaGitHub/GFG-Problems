/*
Max Profit from Two Machines
Given two machines, Machine A and Machine B, and a set of n tasks. The profit earned for performing each task is given in two arrays a[] and b[] such that if Machine A performs the i-th task, the profit is a[i], and if Machine B performs it, the profit is b[i].

Machine A can process at most x tasks, and Machine B can process at most y tasks. It is guaranteed that x + y ≥ n, so all tasks can be assigned. Return the maximum possible profit after assigning each task to either Machine A or Machine B.

Examples:

Input: x = 3, y = 3, a[] = [1, 2, 3, 4, 5], b[] = [5, 4, 3, 2, 1]
Output: 21
Explanation: Machine A performs tasks with indices [2, 3, 4], and Machine B performs the rest [0, 1], giving profits (3 + 4 + 5) + (5 + 4) = 21.
Input: x = 4, y = 4, a[] = [1, 4, 3, 2, 7, 5, 9, 6], b[] = [1, 2, 3, 6, 5, 4, 9, 8]
Output: 43
Explanation: Machine A performs tasks with indices [1, 4, 5, 6], and Machine B performs the rest [0, 2, 3, 7], giving profits (4 + 7 + 5 + 9) + (1 + 3 + 6 + 8) = 43.
Input: x = 3, y = 4, a[] = [8, 7, 15, 19, 16, 16, 18], b[] = [1, 7, 15, 11, 12, 31, 9]
Output: 110
Explanation: Machine A performs tasks with indices [0, 3, 6], and Machine B performs the rest [1, 2, 4, 5], giving profits (8 + 19 + 18) + (7 + 15 + 12 + 31) = 110.
Constraints:
1 ≤ a.size() == b.size() ≤ 105
1 ≤ x, y ≤ 105
1 ≤ a[i], b[i] ≤ 104
*/
/*
        Approach:
        1. Create a vector of pairs to store the difference in profit between Machine A and Machine B for each task, along with the index of the task.
        2. Sort this vector in descending order based on the profit difference.
        3. Initialize a variable to keep track of the total profit and a counter for the number of tasks assigned to Machine A.
        4. Iterate through the sorted vector and assign tasks to Machine A until it reaches its maximum capacity (x). If the profit difference is negative and there are still tasks that can be assigned to Machine B, break the loop.
        5. For the remaining tasks, assign them to Machine B and add their profits to the total profit.
        6. Return the total profit. 

        Time Complexity: O(n log n) due to sorting.
        Space Complexity: O(n) for the vector of pairs.
*/
class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        // code here
         int n = a.size();
        vector<pair<int,int>>vec;
        for(int i = 0 ;i<n ; i++){
            vec.push_back({a[i] - b[i] , i});
        }
        sort(vec.begin() , vec.end() , greater());
        int res = 0 , i=0;
        for(;i<x ; i++){
            if(vec[i].first<0 && n-i <=y)break;
            res+= a[vec[i].second];
        }
        for(;i<n ; i++)res+= b[vec[i].second];
        
        return res;
    }
};