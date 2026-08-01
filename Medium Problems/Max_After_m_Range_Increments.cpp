/*
Max After m Range Increments
Given three arrays a[], b[], and k[], representing m range increment operations on an array arr[] of size n, where all elements of arr[] are initially 0.

Increment(a[i], b[i], k[i]) adds k[i] to each element arr[j] such that a[i] ≤ j ≤ b[i] (mainly indexes in range from a[i] to b[i])
After performing all the given operations, find the maximum value present in the array.
Examples:

Input: n = 5, a[] = [0, 1, 2], b[] = [1, 4, 3], k[] = [100, 100, 100]
Output: 200
Explanation: Initially, arr = [0, 0, 0, 0, 0]
After the first operation: arr = [100, 100, 0, 0, 0]
After the second operation: arr = [100, 200, 100, 100, 100]
After the third operation: arr = [100, 200, 200, 200, 100]
The maximum element after all operations is 200.
Input: n = 4, a[] = [1, 0, 3], b[] = [2, 0, 3], k[] = [603, 286, 882]
Output: 882
Explanation: Initially, arr = [0, 0, 0, 0]
After the first operation: arr = [0, 603, 603, 0]
After the second operation: arr = [286, 603, 603, 0]
After the third operation: arr = [286, 603, 603, 882]
The maximum element after all operations is 882.
Constraints:
1 ≤  n ≤ 106
1 ≤  a.size() = b.size() = k.size() = m  ≤ 106
0 ≤  ai  ≤  bi  ≤ n-1
0 ≤  ki  ≤ 106
*/
class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
        vector<int>v(n,0);
        int m = a.size();
        int sum = 0;
        int ans = 0;
        
        for(int i=0;i<m;i++){
            v[a[i]]+=k[i];
            if(b[i]+1<n)v[b[i]+1]-=k[i];
        }
        
        
        for(int i=0;i<n;i++){
            sum+=v[i];
            ans = max(ans,sum);
        }
        
        
        return ans;
        
    }
};