/*
Node and Ancestor Max Diff
vGiven the root of a binary tree, find the maximum difference between an ancestor node A and its descendant node B, i.e., maximize A - B.

Examples :

Input: root[] = [5, 2, 1] 

Output: 4
Explanation: The maximum difference we can get is 4, which is between 5 and 1.
Input: root[] = [1, 2, 3, N, N, N, 7] 

Output: -1
Explanation: The maximum difference we can get is -1, which is between 1 and 2.
Constraints:

2 ≤ no. of nodes in root ≤ 104
0 ≤ root.node->data ≤ 105
2 ≤ Number of edges ≤ 104
*/
/*
    APPROACH:
    Step:
    1. We will do a postorder traversal of the tree.
    2. For each node, we will find the minimum value of its descendants.
    3. We will calculate the difference between the current node's value and the minimum value
       of its descendants and update the maximum difference if the current difference is greater.
    4. Finally, we will return the maximum difference found.

    Time Complexity: O(n) where n is the number of nodes in the tree.
    Space Complexity: O(h) where h is the height of the tree due to recursion stack.

*/
/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:

    int solve(Node* root, int& ans) {

        if (!root) {
            return 1e9;
        }

        int left = solve(root->left, ans);
        int right = solve(root->right, ans);

        ans = max(ans, root->data - left);
        ans = max(ans, root->data - right);

        return min({root->data, left, right});
    }
    int maxDiff(Node* root) {
        // code here

        /*
        i stay in root node i only ask left root ya right root sa jo bhi descendant hoga 
        lunga usa jo minimum hoga or root hamri ancestor node hai 
        */

        int ans = INT_MIN;
        solve(root, ans);

        return ans;
    }
};

