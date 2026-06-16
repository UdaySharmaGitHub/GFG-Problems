/*
Construct List using XOR Queries
There is an array that initially contains only a single value, 0. 

Given a list of queries queries[][] of size q, where each query is of one of the following types:

0 x: Insert x into the array.
1 x: Replace every element a in the array with a ^ x, where ^ denotes the bitwise XOR operator.
Return the array in sorted order after performing all the queries.

Examples:

Input: q = 5, queries[] = [[0, 6], [0, 3], [0, 2], [1, 4], [1, 5]]
Output: [1, 2, 3, 7]
Explanation:
[0] (initial value)
[0, 6] (add 6 to list)
[0, 6, 3] (add 3 to list)
[0, 6, 3, 2] (add 2 to list)
[4, 2, 7, 6] (XOR each element by 4)
[1, 7, 2, 3] (XOR each element by 5)
The sorted list after performing all the queries is [1, 2, 3, 7]. 
Input: q = 3, queries[] = [[0, 2], [1, 3], [0, 5]] 
Output : [1, 3, 5]
Explanation:
[0] (initial value)
[0, 2] (add 2 to list)
[3, 1] (XOR each element by 3)
[3, 1, 5] (add 5 to list)
The sorted list after performing all the queries is [1, 3, 5].
Constraints:
1 ≤ q ≤ 105
0 ≤ x ≤ 109
*/
class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        vector<int> arr;
        int _xor = 0;
        for(int i = queries.size()-1;i>=0;i--){
            int ty = queries[i][0], x = queries[i][1];
            if(ty == 0){
                arr.push_back((_xor^x));
            }
            else{
                _xor ^= x;
            }
        }
        arr.push_back(_xor);
        sort(arr.begin(), arr.end());
        return arr;
    }
};