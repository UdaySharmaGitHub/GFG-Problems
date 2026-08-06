/*
Minimum Increment or Double Operations to Convert
Given an array arr[]. Initially, you have another array containing only 0s.
In one operation, you may either:

Choose any one element and increase its value by 1, or
Double the values of all elements in the array simultaneously.
Find the minimum number of operations required to transform the initial all-zero array into the given array arr[].

Examples:

Input: arr[] = [16, 16, 16]
Output: 7
Explanation: 
First, increase each element to make the array [1, 1, 1] (3 steps).
Then, multiply the whole array by 2 four times:
[1,1,1] -> [2,2,2] -> [4,4,4] -> [8,8,8] -> [16,16,16]
Total steps = 3 + 4 = 7.
Input: arr[] = [2, 3]
Output: 4
Explanation: 
Start from [0, 0].
Increase both elements to get [1, 1] (2 steps)
Multiply once: [2, 2] (1 step)
Increase second element once: [2, 3] (1 step)
Total steps = 2 + 1 + 1 = 4.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 109
*/
/*
        APPROACH: [Expected Approach] Reverse Greedy - O(n × log m) Time and O(n) Space
        Steps:
        1. Start from the given array and try to reach the all-zero array.
        2. If any element is odd, we can undo the increment operation by decrementing that element by 1 and incrementing the operation count.
        3. If all elements are even, we can undo the doubling operation by dividing all elements by 2 and incrementing the operation    count.
        This process is repeated until all elements become zero.
        
        Time Complexity: O(n × log m), where n is the size of the array and m is the maximum element in the array.
        Space Complexity: O(n), where n is the size of the array.
*/
class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        // code here
          vector<int> nums = arr;
    int ops = 0;

    while (true) {
        bool allZero = true;
        for (int val : nums) {
            if (val != 0) {
                allZero = false;
                break;
            }
        }

        if (allZero) {
            return ops;
        }

        // Undo increment operations for any odd numbers
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) {
                nums[i]--;
                ops++;
            }
        }

        bool hasNonZero = false;
        for (int val : nums) {
            if (val > 0) {
                hasNonZero = true;
                break;
            }
        }

        // Undo one simultaneous doubling operation 
        // by dividing all elements by 2
        if (hasNonZero) {
            for (int& val : nums) {
                val /= 2;
            }
            ops++;
        }
    }
    return ops;
    }
};