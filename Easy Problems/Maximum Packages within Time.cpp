/*
Maximum Packages within Time
A delivery agent has to deliver packages at locations arranged in a line. The number of packages at the ith location is given by arr[i].

The agent can start at any location and can only visit consecutive locations.
Visiting each location takes 1 unit of time.
Given arr[] and totalTime, find the maximum number of packages the agent can deliver within totalTime.

Examples:

Input: arr[] = [2, 1, 3, 5, 0, 1, 4], totalTime = 3
Output: 9
Explanation: The agent can visit three consecutive locations. Starting from the second location, it delivers arr[1] + arr[2] + arr[3] = 1 + 3 + 5 = 9 packages.
Input: arr[] = [1, 6, 2, 5, 3, 4], totalTime = 2
Output: 8
Explanation: The agent can visit two consecutive locations. Starting from the second location, it delivers arr[1] + arr[2] = 6 + 2 = 8 packages. Starting from the fourth location gives arr[3] + arr[4] = 5 + 3 = 8 packages. Hence, the maximum is 8 packages.
Constraints:

1 ≤ arr.size(), totalTime ≤ 105
0 ≤ arr[i] ≤ 103
*/
class Solution {
  public:
    int maxPackages(vector<int>& arr, int totalTime) {
        // code here
        int maxPackage = 0;
        for(int i =0 ; i<totalTime && i<arr.size();i++) maxPackage += arr[i];
        int temp = maxPackage , idx =0 ;
        for(int i=totalTime;i<arr.size() && idx<arr.size();i++){
            temp = temp-arr[idx++] + arr[i];
            maxPackage = max(maxPackage,temp);
        }
        return maxPackage;
    }
};