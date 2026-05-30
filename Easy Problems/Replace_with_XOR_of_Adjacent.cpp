/*
Replace with XOR of Adjacent
Given an array arr[] of n integers, modify the array in-place such that each element is replaced with the XOR of its adjacent elements.

For the first element, update arr[0] = arr[0] ^ arr[1].
For the last element, update arr[n-1] = arr[n-2] ^ arr[n-1].
For all other elements, update arr[i] = arr[i-1] ^ arr[i+1].
Note: Here, a ^ b represents the XOR operation between a and b. 

Examples :

Input : arr[] = [2, 1, 4, 7]
Output : [3, 6, 6, 3]
Explanation:
At index 0, arr[0] ^ arr[1] = 2 ^ 1 = 3
At index 1, arr[0] ^ arr[2] = 2 ^ 4 = 6
At index 2, arr[1] ^ arr[3] = 1 ^ 7 = 6
At index 3, arr[2] ^ arr[3] = 4 ^ 7 = 3
Thus, the updated array becomes [3, 6, 6, 3].
Input : arr[] = [5, 9, 2, 6, 7]
Output: [12, 7, 15, 5, 1]
Explanation:
At index 0, arr[0] ^ arr[1] = 5 ^ 9 = 12
At index 1, arr[0] ^ arr[2] = 5 ^ 2 = 7
At index 2, arr[1] ^ arr[3] = 9 ^ 6 = 15
At index 3, arr[2] ^ arr[4] = 2 ^ 7 = 5
At index 4, arr[3] ^ arr[4] = 6 ^ 7 = 1
Thus, the updated array becomes [12, 7, 15, 5, 1]. 
Constraints:
2 ≤ n ≤ 105
1 ≤ arr[i] ≤ 107
*/
/*
    APPROACH:
    1. We can solve this problem in O(n) time complexity by iterating through the array and updating each element based on the given rules.
    2. We need to be careful while updating the elements, as we need to use the original values of the adjacent elements before they are modified.
    3. We can store the original first element before updating it, and then use it to update the middle elements. Finally, we can update the last element using the last and previous original element.
    4. This way, we can ensure that we are using the correct values for the XOR operation while updating the elements in-place.

    ALGORITHM:
    1. Check if the array is empty or has only one element. If so, return immediately as no changes are needed.
    2. Store the original first element in a variable (prev).
    3. Update the first element using the XOR of the first and second elements.
    4. Iterate through the array from the second element to the second last element:
       a. Compute the XOR of the previous original element (prev) and the next element.
       b. Store the current element before overwriting it in prev.
       c. Update the current element with the computed XOR value.
    5. Finally, update the last element using the XOR of the last element and the previous original element (prev).

    TIME COMPLEXITY: O(n), where n is the size of the array.
    SPACE COMPLEXITY: O(1), as we are modifying the array in-place and
*/
class Solution {
  public:
    void replaceElements(vector<int> &arr)
{
    int n = arr.size();
    // Edge case: if array is empty or has only one element
    if (n <= 1)
        return;
    // Store original first element
    int prev = arr[0];
    // Update first element using arr[0] ^ arr[1]
    arr[0] = arr[0] ^ arr[1];
    // Traverse and update middle elements
    for (int i = 1; i < n - 1; i++)
    {
        // Compute XOR of previous original element and next element
        int val = prev ^ arr[i + 1];
        // Store current element before overwriting
        prev = arr[i];
        // Update current element
        arr[i] = val;
    }
    // Update last element using last and previous original element
    arr[n - 1] = arr[n - 1] ^ prev;
}
};

/*
    APPROACH:
    1. We can create a new array to store the updated values while iterating through the original array.
    2. For each element, we can compute the XOR of the adjacent elements based on the given rules and store the result in the new array.
    3. Finally, we can copy the values from the new array back to the original array to reflect the changes.
    ALGORITHM:
    1. Create a new array (res) of the same size as the original array to store the updated values.
    2. Iterate through the original array:
       a. For the first element, compute res[0] = arr[0] ^ arr[1].
       b. For the last element, compute res[n-1] = arr[n-2] ^ arr[n-1].
       c. For all other elements, compute res[i] = arr[i-1] ^ arr[i+1].
    3. After the loop, copy the values from the res array back to the original arr array to update it in-place.

    TIME COMPLEXITY: O(n), where n is the size of the array.
    SPACE COMPLEXITY: O(n), as we are using an additional array to store the
*/
class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        // code here
        vector<int> res(arr.size(),0);
        if(arr.size()==1) arr[0] = arr[0]^arr[0];
        for(int i =0;i<arr.size();i++){
            if(i==0) res[i] = arr[i]^arr[i+1];
            else if(i==arr.size()-1) res[i] = arr[i-1]^arr[i];
            else res[i] = arr[i-1]^arr[i+1];
            
        }
            arr = res;
    }
};