/*
Sum of XOR of all pairs
Given an integer array arr[] of size n, compute the sum of the bitwise XOR for all distinct pairs of elements. That is, consider every pair of indices (i, j) such that 0 ≤ i < j < n, and calculate the total sum of (arr[i] XOR arr[j]) over all such pairs.

Examples :

Input : arr[] = [7, 3, 5]
Output : 12
Explanation: 
All pairs (i, j) such that i < j and their XOR values are:
7 ^ 3 = 4
7 ^ 5 = 2
3 ^ 5 = 6
Sum of all XOR values = 4 + 2 + 6 = 12.
Input : arr[] = [5, 9, 7, 6] 
Output : 47
Explanation:
All pairs (i, j) such that i < j and their XOR values are:
5 ^ 9 = 12
5 ^ 7 = 2
5 ^ 6 = 3
9 ^ 7 = 14
9 ^ 6 = 15
7 ^ 6 = 1
Sum of all XOR values = 12 + 2 + 3 + 14 + 15 + 1 = 47.
Input : arr[] = [10] 
Output : 0
Explanation: Since there are no pairs, sum is 0.
Constraints
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 105
*/
/*
    APPROACH:
    steps:
    1. We will iterate through each bit position from 0 to 31 (assuming 32-bit integers).
    2. For each bit position, we will count the number of elements in the array that have that bit set (1) and the number of elements that do not have that bit set (0).
    3. The contribution of that bit to the total XOR sum can be calculated as the product of the count of elements with that bit set and the count of elements without that bit set, multiplied by the value of that bit (which is 2^i).
    4. We will accumulate the contributions from all bit positions to get the final sum of XOR of all pairs.

    Time Complexity: O(n * 32) = O(n)
    Space Complexity: O(1)
*/
class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        long long int sum = 0 ;
        for(int i =0 ; i<32;i++){
            int zc = 0,oc= 0 ;
            for(int j =0;j<arr.size();j++){
                if ((arr[j] >> i) & 1)
                    oc++;
                else
                    zc++;
            }
            sum+= (long)oc*zc*(1<<i);
        }
        return sum;
    }
};
