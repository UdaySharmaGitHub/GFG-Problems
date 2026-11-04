/*
XOR of All Subarray XORs
Given an integer array arr[], find the XOR of the XOR values of all possible non-empty subarrays of the array.

Examples:

Input: arr[] = [1, 2, 3] 
Output: 2
Explanation:
xor[1] = 1
xor[1, 2] = 3
xor[2, 3] = 1
xor[1, 2, 3] = 0
xor[2] = 2
xor[3] = 3
Result: 1 ^ 3 ^ 1 ^ 0 ^ 2 ^ 3 = 2
Input: arr[] = [1, 2]
Output: 0
Explanation:
xor[1] = 1
xor[1, 2] = 3
xor[2] = 2
Result: 1 ^ 3 ^ 2 = 0
Constraints:

1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 109

*/
class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
          int len = arr.size();
        int ans = 0;
        
        for(int i=0;i<arr.size();i++){
            int val = (i+1)*(len-i);
            if(val%2){
                ans^=arr[i];
            }
            
        }
        return ans;
    }
};