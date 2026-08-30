/*
Marks from Ranks
Consider an input where all marks obtained are divided into intervals of consecutive numbers represented as l[] and r[] where l[i] and r[i] represent the starting and ending marks (inclusive) of the i-th interval. 
The intervals are sorted in increasing order and do not overlap.
The rank of a mark is defined by its position among all valid marks in increasing order, with the smallest mark assigned rank 1, the next smallest rank 2, and so on.
Given an array rank[]. for each value in rank[], find the corresponding mark and return as an array.
Examples:
Input: l[] = [1, 6, 14], r[] = [3, 9, 15], rank[] = [2, 5, 8]
Output: [2, 7, 14]
Explanation: The valid marks are 1, 2, 3, 6, 7, 8, 9, 14, 15. Their corresponding ranks are 1 to 9 as there are 9 distinct marks. Therefore, rank 2 corresponds to mark 2, rank 5 corresponds to mark 7, and rank 8 corresponds to mark 14.
Input: l[] = [5, 10], r[] = [7, 12], rank[] = [1, 4, 6]
Output: [5, 10, 12]
xplanation: The valid marks are 5, 6, 7, 10, 11, 12. Their corresponding ranks are 1 to 6 in increasing order. Hence, rank 1 corresponds to mark 5, rank 4 corresponds to mark 10, and rank 6 corresponds to mark 12.
 
Constraints:
1 ≤ l.size(), l[i], r.size(), r[i], rank.size(), rank[i] ≤ 105
*/
/*
    APPROACH: Using Searching and Storing Valid Marks
    Steps:
    1. Create an empty vector arr to store all valid marks.
    2. Iterate through the intervals defined by l and r.
    3. For each interval, add all marks from l[i] to r[i] to arr.
    4. Clear the l vector to reuse it for storing the results.
    5. For each rank in the rank vector, check if it is within the bounds of arr. If it is, add the corresponding mark from arr to l.
    6. Return the l vector containing the marks corresponding to the given ranks.

    Time Complexity: O(n + m) where n is the total number of valid marks and m is the size of the rank vector.
    Space Complexity: O(n) for storing the valid marks in arr.
*/
class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        vector<int> arr;
        for(int i =0 ; i<r.size();i++){
            int st = l[i] , en = r[i];
            for(int j =st;j<=en;j++) arr.push_back(j);
        }
        l.clear();
        for(int i:rank)if(i<=arr.size())l.push_back(arr[i-1]);
        return l;
    }
};