/*
Mountain Subarray Queries
Given an array arr[] and a list of queries. For each query [l, r], find whether the subarray arr[l...r] is a mountain array. A subarray is called a mountain array if there exists an index k (l ≤ k ≤ r) such that: arr[l] ≤ arr[l + 1] ≤ ... ≤ arr[k] ≥ arr[k + 1] ≥ ... ≥ arr[r].

Elements of a Mountain subarray are first non-decreasing and then non-increasing.
A subarray that is entirely non-decreasing or entirely non-increasing is also considered a mountain.
Examples:

Input: arr[] = [2, 3, 2, 4, 4, 6, 3, 2], queries[][] = [[0, 2], [1, 3]]
Output: [true, false]
Explanation: For query [0, 2], the subarray is [2, 3, 2]. The elements first increase and then decrease, so it forms a mountain.
For query [1, 3], the subarray is [3, 2, 4]. The elements decrease and then increase, so it does not form a mountain.
Input: arr[] = [2, 2, 2, 2], queries[][] = [[0, 2], [1, 3]]
Output: [true, true]
Explanation: All subarrays of the given array are mountain.
Constraints:
1 <= arr.size(), queries.size() <= 105
1 <= arr[i] <= 106
0 <= l <= r < arr.size()
*/
class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
         int n = arr.size();
    if (n == 0) return vector<bool>(queries.size(), false);

    vector<int> end_inc(n);
    end_inc[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] <= arr[i + 1]) {
            end_inc[i] = end_inc[i + 1];
        } else {
            end_inc[i] = i;
        }
    }

    vector<int> start_dec(n);
    start_dec[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i - 1] >= arr[i]) {
            start_dec[i] = start_dec[i - 1];
        } else {
            start_dec[i] = i;
        }
    }

    vector<bool> result;
    result.reserve(queries.size());

    for (const auto& q : queries) {
        int l = q[0];
        int r = q[1];
        int peak_end = end_inc[l];
        int valley_start = start_dec[r];
        result.push_back(peak_end >= valley_start);
    }

    return result;
        
    }
};