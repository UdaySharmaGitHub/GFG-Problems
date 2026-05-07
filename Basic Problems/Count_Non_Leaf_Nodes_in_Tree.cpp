/*
Count Non-Leaf Nodes in Tree
Given a Binary Tree of size n, your task is to return the count of all the non-leaf nodes of the given binary tree.

Example:

Input: 
Image
Output: 2
Explanation: Nodes 1 and 2 are the only non leaf nodes.
Input: 
          8
        /   \
       3     9
      / \
     1   6
        / \
       4   7
Output: 3
Explanation: Nodes 8, 3 and 6 are the only non leaf nodes.
Input: 
          10
        /    \
      5       20
     / \     /  \
    3   7   15   25
Output: 3
Explanation: Nodes 10, 5 and 20 are the only non leaf nodes.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105
*/
/*Structure of the node of the tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// you are required to complete this function
// the function should return the count of Non-Leaf Nodes
/*
    APPRAOCH:  Recursive Approach
    1. We will use a recursive approach to solve this problem.
    2. We will define a helper function 'solve' that takes the current node and a reference to the count of non-leaf nodes.
    3. In the 'solve' function, we will check if the current node is a non-leaf node (i.e., it has at least one child). If it is, we will increment the count.
    4. We will then recursively call the 'solve' function for the left and right children of the current node.
    5. Finally, we will return the count of non-leaf nodes after the recursive calls are complete.

    Time Complexity: O(n), where n is the number of nodes in the tree, since we visit each node exactly once.
    Space Complexity: O(h), where h is the height of the tree, due to the recursive call stack. In the worst case (skewed tree), this can be O(n).
*/
class Solution {
  public:
     void solve(Node* root,int & count){
         if(!root) return ;
         if(root->left || root->right) count++;
         solve(root->left,count);
         solve(root->right,count);
         
     }
    int countNonLeafNodes(Node* root) {
        // Code here
        int count =0;
        solve(root,count);
        return count ;
    }
};
/*
    APPROACH:  Iterative Approach
    1. We will use a level order traversal (BFS) to count the non-leaf nodes iteratively.
    2. We will initialize a queue and push the root node into it.
    3. We will initialize a variable 'countNonLeaf' to keep track of the count of non-leaf nodes.
    4. We will loop until the queue is empty. In each iteration, we will get the number of nodes at the current level (size of the queue).
    5. For each node at the current level, we will check if it is a non-leaf node (i.e., it has at least one child). 
       If it is we will increment the 'countNonLeaf' variable.

    Time Complexity: O(n), where n is the number of nodes in the tree, since we visit each node exactly once.
    Space Complexity: O(w), where w is the maximum width of the tree, due to the queue used for level order traversal. 
                      In the worst case (complete binary tree), this can be O(n/2) = O(n).
*/
class Solution {
  public:
    int countNonLeafNodes(Node* root) {
        // Code here
         queue<Node*> q;
        q.push(root);
        int countNonLeaf = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i =0 ;i<n;i++){
                Node* frontNode = q.front();
                if(frontNode->right || frontNode->left)countNonLeaf++;
                q.pop();
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
        }
        return countNonLeaf;
    }
};