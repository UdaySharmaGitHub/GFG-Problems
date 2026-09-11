/*
Values with Equal Array Remainders
Given an integer array arr[], count the number of positive integers k such that all elements of the array leave the same remainder when divided by k.

If there are infinitely many such values of k, return -1.

Examples:

Input: arr[] = [38, 6, 34]
Output: 3
Explanation: 
The values of k for which all elements leave the same remainder when divided by k are 1, 2, and 4.
For k = 1, all elements leave remainder 0.
For k = 2, all elements leave remainder 0.
For k = 4, all elements leave remainder 2.
No other positive integer satisfies the required condition. Hence, the answer is 3.
Input: arr[] = [3, 2]
Output: 1
Explanation: 
The only positive integer for which both elements leave the same remainder is 1, 
since both numbers leave remainder 0 when divided by 1.
Input: arr[] = [5, 5, 5]
Output: -1
Explanation: 
All elements in the array are equal. Therefore, for every positive integer k, 
all elements leave the same remainder when divided by k.
Since there are infinitely many such values of k, the answer is -1.
Constraints:

1 ≤ arr.size(), arr[i] ≤ 105
*/
class Solution {
  public:
    int sameMod(vector<int> &arr) {
        // code here
    int n = arr.size();
			int result = 0;
			int k = 1;
			bool allEqual = true;
			for (int i = 0; i<n; ++i) {
				k = max(arr[i], k);
				if (i>0 && arr[i] != arr[i - 1])allEqual = false;
			}
			if (allEqual)return - 1;
			for (int i = 1; i <= k; ++i) {
				int prevRemainder = -1;
				bool equalRemainder = true;
				for (int j = 0; j<n; ++j) {
					int remainders = arr[j]%i;
					if (prevRemainder == -1)prevRemainder = remainders;
					else {
						if (prevRemainder != remainders) {
							equalRemainder = false;
							break;
						}
					}
				}
				if (equalRemainder)result++;
			}
			return result;
		}
};