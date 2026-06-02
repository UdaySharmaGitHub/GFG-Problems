/*
Pairs with certain difference
Given an array of integers and a number k, the task is the find maximum pair sum with the following conditions on the pairs.

Pair difference should be less than k.
Pairs should be disjoint. For example if (x, y) is a result pair, then neither x nor y should appear in any other result pair.
Sum of p pairs means sum of 2p elements in the result.
If no valid pairs can be formed, return 0.

Examples:

Input: arr[] = [3, 5, 10, 15, 17, 12, 9], K = 4
Output: 62
Explanation :
The valid disjoint pairs with difference less than K are:
(3, 5), (10, 12), (15, 17)
The maximum sum obtained from these pairs is:
3 + 5 + 10 + 12 + 15 + 17 = 62
An alternative pairing could be:
(3, 5), (9, 12), (15, 17)
However, this combination results in a smaller total sum, so it is not optimal.
Input: arr[] = [5, 15, 10, 300], k = 12
Output: 25
Explanation: 
The valid disjoint pairs with difference less than k are:
(5, 10)
The maximum sum obtained from these pairs is:
5 + 10 = 15
An alternative pairing could be:
(10, 15)
However, this combination results in a larger total sum:
10 + 15 = 25. So this pairing is optimal.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ k ≤ 105
1 ≤ arr[i] ≤ 104
*/
/*
    Approach:
    1. Sort the array in non-decreasing order.
    2. Initialize a variable sum to store the maximum pair sum.
    3. Iterate through the sorted array from the end to the beginning:
    a. For each element arr[i], check if the difference between arr[i] and the previous element arr[i-1] is less than k.
    b. If the difference is less than k, it means we can form a valid pair (arr[i], arr[i-1]).
    c. Add the sum of the pair (arr[i] + arr[i-1]) to the variable sum.
    d. Skip both elements of the pair by decrementing i by 2 (i.e., i -= 2) to ensure that the pairs are disjoint.
    4. Return the final value of sum, which will be the maximum pair sum with the given conditions.

    Time Complexity: O(n log n) due to sorting the array.
    Space Complexity: O(1) as we are using only a constant amount of extra space.
*/
class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int sum = 0;

        for(int i = n - 1; i > 0; i--){
            // If pair possible
            if(arr[i]-arr[i-1] < k) {
                sum += arr[i] + arr[i-1];
                // Skip both used elements
                i--;
            }
        }

        return sum;
    }
};