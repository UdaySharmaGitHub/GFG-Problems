/*
Sum of Binary Tree
Given a binary tree, find the sum of values of all the nodes. 
Examples:
Input: root = [15, 10, 20, 8, 12, 16, 25]
Output: 106
Explanation: The sum of all the nodes is 15 + 10 + 20 + 8 + 12 + 16 + 25 = 106

Input: root = [1, 3, 2]
Output: 6
Explanation: The sum of all the nodes is 1 + 2 + 3 = 6.

Input: root = [1, 2, N, 4, N]
Output: 7
Explanation: The sum of all the nodes is 1 + 2 + 4 = 7.

Constraints:
1 ≤ number of nodes ≤ 104
-105 ≤ Node data ≤ 105
*/
/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
/*
    APPROACH: Recursion (Optimized)
    1. If the root is null, return 0.
    2. Recursively call the function for the left and right subtrees.
    3. Return the sum of the root's data and the sums obtained from the left and right subtrees.

    Time Complexity: O(N), where N is the number of nodes in the binary tree, since we visit each node exactly once.
    Space Complexity: O(H), where H is the height of the binary tree, due to the recursive call stack. In the worst case (skewed tree), 
                      H can be equal to N, leading to O(N) space complexity. In the best case (balanced tree), H is log(N), 
                      leading to O(log(N)) space complexity.
*/
class Solution {
  public:
    int sumBT(Node* root) {
        // code here
        if(!root ) return 0;
        int left = sumBT(root->left), right = sumBT(root->right);
        return root->data + left+right;
    }
};

/*
    APPROACH: Iterative (Level Order Traversal)
    1. Initialize a queue and push the root node into it.
    2. Initialize a variable `sum` to store the cumulative sum of node values.
    3. While the queue is not empty:
       a. Get the number of nodes at the current level (size of the queue).
       b. For each node at the current level:
          i. Pop the front node from the queue and add its value to `sum`.
          ii. If the left child of the node exists, push it into the queue.
          iii. If the right child of the node exists, push it into the queue.
    4. After the loop ends, return the value of `sum`.  

    Time Complexity: O(N), where N is the number of nodes in the binary tree, since we visit each node exactly once.
    Space Complexity: O(W), where W is the maximum width of the binary tree, which can be O(N) in the worst case (when the tree is a complete binary tree). 
                      In the best case (skewed tree), W is 1, leading to O(1) space complexity.
*/
class Solution {
  public:
    int sumBT(Node* root) {
        // code here
         queue<Node*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i =0 ;i<n;i++){
                Node* frontNode = q.front();
                sum+=frontNode->data;
                q.pop();
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
        }
        return sum;
    }
};