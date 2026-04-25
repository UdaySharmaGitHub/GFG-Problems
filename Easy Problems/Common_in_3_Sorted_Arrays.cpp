/*
Common in 3 Sorted Arrays
Given three sorted arrays in non-decreasing order, return all common elements in non-decreasing order across these arrays. If there are no such elements return an empty array.
Examples :
Input: a[] = [1, 5, 10, 20, 40, 80], b[] = [6, 7, 20, 80, 100], c[] = [3, 4, 15, 20, 30, 70, 80, 120]
Output: [20, 80]
Explanation: The elements 20 and 80 appear in all three arrays a, b, and c, making them the only common elements, so the output is [20, 80].
Input: a[] = [1, 2, 3, 4, 5], b[] = [6, 7], c[] = [8, 9, 10]
Output: []
Explanation: Since none of the elements in arrays a, b, and c appear in all three arrays, there are no common elements, so the output is [].
Input:  a[] = [1, 1, 1, 2, 2, 2], b[] = [1, 1, 2, 2, 2], c[] = [1, 1, 1, 1, 2, 2, 2, 2]
Output: [1, 2]
Explanation: Ignoring duplicates, 1 and 2 are present in all three arrays, so the output is [1, 2].
Constraints:
1 ≤ a.size(), b.size(), c.size() ≤ 105
-105 ≤ a[i], b[i] , c[i] ≤ 105
*/
/*
    using the Set
    Time Complexity: O(max(n1,n2,n3))
    Space Complexity: O(n);
*/
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            set<int> s;
            int i = 0 , j = 0 , k = 0;
            while(i<n1 && j<n2 && k<n3){
                if(A[i] == B[j] && B[j] == C[k]){
                    s.insert(A[i]);
                    i++;j++;k++;
                    
                }
                else if(A[i] < B[j]){
                    i++;
                }
                else if(B[j]<C[k]){
                    j++;
                }
                else{
                    k++;
                }
            }
            vector<int> ans;
            for(auto se:s){
                ans.push_back(se);
            }
            if(ans.size()==0) return {-1};
            
            return ans;
            
        }

};
/*
    Without using the Set
    Time Complexity: O(max(n1,n2,n3))
    Space Complexity: O(n);
*/
class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        vector<int> res;
        int i =0 , j = 0,k = 0;
        while(i<a.size() && j<b.size() && k<c.size()){
            if(a[i] == b[j] && b[j] == c[k] && a[i] == c[k]){ res.push_back(a[i]);i++;j++;k++;}
            int maxa = max(a[i],max(b[j],c[k]));
            while(a[i]<maxa && i<a.size()) i++;
            while(b[j]<maxa && j<b.size()) j++;
            while(c[k]<maxa && k<c.size()) k++;
        }
        if(res.size()==0) return res;
        a.clear();
        i=0;
        a.push_back(res[i]);
        for(i=1;i<res.size();i++) if(res[i-1] != res[i]) a.push_back(res[i]);
        return a;
    }
};