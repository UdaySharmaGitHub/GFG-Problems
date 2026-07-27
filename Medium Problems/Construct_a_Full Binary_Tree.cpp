/*
Construct a Full Binary Tree
Given two arrays pre[] and preMirror[] of size n containing unique elements, where pre[] represents the preorder traversal of a full binary tree and preMirror[] represents the preorder traversal of its mirror tree, construct the original full binary tree using these traversals.
Note: A general binary tree cannot be uniquely constructed using these two traversals. However, a full binary tree can be constructed uniquely from the given traversals without any ambiguity.
Examples:
Input: pre[] = [0,1,2], preMirror[] = [0,2,1] 
Output: [0, 1, 2]
Explanation: The tree will look like
Input: pre[] = [1, 2, 4, 5, 3, 6, 7], preMirror[] = [1, 3, 7, 6, 2, 5, 4]
Output: [1, 2, 4, 5, 3, 6, 7]
Explanation: The tree will look like
Constraints:
1 ≤ pre.size() ≤ 105
0 ≤ pre[i] ≤ 109
1 ≤ preMirror.size() ≤ 105
0 ≤ preMirror[i] ≤ 109
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
    // Recursive function to construct full binary tree
Node* constructBinaryTreeUtil(vector<int> &pre,
                              vector<int> &preMirror,
                              int &preIndex,
                              int l,
                              int h,
                              int n) {

    // Base case
    if (preIndex >= n || l > h)
        return nullptr;

    // Create root node
    Node* root = new Node(pre[preIndex++]);

    // If single element
    if (l == h)
        return root;

    // Find next preorder element in preMirror
    int i;
    for (i = l; i <= h; i++) {
        if (pre[preIndex] == preMirror[i])
            break;
    }

    // Build left and right subtrees
    if (i <= h) {

        root->left = constructBinaryTreeUtil(pre, preMirror,
                                            preIndex, i, h, n);

        root->right = constructBinaryTreeUtil(pre, preMirror,
                                             preIndex, l + 1, i - 1, n);
    }

    return root;
}

Node* constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {

    int n = pre.size();
    int preIndex = 0;

    return constructBinaryTreeUtil(pre, preMirror,
                                   preIndex, 0, n - 1, n);
}
};