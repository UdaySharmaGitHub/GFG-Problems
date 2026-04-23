/*
Two Equal Sum Subarrays
Given an array of integers arr[], return true if it is possible to split it in two subarrays (without reordering the elements), such that the sum of the two subarrays are equal. If it is not possible then return false.
Examples:
Input: arr[] = [1, 2, 3, 4, 5, 5]
Output: true
Explanation: We can divide the array into [1, 2, 3, 4] and [5, 5]. The sum of both the subarrays are 10.
Input: arr[] = [4, 3, 2, 1]
Output: false
Explanation: We cannot divide the array into two subarrays with equal sum.
Constraints:
1 ≤ arr.size() ≤ 105 
1 ≤ arr[i] ≤ 106
*/
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int totalSum = 0;
        for(int i:arr) totalSum+=i;
        int leftSum = 0 ;
        for(int i:arr){
            totalSum-=i;
            leftSum+=i;
            if(totalSum == leftSum) return 1;
        }
        
        return false;
        
    }
};
