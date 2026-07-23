/*
Check Preorder of BST
Given an array arr[ ] consisting of distinct integers, check if the given array can represent preorder traversal of a BST.

Examples :

Input: arr[] = [2, 4, 3]
Output: true
Explaination: Given arr[] can represent preorder traversal of following BST:
 
Input: arr[] = [2, 4, 1]
Output: false
Explaination: Given arr[] cannot represent preorder traversal of a BST.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105
*/
class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        // code here
        int root = INT_MIN;
        stack<int> s;
        for(int i =0 ; i<arr.size();i++){
            if(arr[i] <root) return false;
            
            while(!s.empty() && s.top() < arr[i]) { root =s.top();s.pop();}
            s.push(arr[i]);
        }
    return 1;
    }
};