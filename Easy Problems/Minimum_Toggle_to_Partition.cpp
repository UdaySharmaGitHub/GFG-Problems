/*
Minimum Toggle to Partition
Given an array arr[] containing only 0 and 1. Find the minimum toggles (switch from 0 to 1 or vice-versa) required such the array become partitioned, i.e., it has first 0s then 1s.

Examples:

Input: arr = [1, 0, 1, 1, 0]
Output: 2
Explaination: The changed array will be [0, 0, 1, 1, 1]. So the number of toggles here required is 2.
Input: arr = [0, 1, 0, 0, 1, 1, 1]
Output: 1
Explaination: The changed array will be [0, 0, 0, 0, 1, 1, 1]. Required toggles are 1.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 1
*/
/*
    APPROACH:
    Step:
    1. We will count the total number of 0s in the array and store it in r0.
    2. We will initialize a variable l1 to count the number of 1s we have encountered so far.
    3. We will iterate through the array and for each element, if it is 0, we will decrement r0, and if it is 1, we will increment l1.
    4. At each step, we will calculate the total toggles required to partition the array at that point, which is the sum of remaining 0s (r0) and encountered 1s (l1).
    5. We will keep track of the minimum toggles required and return that as the answer.

    Time Complexity: O(n) - We need to iterate through the array once.
    Auxiliary Space: O(1) - We are using a constant amount of space to store the counts and other variables.
*/
class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
        int r0=0,l1=0;
        for(auto i:arr)if(i==0)r0++;
        int ans=r0;
        for(auto i:arr){
            if(i==0)r0--;
            else l1++;
            ans=min(ans,r0+l1);
        }
        return ans;
    }
};