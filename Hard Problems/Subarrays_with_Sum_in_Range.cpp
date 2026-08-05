/*
Subarrays with Sum in Range
Given an integer array arr[] and two integers l and r, find the number of subarrays whose sum lies in the range [l, r] (inclusive).

A subarray is a contiguous sequence of elements within the array.

Examples:

Input: l = 3, r = 8, arr[] = [1, 4, 6]
Output: 3
Explanation: The subarrays are [1,4], [4] and [6]. Therefore answer for this test case is 3.
Input: l = 4, r = 13, arr[] = [2, 3, 5, 8]
Output: 6
Explanation: The subarrays are [2, 3], [2, 3, 5], [3, 5], [5], [5, 8] and [8]. 
Therefore answer for this test case is 6.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
1 ≤ l ≤ r ≤ 109
*/
/*
        APPROACH: [Expected Approach - 1] Using Sliding Window with Inclusion-Exclusion - O(n) Time and O(1) Space
        Steps:
        1. Define a helper function countSubarraysWithSumLessThanOrEqualTo that counts the number of subarrays with sum less than or equal to a given value.
        2. Use the helper function to count the number of subarrays with sum less than or equal to r and the number of subarrays with sum less than l.
        3. The result is the difference between the two counts, which gives the number of subarrays with sum in the range [l, r].
        4. Return the result.   
        
        Time Complexity: O(n) - The sliding window technique ensures that each element is processed at most twice.
        Space Complexity: O(1) - No additional space is used that scales with input size
*/
class Solution {
  public:
  int countSum(vector<int>&arr,int x){
      int n  = arr.size();
      
      int st = 0 ,en =0 ,sum =0 ,count  = 0 ;
      while(en<n){
          sum+=arr[en];
          while(st<=en && sum>x){
              sum-=arr[st];
              st++;
          }
          count+=(en-st+1);
          en++;
      }
      return count;
  }
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        int sub1 = countSum(arr,l-1);
        int sub2 = countSum(arr,r);
        return sub2 - sub1;
    }
};
/*
        APPROACH: [Naive Approach] Using Two Nested Loops - O(n^2) Time and O(1) Space
        Steps:
        1. Initialize a variable count to 0.
        2. Iterate through the array using two nested loops to consider all possible subarrays.
        3. For each subarray, calculate the sum of its elements.
        4. If the sum lies within the range [l, r], increment the count.
        5. Return the count after checking all subarrays.

        Time Complexity: O(n^2) - Due to the two nested loops iterating through the array.
        Space Complexity: O(1) - No additional space is used that scales with input size
*/
class Solution {
  public:
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        int count = 0;
        for(int i =0;i<arr.size();i++){
            int sum = 0;
            for(int j =i;j<arr.size();j++){
                sum+=arr[j];
                if(sum>=l && sum<=r)count++;
            }
        }
        return count ;
    }
};