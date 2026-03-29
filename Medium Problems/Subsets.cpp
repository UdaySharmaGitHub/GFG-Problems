/*
Given an array arr[] of distinct positive integers, your task is to find all its subsets.
Note: You can return the subsets in any order, the driver code will print them in sorted order.
Examples:
Input: arr[] = [1, 2, 3]
Output: [[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]
Explanation: 
The subsets of [1, 2, 3] in lexicographical order are:
[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]
Input: arr[] = [2, 4]
Output: [[], [2], [2, 4], [4]]
Explanation:
The subsets of [2, 4] in lexicographical order are:
[], [2], [2, 4], [4]
Constraints :
1 ≤ arr.size() ≤ 10
1 ≤ arr[i] ≤ 103
*/
/*
    Approach -1 Using Recursion
    Time Complexity: O(n * 2n), generating all subsets requires 2n recursive calls, and copying each subset of size up to n takes O(n) time.
    Auxiliary Space: O(n), recursion stack and temporary subset use at most n space at a time.
*/
class Solution {
  public:
  void totalSubSet(vector<int> arr,int idx,vector<vector<int>>&res,vector<int>subset){
      if(idx>=arr.size()){
          res.push_back(subset);
          return ;
      }
      totalSubSet(arr,idx+1,res,subset);
      subset.push_back(arr[idx]);
      totalSubSet(arr,idx+1,res,subset);
  }
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        vector<vector<int>> res;
        vector<int> subset;
        int idx =0;
        totalSubSet(arr,idx,res,subset);
        return res;
    }
};
/*
    Using Bit Manipulation
    Approach -2 Optimized Apprach
    Time Complexity: O(n * 2n), generating all subsets requires 2n recursive calls, and copying each subset of size up to n takes O(n) time.
    Auxiliary Space: O(n), recursion stack and temporary subset use at most n space at a time.
*/
/*
    Example: Consider an array [A, B]:
    0 → 00 → A excluded, B excluded → []
    1 → 01 → A excluded, B included → [B]
    2 → 10 → A included, B excluded → [A]
    3 → 11 → A included, B included → [A, B]
Time Complexity: O(n * 2n), generating all subsets requires 2n recursive calls, and copying each subset of size up to n takes O(n) time.
Auxiliary Space: O(n), temporary subset at most n space at a time
*/
class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
       int n = arr.size();
       vector<vector<int>> res;
       for(int i =0;i<(1<<n);i++){
           vector<int> subset;
           for(int j=0;j<n;j++){
               if((i&(1<<j))!=0) subset.push_back(arr[j]);
           }
           res.push_back(subset);
   }        
       return res;      
    }
};