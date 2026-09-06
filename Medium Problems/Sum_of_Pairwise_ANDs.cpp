/*
Sum of Pairwise ANDs
Given an array arr[] of integers, calculate the sum of bitwise AND for all pairs of elements such that the first index is less than the second index.

Examples:

Input: arr = [5, 10, 15]
Output: 15
Explanation: 
Consider all pairs of elements where the first index is less than the second index (i < j).
For the array [5, 10, 15], the valid pairs are:
(5, 10)  -> 5 & 10  = 0
(5, 15)  -> 5 & 15  = 5
(10, 15) -> 10 & 15 = 10
Now, add all these results: 0 + 5 + 10 = 15
So, the total sum of bitwise ANDs for all such pairs is 15
Input: arr = [10, 20, 30, 40]
Output: 46
Explanation: 
Consider all pairs of elements where the first index is less than the second index (i < j).
For the array [10, 20, 30, 40], the valid pairs are:
(10, 20) -> 10 & 20 = 0
(10, 30) -> 10 & 30 = 10
(10, 40) -> 10 & 40 = 8
(20, 30) -> 20 & 30 = 20
(20, 40) -> 20 & 40 = 0
(30, 40) -> 30 & 40 = 8
Now, add all these results: 0 + 10 + 8 + 20 + 0 + 8 = 46
So, the total sum of bitwise ANDs for all such pairs is 46
Constraints:

1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 108
*/
/*
    APPRACH: [Efficient Approach] Using Bit Manipulation – O(32 * n) Time and O(1) Space
    Steps:
    - Iterate over all 32 bit positions and count how many elements have the current bit set
    - For each bit, compute number of valid pairs using k(k−1)/2 where k is count of set bits
    - Multiply the pair count with the value of that bit and add it to the result
    - Return the final accumulated sum after processing all bits

    Time Complexity: O(32*N);
    Space Complexity: O(1)

*/
class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        // code here
        long long ans = 0; 

            int n = arr.size();

            // Traverse over all bits
            for (int i = 0; i < 32; i++) {

                // Count number of elements with i'th bit set
                long long k = 0; 
                for (int j = 0; j < n; j++)
                    if ((arr[j] & (1LL << i)))
                        k++;

                // There are k set bits, means k(k-1)/2 pairs.
                // Every pair adds 2^i to the answer. Therefore,
                // we add "2^i * [k*(k-1)/2]" to the answer.
                ans += (1LL << i) * (k * (k - 1) / 2);
            }

            return ans;
    }
};


/*
    APPROACH: [Naive Approach] Using Nested Loops – O(n²) Time and O(1) Space
    Steps:
    - Initialize a variable to store the final sum and get the size of the array
    - Use two loops where the first loop fixes one element and the second loop forms pairs with remaining elements
    - For each pair, compute bitwise AND and add it to the sum
    - Return the accumulated sum after processing all pairs 

    Time Complexity: O(N*N);
    Space Complexity: O(1);

*/
class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        // code here
        long long  res = 0 ;
        for(int i =0 ;i<arr.size();i++){
            for(int j= i+1;j<arr.size();j++){
                res+= (arr[i]&arr[j]);
            }
        }
        return res;
    }
};