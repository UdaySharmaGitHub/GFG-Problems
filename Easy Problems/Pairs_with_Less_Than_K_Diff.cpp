/*
Pairs with Less Than K Diff
Given an array arr[] of positive integers and an integer k, find the total number of pairs of elements that have an absolute difference strictly less than k.

Note:  Pair (i, j) is considered the same as (j, i).

Examples:

Input : arr[] = [1, 10, 4, 2], k = 3
Output : 2
Explanation: We have an array arr[] = [1, 10, 4, 2] and k = 3 We can make only two pairs with a difference of less than 3. (1, 2) and (4, 2). So, the answer is 2.
Input : arr[] = [2, 3, 4], k = 5
Output : 3
Explanation:  For the given array arr[] = [2, 3, 4] and k = 5, there are 3 valid pairs where the absolute difference between the pair's elements is less than 5. These pairs are (2, 3), (2, 4), and (3, 4). Hence, the output is 3.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ k ≤ 105
1 ≤ arr[i] ≤ 105
*/
/*
    APPRAOCH:
    Steps:
    1. Sort the array.
    2. Use two pointers to find the pairs with a difference less than k.
    3. Initialize two pointers, left and right, both starting at the beginning of the array.
    4. Iterate through the array using the right pointer.
    5. For each position of the right pointer, move the left pointer to the right as long as the difference between the elements at the right and left pointers is greater than or equal to k.
    6. The number of valid pairs for the current position of the right pointer is
    (right - left), which represents the number of elements between the left and right pointers.
    7. Accumulate the count of valid pairs in a variable ans.
    8. Return the final count of valid pairs.
    
    Time Complexity: O(nlogn) + O(n) = O(nlogn)
    Space Complexity: O(1)
*/
class Solution {
public:
    int countPairs(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int left = 0;
        long long ans = 0;

        for (int right = 0; right < n; right++) {

            while (arr[right] - arr[left] >= k)
                left++;

            ans += (right - left);
        }

        return ans;
    }
};