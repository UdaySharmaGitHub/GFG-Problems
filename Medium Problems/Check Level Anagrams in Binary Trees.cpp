/*
Check Level Anagrams in Binary Trees
Given the roots of two binary trees root1 and root2, check whether the nodes at every corresponding level of the two trees are anagrams of each other.

Two levels are considered anagrams if they contain the same node values with the same frequencies, regardless of their order.
Examples:
Input: root1 = [1, 3, 2, N, N, 5, 4], root2 = [1, 2, 3, 4, 5, N, N]
Output: true
Explanation: 
Level 0: [1] and [1]
Level 1: [3, 2] and [2, 3]
Level 2: [5, 4] and [4, 5]
The node values at every corresponding level are anagrams of each other. Hence, the answer is true.
Input: root1 = [1, 2, 3, 5, 4], root2 = [1, 2, 4, 5, 3]
Output: false
Explanation: 
Level 0: [1] and [1]
Level 1: [2, 3] and [2, 4]
Since the node values at level 1 are not anagrams, the answer is false.
Constraints:
1 ≤ size of binary tree ≤ 105
1 ≤ node.data ≤ 106
The character N represents a null child.
*/
/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
            if (!root1 && !root2) return true;
            if (!root1 || !root2) return false;

            std::queue<Node*> q1, q2;
            q1.push(root1);
            q2.push(root2);

            while (!q1.empty() && !q2.empty()) {
                int n1 = q1.size();
                int n2 = q2.size();

                // Levels with different node counts cannot be anagrams
                if (n1 != n2) return false;

                std::vector<int> level1, level2;

                for (int i = 0; i < n1; i++) {
                    Node* node1 = q1.front();
                    q1.pop();
                    level1.push_back(node1->data);
                    if (node1->left) q1.push(node1->left);
                    if (node1->right) q1.push(node1->right);

                    Node* node2 = q2.front();
                    q2.pop();
                    level2.push_back(node2->data);
                    if (node2->left) q2.push(node2->left);
                    if (node2->right) q2.push(node2->right);
                }

                // Sort level vectors to verify if they are anagrams
                std::sort(level1.begin(), level1.end());
                std::sort(level2.begin(), level2.end());

                if (level1 != level2) return false;
            }

            // Both queues must be empty at the end (same depth)
            return q1.empty() && q2.empty();
        }
};
