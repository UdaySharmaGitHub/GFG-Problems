/*
Count Pairs Violating BST Property
Given root of a binary tree in which all node values are distinct, count pairs of nodes that violate any of the following Binary Search Tree (BST) properties.


All values in the left subtree are strictly smaller.
All values in the right subtree are strictly greater.
Examples:

Input: root[] = [10, 50, 40, N, N, 20, 30]
2056958715
Output: 5
Explanation: Pairs violating BST property are:-
(10, 50), 10 should be greater than its left child value.
(40, 30), 40 should be less than its right child value.
(50, 20), (50, 30) and (50, 40), maximum of left subtree of 10 is 50 greater than 20, 30 and 40 of its right subtree.
Input: root[] = [80, 40, 30, 70, N, 60, 50]

Output: 10
Explanation: There are total 10 pairs (80, 30), (80, 60), (80, 50), (30, 60), (40, 70), (40, 30), (40, 50), (70, 30), (70, 60), (70, 50) which violate the BST properties.
Constraints:

1 ≤ size of binary tree ≤ 5*104
1 ≤ node.data ≤ 109
All node values are distinct.
*/
/* BST Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  vector<int>ind;
  int n;
    void traverse(Node* root){
        if(!root)return ;
        traverse(root->left);
        ind.push_back(root->data);
        traverse(root->right);
    }
    vector<int>bits;
    void update(int idx){
        while(idx<=n){
            bits[idx]+=1;
            idx+=(idx&-idx);
        }
    }
    int query(int idx){
        int sum=0;
        while(idx>0){
            sum+=bits[idx];
            idx-=(idx&-idx);
        }
        return sum;
    }
    int pairsViolatingBST(Node *root) {
        // code here
        // vector<i
        int sum=0;
        ind.clear();
        traverse(root);
        vector<int>temp=ind;
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());
        n=temp.size();
        bits.assign(n+1, 0);
        int s=ind.size();
        for(int i=s-1;i>=0;i--){
            int idx=lower_bound(temp.begin(),temp.end(),ind[i])-temp.begin()+1;
            sum+=query(idx-1);
            update(idx);
        }
        return sum;

    }
};