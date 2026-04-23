/*
Max value
In a given array arr[], find the maximum value of (arr[i] – i) - (arr[j] – j) where i is not equal to j and n is the size of the array. i and j vary from 0 to n-1  arr[].
Examples:
Input: arr[] = [9, 15, 4, 12, 13]
Output: 12
Explanation: (a[1]-1) - (a[2]-2) = (15-1)-(4-2) = 12
Input: arr[] = [3, 1, 2, 4]
Output: 3
Explanation: (a[0]-0) -(a[1]-1) = (3-0) - (1-1) = 3
Constraints:
2 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
*/
// User function Template for C++

class Solution {
  public:
    // Function to find maximum value among the difference of element and index.
    int maxVal(vector<int> &arr) {
        // code here
        int maxa  = INT_MIN , mina = INT_MAX;
        for(int i=0;i<arr.size();i++){
            maxa =max(maxa,arr[i]-i);
            mina = min(mina,arr[i]-i);
        }
        return maxa-mina;
    }
};