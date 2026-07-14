/*
Smallest Non-Zero Number
Given an array arr[], find the smallest number x such that when x is processed sequentially with each element of the array (from index 0 to n-1), it never becomes negative, under the following conditions:

If x is greater than the current array element, x is increased by the difference between x and the array element.
If x is less than or equal to the current array element, x is decreased by the difference between the array element and x.
Examples:

Input: arr[] = [3, 4, 3, 2, 4]
Output: 4
Explanation: Start with x = 4:
- For arr[0] = 3, x becomes 5.
- For arr[1] = 4, x becomes 6.
- For arr[2] = 3, x becomes 9.
- For arr[3] = 2, x becomes 16.
- For arr[4] = 4, x becomes 28.
x remains positive throughout the process.
If x < 4, it would become negative at some point.
Input: arr[] = [4, 4]
Output: 3
Explanation: Start with x = 3:
- For arr[0] = 4, x becomes 2.
- For arr[1] = 4, x becomes 0.
x remains non-negative. If x < 3, it would become negative.
Constraints:
1 ≤ arr.size() ≤ 106
1<= arr[i] <= 104
*/
/*
    APPROACH: Reverse Greedy - O(n) Time and O(1) Space
    STEPS:
    1. Start with x = 0.
    2. Iterate through the array in reverse order.
    3. For each element, update x using the formula: x = (x + arr[i] + 1) / 2.
    4. Return the final value of x after processing all elements.   

    Time Complexity: O(n), where n is the size of the array.
    Space Complexity: O(1), as we are using a constant amount of space.

*/
class Solution {
  public:
    int find(vector<int>& arr) {
        // code here
        int x = 0 ; 
        for(int i  = arr.size()-1;i>=0;i--){
            x = (x+arr[i]+1)/2;
        }
        return x;
    }
};
/*
    APPROACH:
    1. Start with x = 0.
    2. For each element in the array, update x based on the conditions given.
    3. If x becomes negative at any point, increment x and repeat the process.

    Time Complexity: O(n * m), where n is the size of the array and m is the value of x.
    Space Complexity: O(1), as we are using a constant amount of space.
*/

class Solution {
  public:
    int find(vector<int>& arr) {
        // code here
        int x = 0 ; 
        while(true){
            int curr = x;
            bool isneg = true;
            
            for(int i:arr){
                if(i<curr) curr+=(curr-i);
                else curr-=(i-curr);
                
                if(curr<0) isneg = false;
            }
            if(isneg) return x;
            x++;
        }
        return x;
    }
};