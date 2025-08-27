/*
Maximize the minimum difference between k elements
Given an array arr[] of integers and an integer k, select k elements from the array such that the minimum absolute difference between any two of the selected elements is maximized. Return this maximum possible minimum difference.
Examples:
Input: arr[] = [2, 6, 2, 5], k = 3
Output: 1
Explanation: 3 elements out of 4 elements are to be selected with a minimum difference as large as possible. Selecting 2, 2, 5 will result in minimum difference as 0. Selecting 2, 5, 6 will result in minimum difference as 6 - 5 = 1.
Input: arr[] = [1, 4, 9, 0, 2, 13, 3], k = 4
Output: 4
Explanation: Selecting 0, 4, 9, 13 will result in minimum difference of 4, which is the largest minimum difference possible.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 106
2 ≤ k ≤ arr.size() 
*/
class Solution {
  public:
      int canPick(vector<int>&arr,int mid)
  {
      int last=arr[0];
      int k=1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]-last<mid)
            {
                continue;
            }
            else
            {
                k+=1;
                last=arr[i];
            }
        }
        return k;
  }
    int maxMinDiff(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans;
        int l=0,h=arr[n-1]-arr[0];
        while(l<=h)
        {
            int mid=(l+h)/2;
            int ch=canPick(arr,mid);
            if(ch>=k)
            {
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};
