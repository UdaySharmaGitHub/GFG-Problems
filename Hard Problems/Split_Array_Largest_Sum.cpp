/*
Split Array Largest Sum
Given an array arr[] and an integer k, divide the array into k contiguous subarrays such that the maximum sum among these subarrays is minimized. Find this minimum possible maximum sum.

Examples:

Input: arr[] = [1, 2, 3, 4], k = 3
Output: 4
Explanation: Optimal Split is [1, 2], [3], [4]. Maximum sum of all subarrays is 4, which is minimum possible for 3 splits.
Input: arr[] = [1, 1, 2], k = 2
Output: 2
Explanation: Splitting the array as [1, 1] and [2] is optimal. This results in a maximum sum subarray of 2.
Constraints:
1 ≤ k ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
*/
/*
    Time Complexity: O(n*log(sum))
    Auxiliary Space: O(1)
*/
class Solution {
  public:
    bool f(int sum , vector<int>& arr, int k){
       int s = 0 ; 
       for(int i : arr){
           s += i ;
           if(s > sum){
               k -- ; s = i ;
           }
       }
       return (k > 0 && s <= sum) ;
    }
    
    int splitArray(vector<int>& arr, int k) {
        int s = *max_element(arr.begin(), arr.end()) ; 
        int e = accumulate(arr.begin() , arr.end() , 0) ;
        int ans = -1 ;
        while(s <= e){
            int mid = s + (e-s) / 2 ;
            if(f(mid , arr , k)){
                ans = mid ;
                e = mid - 1 ;
            }
            else{
                s = mid + 1 ;
            }
        }
        return ans ;
    }
};