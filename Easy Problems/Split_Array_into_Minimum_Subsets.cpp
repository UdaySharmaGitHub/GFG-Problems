/*
Split Array into Minimum Subsets
Given an array arr[] of distinct positive numbers. Split the array into the minimum number of subsets (or subsequences) such that each subset contains consecutive numbers.

Examples:

Input: arr[] = [100, 56, 5, 6, 102, 58, 101, 57, 7, 103, 59]
Output: 3
Explanation: [5, 6, 7], [56, 57, 58, 59], [100, 101, 102, 103] are 3 subsequences in which numbers are consecutive.
Input: arr[] = [10, 100, 105]
Output: 3
Explanation: [10], [100] and [105] are 3 subset in which numbers are consecutive.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 109

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)
*/
/*
    APROACH: using Inbiult sort function and then iterate through the array to find the minimum number of subsets.
    1. Sort the array.
    2. Initialize a counter to 1 and a variable to keep track of the last number in the current subset.
    3. Iterate through the sorted array and check if the current number is consecutive to the last number in the current subset.
    4. If it is, update the last number in the current subset. If it is not, increment the counter and update the last number in the current subset.
    5. Return the counter as the minimum number of subsets

    Time Complexity: O(nlogn) for sorting the array and O(n) for iterating through the array, so overall O(nlogn).
    Space Complexity: O(1) as we are using a constant amount of extra space.
*/
class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // Your code here
        sort(arr.begin(),arr.end());
        int ans = 1;
        for(int i = 1;i<arr.size();i++){
            if(arr[i]!=arr[i-1]+1) ans++;
        }
        return ans;
    }
};
/* --------------------------------------------------------------------------------------------------------- */
class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int count = 1 ,compare = arr[0];
        for(int i =1 ; i<arr.size();i++){
            if(compare+1 == arr[i]){compare= arr[i];}
            else {count++;compare = arr[i];}
        }
        
        return count; 
    }
};
