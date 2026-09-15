/*
Visit Leaves with Budget
Given a binary tree and an integer k, where you start from the root at level 1. The cost of visiting a leaf node is equal to the level of that leaf node. You can visit any number of leaf nodes, but the total cost of visiting them must not exceed k.

Return the maximum number of leaf nodes that can be visited within the given budget.

Examples:

Input: root[] = [10, 8, 2, 3, N, 3, 6, N, N, N, 4], k = 8

Output: 2
Explanation:
Cost For visiting Leaf Node 3: 3
Cost For visiting Leaf Node 4: 4
Cost For visiting Leaf Node 6: 3
To maximize the number of visited leaves, choose the two cheapest leaves: Cost = 3 + 3 = 6 ≤ 8. 
Thus, the maximum number of leaf nodes that can be visited is 2.
Input: root[] = [1, 2, 3, 4, 5, 6, 7], k = 5

Output: 1
Explanation: The leaf nodes are 4, 5, 6 and 7, and all are at level 3. Therefore, visiting each leaf costs 3. With a budget of 5, we can visit only one leaf because: 3 ≤ 5, but 3 + 3 > 5. Thus, the maximum number of leaf nodes that can be visited is 1.
Input: root[] = [1], k = 1         
Output: 1
Explanation: The root node is also a leaf node and is at level 1. Therefore, its visiting cost is 1. Thus, the maximum number of leaf nodes that can be visited is 1.
Constraints:

1 ≤ size of binary tree ≤ 105
1 ≤ k ≤ 104
*/
/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
/*
        APPROACH: BFS Traversal
        1. Use a queue to perform level-order traversal of the binary tree.
        2. Keep track of the current level.
        3. For each leaf node, check if visiting it is within the budget.
        4. If yes, increment the count and decrease the budget by the level.
        5. Continue until the queue is empty or the budget is exhausted.

        TIME COMPLEXITY: O(n), where n is the number of nodes in the binary tree.
        SPACE COMPLEXITY: O(n), for the queue used in level-order traversal.
*/
class Solution {
  public:
    int getCount(Node *root, int k) {
        // code here
        vector<int> res;
    queue<Node*> q;
    q.push(root);
    int level = 1 ,count=0;
    while(!q.empty()){
        int n = q.size();
        for(int i =0 ; i<n;i++){
            Node* frontNode = q.front();
            q.pop();
            if(frontNode->left) q.push(frontNode->left);
            if(frontNode ->right ) q.push(frontNode->right);
            
            if(!frontNode->right && !frontNode->left && (k-level)>=0){
                count++;k-=level;
            }
        }
        level++;
    }

  return count;
        
    }
};