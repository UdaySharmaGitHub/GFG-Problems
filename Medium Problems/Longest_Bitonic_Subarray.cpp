/*
Longest Bitonic Subarray
Given an array arr[] of size n containing positive integers, return the maximum length of the bitonic subarray.

A subarray arr[i...j] is considered bitonic if its elements first monotonically increase, and then monotonically decrease. Formally, there exists and index k (where i <= k <= j) such that:

arr[i] <= arr[i+1] <= . . . <= arr[k] 
arr[k] >= arr[k+1] >= . . . >= arr[j]
Examples: 

Input: arr[] = [12, 4, 78, 90, 45, 23]
Output: 5
Explanation: The longest bitonic subarray is [4, 78, 90, 45, 23], it starts increasing at 4, peaks at 90, and decreases to 23, giving length of 5.
Input: arr[] = [10, 20, 30, 40]
Output: 4
Explanation: The array [10, 20, 30, 40] is striclty increasing with no decreasing part, so longest bitonic subarray is the entire array itself, giving a length of 4.
Input: arr[] = [10, 10, 10, 10]
Output: 4
Constraints:
1 ≤  n ≤ 106
1 ≤ arr[i] ≤ 106
*/
class Solution {
  public:
    int bitonic(vector<int> &arr) {
        // code here
        if(arr.size()==0) return 0;
        if(arr.size()==1) return 1;
        
        int maxLen =0 ,start = 0 , nextStart = 0 , j = 0 ;
        while(j<arr.size()-1){
            nextStart  = j;    
            while(j<arr.size()-1 && arr[j]<=arr[j+1]) j++;
            
            while(j<arr.size()-1 && arr[j]>=arr[j+1]){
                if(j<arr.size()-1 && arr[j]>arr[j+1])            nextStart = j+1;
                
                j++;
            }
            
            maxLen = max(maxLen,j-start+1);
            start = nextStart;
        }
        return maxLen;
    }
};
