/*
Check if subtree
Given two binary trees with roots root1 (for tree T) and root2 (for tree S), each containing at most N nodes. Determine whether tree S is a subtree of tree T.
Return true if S is a subtree of T, otherwise return false.
Note: A tree S is considered a subtree of T if there exists a node in T such that the subtree rooted at that node is identical to S. Two trees are identical if they have the same structure and the same node values.
Examples:
Input: root1 = [1, 2, 3, N, N, 4], root2 = [3, 4]    
Output: true 
Explanation: In the tree rooted at root1, the subtree starting at node 3 is identical to the tree rooted at root2 (same structure and node values). Hence, root2 is a subtree of root1, so the output is true.
Input: root1 = [26, 10, N, 20, 30, 40, 60], root2 = [26, 10, N, 20, 30, 40, 60]
                        
Output: true 
Explanation: Both root1 and root2 represent identical trees. So, root2 is a subtree of root1, and the output is true.
Constraints:
1 ≤ n ≤ 103
1 ≤ value of nodes ≤ 104
*/
/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

/*
    Time Complexity: O(n*m) where n and m are the number of nodes in root1 and root2 respectively. In the worst case, we may have to compare each node of root1 with root2, and each comparison takes O(m) time.
    Space Complexity: O(h) where h is the height of the tree rooted at root1
*/
class Solution {
  public:

    bool isIdentical(Node* a, Node* b) {
        
        // both null
        if(a == NULL && b == NULL)
            return true;

        // one null
        if(a == NULL || b == NULL)
            return false;

        // values different
        if(a->data != b->data)
            return false;

        // check left and right
        return isIdentical(a->left, b->left) &&
               isIdentical(a->right, b->right);
    }

    bool isSubTree(Node* root1, Node* root2) {

        // empty subtree always true
        if(root2 == NULL)
            return true;

        // main tree ended
        if(root1 == NULL)
            return false;

        // if identical from current node
        if(isIdentical(root1, root2))
            return true;

        // search in left or right subtree
        return isSubTree(root1->left, root2) ||
               isSubTree(root1->right, root2);
    }
};