/*
Max Product Subsequence of Size K
Given an array arr[] of integers and an integer k, find a subsequence of size k whose product is maximum among all possible subsequences of size k. Return the maximum product that can be obtained.

Examples:

Input: arr[] = [1, 2, 0, 3], k = 2
Output: 6
Explanation: Subsequence containing elements {2, 3} gives maximum product: 2*3 = 6
Input: arr[] = [1, 2, -1, -3, -6, 4], k = 4
Output: 144
Explanation: Subsequence containing {2, -3, -6, 4} gives maximum product: 2*(-3)*(-6)*4 = 144
Constraints:

arr.size() ≤ 30
-10 ≤ arr[i] ≤ 10
1 ≤ k ≤ arr.size()
*/
class Solution {
  public:
    int maxProduct(vector<int> &arr, int k) {
        // code here
        int n = arr.size();

            // Sort the array.
            sort(arr.begin(), arr.end());

            // Store the maximum product.
            int product = 1;

            // If the largest element is 0 and k is odd.
            if (arr[n - 1] == 0 && (k & 1))
            {
                return 0;
            }

            // If all elements are non-positive and k is odd.
            if (arr[n - 1] <= 0 && (k & 1))
            {

                for (int i = n - 1; i >= n - k; i--)
                {
                    product *= arr[i];
                }

                return product;
            }

            int left = 0;
            int right = n - 1;

            // Include the largest positive element if k is odd.
            if (k & 1)
            {
                product *= arr[right];
                right--;
                k--;
            }

            // Process remaining elements in pairs.
            k /= 2;

            for (int i = 0; i < k; i++)
            {

                int leftProduct = arr[left] * arr[left + 1];
                int rightProduct = arr[right] * arr[right - 1];

                // Choose the better pair.
                if (leftProduct > rightProduct)
                {
                    product *= leftProduct;
                    left += 2;
                }
                else
                {
                    product *= rightProduct;
                    right -= 2;
                }
            }

            // Return the maximum product.
            return product;
    }
};