/*
Count Pairs Divisible By K
Given an array arr[] and positive integer k, count total number of pairs in the array whose sum is divisible by k.

Examples:

Input :  arr[] = [2, 2, 1, 7, 5, 3], k = 4
Output : 5
Explanation : There are five pairs possible whose sum is divisible by '4' i.e., (2, 2), (1, 7), (7, 5), (1, 3) and (5, 3).
Input : arr[] = [5, 9, 36, 74, 52, 31, 42], k = 3
Output : 7 
Explanation : There are seven pairs whose sum is divisible by 3, i.e, (9, 36), (9,42), (74, 52), (36, 42), (74, 31), (31, 5) and (5, 52).
Constraints :
1 ≤ |arr| ≤ 5*104
1 ≤ arr[i] ≤ 106
1 ≤ k ≤ 5*104
*/
/*
    APPRAOCH:
    Steps:
    1. Create a vector rem of size k and initialize it with 0.
    2. Iterate through the array and for each element, calculate its remainder when divided by k.
    3. If the remainder is 0, add the count of elements with remainder 0 to the answer.
    4. If the remainder is not 0, add the count of elements with remainder k - remainder to the answer.
    5. Increment the count of the current remainder in the rem vector.
    6. Return the final answer.

    Time Complexity: O(n), where n is the size of the array.
    Space Complexity: O(k), where k is the given integer.
*/
class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
    int ans=0;
        vector<int>rem(k,0);
        for(int i=0;i<arr.size();i++){
            int reminder=arr[i]%k;
            if(reminder==0)
                ans+=rem[0];
            else
                ans+=rem[k-reminder];
            rem[reminder]++;
        }
        return ans;
    }
};