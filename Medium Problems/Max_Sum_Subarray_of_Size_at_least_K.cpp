/*
Max Sum Subarray of Size at least K
Given an array arr[] and an integer k, find the maximum sum among all contiguous subarrays having a length greater than or equal to k.

Examples:

Input: arr[] = [1, -2, 2, -3], k = 3
Output: 1
Explanation: The sub-array of length at least 3 that produces greatest sum is [1, -2, 2]
Input: arr[] = [1, 1, 1, 1, 1, 1], k = 2
Output: 6
Explanation: The sub-array of length at least 2 that produces greatest sum is [1, 1, 1, 1, 1, 1]
Input: arr[] = [-4, -2, 1, -3], k = 2
Output: -1
Explanation: The sub-array of length at least 2 that produces greatest sum is [-2, 1]

Constraints:

1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104
1 ≤ k ≤ arr.size()
*/
/*
        [Expected Approach] Sliding Window with Kadane's Optimization - O(n) Time and O(1) Space
        Steps:-
        1. Create a prefix sum array to store the sum of elements from the start of the array to the current index.
        2. Iterate through the array and for each index, calculate the sum of the subarray of length k ending at that index using the prefix sum array.
        3. Keep track of the maximum sum found so far and update it if the current  sum is greater than the previous maximum sum.

        Time Complexity: O(n) where n is the size of the array.
        Space Complexity: O(1) as we are using a prefix sum array of size n.
*/

class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
		int curr_sum = 0;
		for (int i = 0; i < k; i++) {
			curr_sum += arr[i];
		}
		int max_sum = curr_sum;
		int prefix_max = -10001;
		for (int i = k; i < n; i++) {
			curr_sum += arr[i] - arr[i - k];
			prefix_max = max({0, arr[i - k], prefix_max + arr[i - k]});
			max_sum = max(max_sum, curr_sum + prefix_max);
		}
		return max_sum;
	}
};
/*
        Least Optimization Approach:
        Steps:-
        1. Iterate through the array and for each index, calculate the sum of all subarrays starting from that index.
        2. For each subarray, check if its length is greater than or equal to k. If it is, update the maximum sum if the current sum is greater than the previous maximum sum.
        3. Return the maximum sum found.

        Time Complexity: O(n^2) where n is the size of the array.
        Space Complexity: O(1) as we are using only a constant amount of extra space.

*/
class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        // code here
        int maxSum = INT_MIN ;
        for(int i =0 ; i<arr.size();i++){
            int temp = 0 ;
            for(int j=i;j<arr.size();j++){
                temp+=arr[j];
                
                if((j-i+1) >=k)maxSum =max(maxSum,temp);
            }
        }
        return maxSum;
    }
};