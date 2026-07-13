/*
Rearrange the Array
Consider an array a[] = [1, 2, 3, ..., n] and a permutation b[] of size n containing all integers from 1 to n exactly once.

The array b[] defines a rearrangement operation.
During a single operation, every element at position i in a[] moves to position b[i] (1-based indexing).
We must do at least one operation on a[].
Find the minimum number of operations required for all elements to return to their original positions simultaneously, i.e., for a[] to become: [1, 2, 3, ..., n] again.

Note:  The answer can be large, so return the answer modulo 10^9+7.

Examples:

Input: b[] = [1, 2, 3]
Output: 1
Explanation: Initially, a[] = [1, 2, 3] and b[] = [1, 2, 3]
After one operation:
a[1] = 1 goes to position 1 as b[1] = 1.
a[2] = 2 goes to position 2.
a[3] = 3 goes to position 3.
so, now a[] becomes [1, 2, 3].
All elements remain at their original positions. Hence, the answer is 1.
Input: b[] = [2, 3, 1, 5, 4]
Output: 6
Explanation: The sequence of arrays obtained after each operation is:
Initially : [1, 2, 3, 4, 5]
1 : [3, 1, 2, 5, 4]
2 : [2, 3, 1, 4, 5]
3 : [1, 2, 3, 5, 4]
4 : [3, 1, 2, 4, 5]
5 : [2, 3, 1, 5, 4]
6 : [1, 2, 3, 4, 5]
After 6 operations, all elements return to their original positions simultaneously. Therefore, the answer is 6.
Constraints:
1 ≤ n ≤ 104
a.size() = b.size() = n
b[] is a permutation of integers from 1 to n.
*/
class Solution {
public:
    int minOperations(vector<int> &b) {
        const int MOD = 1000000007;
        int n = b.size();

        vector<int> vis(n, 0);

        unordered_map<int, int> mxExp;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            int cur = i;
            int len = 0;

            while (!vis[cur]) {
                vis[cur] = 1;
                cur = b[cur] - 1;
                len++;
            }

            int x = len;
            for (int p = 2; p * p <= x; p++) {
                if (x % p == 0) {
                    int cnt = 0;
                    while (x % p == 0) {
                        x /= p;
                        cnt++;
                    }
                    mxExp[p] = max(mxExp[p], cnt);
                }
            }

            if (x > 1)
                mxExp[x] = max(mxExp[x], 1);
        }

        long long ans = 1;

        for (auto &it : mxExp) {
            long long base = it.first;
            int exp = it.second;

            while (exp--) {
                ans = (ans * base) % MOD;
            }
        }

        return (int)ans;
    }
};