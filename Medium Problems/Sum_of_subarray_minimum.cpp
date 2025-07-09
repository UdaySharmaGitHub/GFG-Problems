/*
Sum of subarray minimum
Given an array arr[] of positive integers, find the total sum of the minimum elements of every possible subarrays.
Note: It is guaranteed that the total sum will fit within a 32-bit unsigned integer
Examples:
Input: arr[] = [3, 1, 2, 4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3, 1], [1, 2], [2, 4], [3, 1, 2], [1, 2, 4], [3, 1, 2, 4]. Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum of all these is 17.
Input: arr[] = [71, 55, 82, 55]
Output: 593
Explanation: The sum of the minimum of all the subarrays is 593.
Constraints:
1 ≤ arr.size() ≤ 3*104
1 ≤ arr[i] ≤ 103
*/
class Solution {
  public:
   vector<int> nse(vector<int> &arr){
        int n=arr.size();
        stack<int> sk;
        sk.push(n);
        vector<int> ans(n,n);
        for(int i=n-1;i>=0;i--){
            while(sk.size()>1 && arr[i] <= arr[sk.top()])    sk.pop();
            ans[i] = sk.top();
            sk.push(i);
        }
        return ans;
    }
    vector<int> pse(vector<int> &arr){
        int n=arr.size();
        stack<int> sk;
        sk.push(-1);
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            while(sk.size()>1 && arr[i] < arr[sk.top()])  sk.pop();
            ans[i] = sk.top();
            sk.push(i);
        }
        return ans;
    }
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> ns = nse(arr),ps = pse(arr);
        int ans = 0;
        for(int i=0;i<n;i++){
            int sz = (ns[i]-i)*(i-ps[i]);
            ans += sz*arr[i];
        }
        return ans;
    }
};