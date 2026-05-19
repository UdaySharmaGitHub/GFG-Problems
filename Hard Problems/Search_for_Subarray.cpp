/*
Search for Subarray
You are given two integer arrays a[] and b[]. Return all the starting indexes of all the occurences of b[] as a subarray in a[].

Examples:

Input: a[] = [2, 4, 1, 0, 4, 1, 1], b[] = [4, 1]
Output: [1, 4]
Explanation: b[] occurs as a subarray in a[] from index 1 to 2 and from index 4 to 5.
Input: a[] = [2, 4, 1, 0, 0, 3], b[] = [0]
Output: [3, 4]
Explanation: b[] occurs as a subarray in a[] from index 3 to 3 and from index 4 to 4.
Input: a[] = [1, 3, 5, 3, 0], b[] = [1, 3, 0]
Output: []
Explanation: There is no subarray occurs as b[] in a[]
Constraints:
1 ≤ a.size() ≤ 106
1 ≤ b.size() ≤ a.size()
0 ≤ b[i], a[i] ≤ 104
*/
class Solution {
  public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        // code here
        int m = b.size();
        int n = a.size();
        vector<int>ans;
        vector<int>lps(m,0);
        lps[0]=0;
        
        int first = 0;
        int second = 1;
        
        // finding LPS
        while(second<m){
            
            if(b[first]==b[second]){
                lps[second] = first+1;
                first++;
                second++;
            }
            else if(first==0){
                lps[second]=0;
                second++;
            }
            else first = lps[first-1];
            
            
        }
        // string matching;
        b.push_back(-1);
        lps.push_back(0);
        first = 0;
        second = 0;
        
        while(second<n){
            
            if(b[first]==a[second]){
                first++;
                second++;
            }
            else if(first==0)second++;
            else{
                
                if(first==m)ans.push_back(second-m);
                first = lps[first-1];
            }
            
        }
        
        if(second==n && first==m)ans.push_back(second-m);
        return ans;
        
        
    }
};