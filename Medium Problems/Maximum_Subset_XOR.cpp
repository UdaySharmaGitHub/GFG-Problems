/*
Maximum Subset XOR
Given an array arr[], choose any subset of elements (possibly all elements) such that the XOR of the chosen elements is maximized.

Examples:

Input : arr[] = [2, 4, 5]
Output: 7
Explanation: The subset {2, 5} has the maximum XOR value.
Input : arr[] = [9, 8, 5]
Output: 13
Explanation: The subset {8, 5} has the maximum XOR value.
Constraints:

1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106
*/
class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        int n = arr.size();

        int index = 0;

        for (int bit = 31; bit >= 0; bit--) {

            int maxIndex = -1;

            for (int i = index; i < n; i++) {
                if (arr[i] & (1 << bit)) {
                    maxIndex = i;
                    break;
                }
            }

            if (maxIndex == -1)
                continue;

            swap(arr[index], arr[maxIndex]);

            for (int i = 0; i < n; i++) {
                if (i != index && (arr[i] & (1 << bit))) {
                    arr[i] ^= arr[index];
                }
            }

            index++;
        }

        int ans = 0;

        for (int i = 0; i < index; i++) {
            ans = max(ans, ans ^ arr[i]);
        }

        return ans;
    }
};