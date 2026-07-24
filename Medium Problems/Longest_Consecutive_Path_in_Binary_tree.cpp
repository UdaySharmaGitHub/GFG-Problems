/*
Longest Consecutive Path in Binary tree
Given the root of a Binary Tree, find the length of the longest path consisting of connected nodes such that each next node has a value exactly 1 greater than its parent.
The path must move from parent to child only and follow increasing consecutive values.
If no such path exists, return -1.
Examples:
Input: root[] = [1, 2, 3]
Output: 2
Explanation : Longest sequence is 1, 2. So answer for this test case is 2.
Input : root[] = [10, 20, 30, 40, N, 60, 90]
Output : -1
Explanation: For the above test case no sequence is possible. So output is -1.
Constraints:
1 ≤ no. of nodes in root ≤ 105
1 ≤ root.node->data ≤ 105
*/
/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    int ans = 1;

    void dfs(Node* node, int parentValue, int length) {
        if (node == nullptr) return;

        if (node->data == parentValue + 1)
            length++;
        else
            length = 1;

        ans = max(ans, length);

        dfs(node->left, node->data, length);

        dfs(node->right, node->data, length);
    }

    int longestConsecutive(Node* root) {
        if (root == nullptr) return -1;

        dfs(root, root->data - 1, 0);

        return (ans == 1) ? -1 : ans;
    }
};