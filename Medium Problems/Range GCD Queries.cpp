/*
Range GCD Queries
Given an integer array arr[] and a 2D array queries[][] containing q queries, where each query is one of the following two types:

Type 1: [0, l, r] -> Return the GCD of all elements in the range [l, r] (both inclusive).
Type 2: [1, index, value] -> Update arr[index] to value.
Return an array containing the answers to all Type 1 queries in the order they appear in queries[][].

Note: Use 0-based indexing.

Examples:

Input: arr[] = [2, 3, 4, 6, 8, 16], q = 3, queries[][] = [[0, 0, 2], [1, 3, 8], [0, 2, 5]]
Output: [1, 4]
Explanation: Initially, arr[] = [2, 3, 4, 6, 8, 16].
Query [0, 0, 2]: Find the GCD of the subarray arr[0...2] = [2, 3, 4]. The GCD is 1.
Query [1, 3, 8]: Update arr[3] from 6 to 8. The array becomes [2, 3, 4, 8, 8, 16].
Query [0, 2, 5]: Find the GCD of the subarray arr[2...5] = [4, 8, 8, 16]. The GCD is 4.
Therefore, the answers to all Type 0 queries are [1, 4].
Input: arr[] = [12, 18, 24, 30, 36], q = 4, queries[][] = [[0, 1, 3], [1, 2, 15], [0, 0, 2], [0, 2, 4]]
Output: [6, 3, 3]
Explanation: Initially, arr[] = [12, 18, 24, 30, 36].
Query [0, 1, 3]: Find the GCD of the subarray arr[1...3] = [18, 24, 30]. The GCD is 6.
Query [1, 2, 15]: Update arr[2] from 24 to 15. The array becomes [12, 18, 15, 30, 36].
Query [0, 0, 2]: Find the GCD of the subarray arr[0...2] = [12, 18, 15]. The GCD is 3.
Query [0, 2, 4]: Find the GCD of the subarray arr[2...4] = [15, 30, 36]. The GCD is 3.
Therefore, the answers to all Type 0 queries are [6, 3, 3].
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ q ≤ 105
0 ≤ l, r, index ≤ arr.size()-1
1 ≤ arr[i], value ≤ 105
*/
class Solution {
  public:
    vector<int> tree;

       int gcd(int a, int b) {
           while (b != 0) {
               int t = a % b;
               a = b;
               b = t;
           }
           return a;
       }

       void build(vector<int>& arr, int node, int l, int r) {
           if (l == r) {
               tree[node] = arr[l];
               return;
           }

           int mid = (l + r) / 2;

           build(arr, 2 * node + 1, l, mid);
           build(arr, 2 * node + 2, mid + 1, r);

           tree[node] = gcd(tree[2 * node + 1],
                             tree[2 * node + 2]);
       }

       int query(int node, int l, int r, int ql, int qr) {
           if (qr < l || r < ql)
               return 0;

           if (ql <= l && r <= qr)
               return tree[node];

           int mid = (l + r) / 2;

           return gcd(
               query(2 * node + 1, l, mid, ql, qr),
               query(2 * node + 2, mid + 1, r, ql, qr)
           );
       }

       void update(int node, int l, int r, int index, int value) {
           if (l == r) {
               tree[node] = value;
               return;
           }

           int mid = (l + r) / 2;

           if (index <= mid)
               update(2 * node + 1, l, mid, index, value);
           else
               update(2 * node + 2, mid + 1, r, index, value);

           tree[node] = gcd(tree[2 * node + 1],
                             tree[2 * node + 2]);
       }

       vector<int> processQueries(vector<int>& arr,
                                  vector<vector<int>>& queries) {
           int n = arr.size();

           tree.assign(4 * n, 0);

           build(arr, 0, 0, n - 1);

           vector<int> ans;

           for (auto &q : queries) {

               if (q[0] == 0) {
                   // Type 0: GCD query
                   int l = q[1];
                   int r = q[2];

                   ans.push_back(
                       query(0, 0, n - 1, l, r)
                   );
               }
               else {
                   // Type 1: Update
                   int index = q[1];
                   int value = q[2];

                   arr[index] = value;

                   update(0, 0, n - 1, index, value);
               }
           }

           return ans;
       }
};