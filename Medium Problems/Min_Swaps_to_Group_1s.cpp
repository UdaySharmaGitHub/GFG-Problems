/*
Min Swaps to Group 1s
You are given a binary array arr[] consisting only of 0s and 1s. Determine the minimum number of swaps required to group all the 1s together in a contiguous subarray.

A swap operation allows you to choose any two indices i and j and exchange their values (i.e., swap(arr[i], arr[j])).

If the array contains no 1s, return -1.

Examples:

Input: arr[] = [1, 0, 1, 0, 1]
Output: 1
Explanation: Only 1 swap is required to group all 1's together. Swapping index 1 and 4 will give arr[] = [1, 1, 1, 0, 0].
Input: arr[] = [1, 0, 1, 0, 1, 1] 
Output: 1
Explanation: Only 1 swap is required to group all 1's together. Swapping index 0 and 3 will give arr[] = [0, 0, 1, 1, 1, 1].
Input: arr[] = [0, 0, 0]
Output: -1
Explanation: No 1s are present in the array, so return -1.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 1
*/
/*
    Approach:
    1. Count the total number of 1s in the array. Let's call this count "ones". This will be the size of the window we need to consider.
    2. Use a sliding window of size "ones" to find the maximum number of 1s that can be grouped together in any contiguous subarray of that size.
    3. The minimum number of swaps required will be the total number of 1s minus the maximum number of 1s found in any window of size "ones". 
    This is because the number of swaps needed is equal to the number of 0s in that window, which is the total number of 1s minus the number of 1s in that window.

    Time Complexity: O(n) where n is the size of the input array.
    Space Complexity: O(1) as we are using only a constant amount of extra space
*/
class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1:  Window Size of One =  Count total 1s
        int ones = 0;
        for (int x : arr) ones += x;
        
        if (ones == 0) return -1;

        // Step 2: Take first window of size ones
        int curr = 0;
        for (int i = 0; i < ones; i++) {
            curr += arr[i];
        }

        
        int maxOnes = curr;

        // Step 3: Slide the window
        // Now move the window one step at a time:
        for (int i = ones; i < n; i++) {
            curr += arr[i];
            curr -= arr[i - ones];
            maxOnes = max(maxOnes, curr);
        }

        // Step 4: Compute swaps
        return ones - maxOnes;
    }
};