/*
Binary Searchable Count

Given an array arr[] consisting of n distinct integers, find the maximum count of integers that are binary searchable in the given array. Binary searchable elements are determined using the standard Binary Search implementation described below.

Initially l is 0 and r is size of array - 1 
while(l <= r), compute mid as floor of (l + r)/2 and compare with mid.
If the target element is same as mid, return true. Else if mid is smaller, change l = mid + 1, else change r = mid - 1.
For example:

In arr[] = [2, 1, 3, 4, 6, 5], the element 5 is not binary searchable. During Binary Search, the search eventually reaches the subarray containing 6, and since 6 > 5, the search moves left (r = mid - 1), causing the element 5 to be skipped.
In arr[] = [2, 1, 3, 4, 5, 6], the element 5 is binary searchable because the standard Binary Search process eventually reaches and finds 5.
Examples:

Input: arr[] = [1, 3, 2]
Output: 2
Explanation: arr[0], arr[1] can be found.
Input: arr[] = [2, 1, 3, 5, 4, 6]
Output: 4
Explanation: arr[0], arr[2], arr[4], arr[5] can be found.
Constraints:
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 105
*/
class Solution {
  public:
    int dfs(int i,int j,int left,int right,vector<int>& nums){
        if(i>=j){
            if(nums[i]<right&&nums[i]>left) return 1;
            return 0;
        }
        int mid=i+(j-i)/2;
        int ans=0;
        if(nums[mid]>left&&nums[mid]<right) ans++;
        ans+=dfs(i,mid-1,left,min(right,nums[mid]),nums);
        ans+=dfs(mid+1,j,max(left,nums[mid]),right,nums);
        return ans;
    }
    int binarySearchable(vector<int>& arr) {
        // code here
        return dfs(0,arr.size()-1,INT_MIN,INT_MAX,arr);
    }
};
