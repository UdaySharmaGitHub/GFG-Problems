/*
Bitonic Point
Given an array of integers arr[] that is first strictly increasing and then maybe strictly decreasing, find the bitonic point, that is the maximum element in the array.
Bitonic Point is a point before which elements are strictly increasing and after which elements are strictly decreasing.

Note: It is guaranteed that the array contains exactly one bitonic point.

Examples:

Input: arr[] = [1, 2, 4, 5, 7, 8, 3]
Output: 8
Explanation: Elements before 8 are strictly increasing [1, 2, 4, 5, 7] and elements after 8 are strictly decreasing [3].
Input: arr[] = [10, 20, 30, 40, 50]
Output: 50
Explanation: Elements before 50 are strictly increasing [10, 20, 30 40] and there are no elements after 50.
Input: arr[] = [120, 100, 80, 20, 0]
Output: 120
Explanation: There are no elements before 120 and elements after 120 are strictly decreasing [100, 80, 20, 0].
Constraints:
3 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106
*/


/*
    Approach - 1
Time Complexity: O(log(N))
Space Complexity: O(1)
*/
class Solution{
    public:
        
        int findMaximum(int nums[], int n) {
            // code here
        int st =0 ,maxa = INT_MIN;
            int en =  n -1 ;
            int mid = st+ (en-st)/2;
            while(st<en){
                if(nums[mid]<nums[mid+1]){
                    st =mid+1;
                }
                else{
                    en =mid;
                }
                maxa = max(maxa,nums[mid]);
                 mid = st+ (en-st)/2;
            }
            return nums[st];
            
        }
    };


/*
    Approach - 2
Time Complexity: O(N)
Space Complexity: O(1)
*/
class Solution {
    public:
      int findMaximum(vector<int> &arr) {
          // code here
          for(int i=0;i<arr.size()-1;i++) if(arr[i] > arr[i+1]) return arr[i];
          return arr[arr.size()-1];
      }
  };
  