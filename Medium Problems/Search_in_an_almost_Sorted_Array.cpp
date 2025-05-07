/*
Search in an almost Sorted Array

Given a sorted integer array arr[] consisting of distinct elements, where some elements of the array are moved to either of the adjacent positions, i.e. arr[i] may be present at arr[i-1] or arr[i+1].
Given an integer target.  You have to return the index ( 0-based ) of the target in the array. If target is not present return -1.

Examples:

Input: arr[] = [10, 3, 40, 20, 50, 80, 70], target = 40
Output: 2
Explanation: Index of 40 in the given array is 2.
Input: arr[] = [10, 3, 40, 20, 50, 80, 70], target = 90
Output: -1
Explanation: 90 is not present in the array.
Input: arr[] = [-20], target = -20
Output: 0
Explanation: -20 is the only element present in the array.
Constraints:
1 <= arr.size() <= 105
-109 <= arr[i] <= 109
*/

/*
    Approach - 1
Time Complexity: O(log(N))
Space Complexity: O(1)
*/
int findTarget(vector<int>& arr, int target) {
    // code here
    int n=arr.size();
    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==target) return mid;
        if(mid-1>=0 && arr[mid-1]==target) return mid-1;
        if(mid+1<n && arr[mid+1]==target) return mid+1;
        
        else if(arr[mid]<target) l=mid+1;
        else r=mid-1;
    }
    
    return -1;
}


/*
    Approach - 2
Time Complexity: O(N)
Space Complexity: O(1)
*/
// User function Template for C++
class Solution {
    public:
      int findTarget(vector<int>& arr, int target) {
          // code here
          for(int i=0;i<arr.size();i++){
              if(arr[i] == target) return i;
          }
          return -1;
      }
  };