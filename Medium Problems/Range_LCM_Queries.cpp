/*
Range LCM Queries
Given an array arr[]  and a list of queries queries[][]. Each query can be one of the following two types:

Update Query: [1, index, value] --> Update the element at position index in the array to the given value.
Range Query: [2, L, R] --> Compute and return the Least Common Multiple (LCM) of all elements in the subarray from index L to R (inclusive).
Process all queries sequentially and return a list containing the results of all Type 2 queries.

Note: All operations follow 0-based indexing.

Examples :

Input: arr[] = [2, 3, 4, 6, 8, 16], queries[][] = [[2, 0, 2], [1, 3, 8], [2, 2, 5]]
Output: [12, 16]
Explanation: The queries are processed sequentially, updating the array when required.
[2, 0, 2]: LCM of [2, 3, 4] = 12
[1, 3, 8]: array becomes [2, 3, 4, 8, 8, 16]
[2, 2, 5]: LCM of [4, 8, 8, 16] = 16
Input: arr[] = [1, 2, 3, 4],  queries[][] = [[2, 0, 3], [1, 0, 5], [2, 0, 1]]
Output: [12, 10]
Explanation: The queries are processed sequentially, updating the array when required.
[2, 0, 3]: LCM of [1, 2, 3, 4] = 12
[1, 0, 5]: array becomes [5, 2, 3, 4]
[2, 0, 1]: LCM of [5, 2] = 10
Constraints:
1 ≤ arr.size() ≤ 104
1 ≤ queries.size() ≤ 105
0 ≤ L ≤ R ≤ arr.size() - 1
0 ≤ index ≤ arr.size() - 1
1 ≤ arr[i], value ≤ 104
*/
class Solution {
  long long lcm(long long a, long long b) {
        return ((a * b) / __gcd(a, b));
    }
    void build(int x, int lx, int rx, vector<int> &arr, vector<long long> &seg) {
        if(rx - lx == 1) {
            if(lx < arr.size()) seg[x] = arr[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m, arr, seg);
        build(2 * x + 2, m, rx, arr, seg);
        seg[x] = lcm(seg[2 * x + 1], seg[2 * x + 2]);
    }
    void update(int x, int lx, int rx, int &idx, int &val, vector<long long> &seg) {
        if(rx - lx == 1) {
            seg[x] = val;
            return;
        }
        int m = (lx + rx) / 2;
        if(idx < m) update(2 * x + 1, lx, m, idx, val, seg);
        else update(2 * x + 2, m, rx, idx, val, seg);
        seg[x] = lcm(seg[2 * x + 1], seg[2 * x + 2]);
    }
    long long query(int x, int lx, int rx, int l, int r, vector<long long> &seg) {
        if(rx <= l || lx >= r) return 1;
        if(lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        return lcm(query(2 * x + 1, lx, m, l, r, seg), query(2 * x + 2, m, rx, l, r, seg));
    }
  public:
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size(), q = queries.size();
        vector<long long> seg(4 * n, 1), ans;
        build(0, 0, n, arr, seg);
        for(int i = 0; i < q; i++) {
            if(queries[i][0] == 1) update(0, 0, n, queries[i][1], queries[i][2], seg);
            else ans.push_back(query(0, 0, n, queries[i][1], queries[i][2] + 1, seg));
        }
        return ans;
    }
};