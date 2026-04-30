/*
Check if an Array is Max Heap
Given an array arr[], determine whether it represents the level-order traversal of a valid max heap. Return true if it does; otherwise, return false.

Examples :

Input: arr[] = [90, 15, 10, 7, 12, 2]
Output: true
Explanation: The given array represents the following tree. Each parent node is greater than or equal to its children, so the max-heap property holds.
 
Input: arr[] = [9, 15, 10, 7, 12, 11]
Output: false
Explanation: The given array represents the following tree. It does not satisfy the max-heap property, as 9 is smaller than 15 and 10, and 10 is smaller than 11.
 
Constraints:
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 105
*/
/*
    HEAP
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
          int n = arr.size();
        
        for(int i=0; i<n; i++)
        {
            int left_child = i*2 + 1;
            int right_child = i*2 + 2;
            
            if(left_child < n && arr[left_child] > arr[i])
            {
                return false;
            }
            if(right_child < n && arr[right_child] > arr[i])
            {
                return false;
            }
        }
        
        return true;
        
    }
};
