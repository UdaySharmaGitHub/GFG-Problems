/*
Longest Subarray with Majority Greater than K
Given an array arr[] and an integer k, the task is to find the length of longest subarray in which the count of elements greater than k is more than the count of elements less than or equal to k.

Examples:

Input: arr[] = [1, 2, 3, 4, 1], k = 2
Output: 3
Explanation: The subarray [2, 3, 4] or [3, 4, 1] satisfy the given condition, and there is no subarray of length 4 or 5 which will hold the given condition, so the answer is 3.
Input: arr[] = [6, 5, 3, 4], k = 2
Output: 4
Explanation: In the subarray [6, 5, 3, 4], there are 4 elements > 2 and 0 elements <= 2, so it is the longest subarray.
Constraints:
1 <= arr.size() <= 106
1 <= arr[i] <= 106
0 <= k <= 106
*/
// User function Template for C++
class Solution {
    public:
      int longestSubarray(vector<int> &arr, int k) {
          // Code here
          int c=0,ans=0;
          unordered_map<int,int>m;
          for(int i=0;i<arr.size();i++) {
              if(arr[i]<=k) c--;
              else c++;
              if(c<=0 and !m.count(c)) m[c]=i;
              if(c<=0 and m.count(c-1))ans=max(ans,i-m[c-1]);
              if(c>0) ans=i+1;
          }
          return ans;
      }
  };