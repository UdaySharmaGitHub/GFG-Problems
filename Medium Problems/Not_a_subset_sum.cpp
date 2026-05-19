/*
Not a subset sum
Given a array arr[] of positive integers, find the smallest positive integer such that it cannot be represented as the sum of elements of any subset of the given array set.

Examples:

Input: arr[] = [3, 1, 2]
Output: 7
Explanation: 7 is the smallest positive number for which no subset is there with sum 7.
Input: arr[] = [3, 10, 9, 6, 20, 28]
Output: 1
Explanation: 1 is the smallest positive number for which no subset is there with sum 1.
Constraints
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 103
*/

// User function template for C++

class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        // Your code goes here.
        int res = 1;
    
    // Sort the array 
	sort(arr.begin(), arr.end());

	// Traverse the array and increment 'res' if arr[i] is
	// smaller than or equal to 'res'.
	for (int i=0; i<arr.size() && arr[i] <= res; i++) {
		res += arr[i];
	}

	return res;
    }
};

