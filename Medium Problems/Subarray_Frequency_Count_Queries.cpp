/*
Subarray Frequency Count Queries
Given an array arr[] of n integers and a 2D array queries[][] representing q queries, where each queries[i] consists of three integers: l, r, and x. For each query determine how many times the element x appears in the arr[] from index l to r (both inclusive).

Return a list of integers where the i-th value represents the answer to the i-th query.

Examples: 

Input: arr[] = [1, 2, 1, 3, 1, 2, 3], queries[][] = [[0, 4, 1], [2, 5, 2], [1, 6, 3], [0, 6, 5]]
Output: [3, 1, 2, 0]
Explanation:
query [0, 4, 1] -> Subarray = [1, 2, 1, 3, 1], 1 appears 3 times
query [2, 5, 2] -> Subarray = [1, 3, 1, 2], 2 appears 1 time
query [1, 6, 3] -> Subarray = [2, 1, 3, 1, 2, 3] 3 appears 2 times
query [0, 6, 5] -> Subarray = [1, 2, 1, 3, 1, 2, 3],  5 appears 0 times
Input: arr[] = [11, 21, 51, 101, 11, 51], queries[][] = [[0, 4, 11], [2, 5, 51]]
Output: [2, 2]
Explanation:
query [0, 4, 11] -> Subarray = [11, 21, 51, 101, 11], 11 appears 2 times
query [2, 5, 51] -> Subarray = [51, 101, 11, 51], 51 appears 2 times
Constraints:
1 ≤ arr.size(), queries.size() ≤ 105
1 ≤ arr[i], queries[i][2] ≤ 105
0 ≤ queries[i][0] ≤ queries[i][1] < arr.size()
*/
/*
    APPROACH: OPTIMIZED APPROACH
    1. Create a map to store the indices of each element in the array.
    2. For each query, check the map for the element x and count how many times it appears in the range [l, r].
    3. Store the count in the result vector and return it at the end.

    Time Complexity: O(N + Q * M) where N is the size of the array, Q is the number of queries, and M is the average number of occurrences of x in the array.
    Space Complexity: O(N) for the map storing the indices of each element.
*/
class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        vector<int> res;
        unordered_map<int,vector<int>> map;    // -----------------> SC: O(N)
        for(int i=0;i<arr.size();i++) map[arr[i]].push_back(i); // -----------------> TC: O(N)
        for(vector<int> temp:queries){  // -----------------> TC: O(Q * M)
            int st= temp[0] , en = temp[1] , x = temp[2] ,count = 0;
            if(map[x].size()>0){
                for(int i:map[x]) if(i >=st && i<=en) count++;
            }
            res.push_back(count);
        }
        return res;
    }
};

/*
    BRUTE FORCE APPROACH
    1. For each query, iterate through the subarray defined by the range [l, r] and count how many times the element x appears.
    2. Store the count in the result vector and return it at the end.   
    Time Complexity: O(Q * N) where Q is the number of queries and N is the size of the array.
    Space Complexity: O(1) for the count variable and O(Q) for the result
*/
class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        vector<int> res;
        for(vector<int> temp:queries){
            int st = temp[0] , en = temp[1] , x =temp[2] ,count = 0;
            for(int i=st;i<=en;i++) if(arr[i] == x) count++;    
            res.push_back(count);
        }
        return res;
    }
};