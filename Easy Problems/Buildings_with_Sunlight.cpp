/*
Buildings with Sunlight
Given the array arr[] of heights of certain buildings that lie adjacent to each other, Sunlight starts falling from the left side of the buildings. If there is a building of a certain height, all the buildings to the right side of it having lesser heights cannot see the sun.
Find the total number of buildings that receive sunlight.
Examples:
Input: arr[] = [6, 2, 8, 4, 11, 13]
Output: 4
Explanation: Only the buildings with heights 6, 8, 11, and 13 receive sunlight; therefore, the output is 4.
Input: arr[] = [2, 5, 1, 8, 3]
Output: 3
Explanation: Only buildings of height 2, 5 and 8 can see the sun, hence output is 3.
Input: arr[] = [3, 3, 3, 1]
Output: 3
Explanation: The first three buildings (height 3) receive sunlight, while the last building (1) is blocked. Hence, the output is 3.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
*/
class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int count = 0 , tallBuilding = arr[0];
        for(int i:arr) if(tallBuilding<=i) {count++;tallBuilding = i;}
        return count;
    }
};