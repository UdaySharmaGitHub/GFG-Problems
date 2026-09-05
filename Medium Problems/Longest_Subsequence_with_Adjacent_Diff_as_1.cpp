/*
Longest Subsequence with Adjacent Diff as 1
Given an array arr[] with n elements. find the longest subsequence such that the absolute difference between adjacent elements is one.

Examples:

Input : arr[] = [10, 9, 4, 5, 4, 8, 6]
Output : 3
Explanation: Longest subsequences with difference 1 are [10, 9, 8], [4, 5, 4] and [4, 5, 6]. 
Input : arr[] = [1, 2, 3, 2, 3, 7, 2, 1]
Output : 7
Explanation:  Longest subsequences with difference 1 is [1, 2, 3, 2, 3, 2, 1]. 
Constraints:

1 ≤ arr.size(), arr[i] ≤ 106
*/
class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        // code here
    unordered_map<int,int>mp;
           int ans=0;
           int n=arr.size();
           for(int i=0;i<n;i++){
               mp[arr[i]]=max(mp[arr[i]-1],mp[arr[i]+1])+1;
               ans=max(ans,mp[arr[i]]);
           }
           return ans;
       }
};