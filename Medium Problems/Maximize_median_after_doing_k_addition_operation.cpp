/*
Maximize median after doing k addition operation
Given an array arr[] consisting of positive integers and an integer k. You are allowed to perform at most k operations, where in each operation, you can increment any one element of the array by 1. Determine the maximum possible median of the array that can be achieved after performing at most k such operations.
Note: The median of an array is defined as the middle element when the array (after sorting) has an odd size, or the average of the two middle elements when the array (after sorting) has an even size.
Examples:
Input: arr[] = [1, 3, 4, 5], k = 3
Output: 5
Explanation: We can add +2 to the second element and +1 to the third element to get the array [1, 5, 5, 5]. After sorting, the array remains [1, 5, 5, 5]. Since the length is even, the median is (5 + 5) / 2 = 5.
Input: arr[] = [1, 3, 6, 4, 2], k = 10
Output: 7
Explanation: After applying operations optimally, we can transform the array to [1, 3, 7, 7, 7] (one possible way). Sorted array becomes [1, 3, 7, 7, 7]. Since the length is odd, the median is the middle element 7.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i], k ≤ 109
*/
class Solution {
  public:
       bool possible(vector<int>& arr, int mid, int pos, int k) {
        long long operations = 0;
        for (int i = pos; i < arr.size(); i++) {
            if (arr[i] < mid) 
                operations += (mid - arr[i]);
            if (operations > k) return false; // early stop
        }
        return true;
    }

    int maximizeMedian(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        // median position (lower median if even size)
        int pos = (n & 1) ? n/2 : n/2 - 1;

        long long low = arr[pos];
        long long high = arr[pos] + k;
        long long ans = low;

        // binary search maximum possible median
        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (possible(arr, mid, pos, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // if odd length, just return median
        if (n & 1) return ans;

        // if even, median is average of two middle values
        if (ans <= arr[pos + 1]) 
            return (ans + arr[pos + 1]) / 2;
        return ans;
    }

};