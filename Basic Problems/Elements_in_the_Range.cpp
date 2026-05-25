/*
Given an array arr[] containing positive elements. A and B are two numbers defining a range. The task is to check if the array contains all elements in the given range.

Example 1:

Input: N = 7, A = 2, B = 5
arr[] =  {1, 4, 5, 2, 7, 8, 3}
Output: Yes
Explanation: It has elements between 
range 2-5 i.e 2,3,4,5
Example 2:

Input: N = 7, A = 2, B = 6
arr[] = {1, 4, 5, 2, 7, 8, 3}
Output: No
Explanation: Array does not contain 6.

Your Task:
This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function check_elements() that takes array arr, integer N, integer A, and integer B  as parameters and returns the boolean True if array elements contain all elements in the given range else boolean False.

Note: If the array contains all elements in the given range then driver code outputs Yes otherwise, it outputs No

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).


Constraints:
1 ≤ N ≤ 107
*/
//{ Driver Code Starts
/*
    APPROACH:
    Step:
    1. We will calculate the total number of elements in the given range using the formula (end - start) + 1.
    2. We will iterate through the array and check if each element is within the range (start to end). If it is, we will decrement the total count.
    3. If at any point the total count becomes zero, it means we have found all the elements in the range, and we can return true.
    4. If we finish iterating through the array and the total count is not zero, it means we are missing some elements in the range, and we will return false.

    Time Complexity: O(N) - We need to iterate through the array once.
    Auxiliary Space: O(1) - We are using a constant amount of space to store the total count and other variables.
*/
class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
         // code here
        // int  cout=0;
        int total= (end- start) +1;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>= start and arr[i]<= end){
                total--;
            }
            if(total==0)return 1;
        }
        return total== 0 ? true : false;
    }
};
