/*
Number of Turns in Binary Tree
Given root of a binary tree and the values of its two nodes p and q, count turns required to travel from node p to q.
A turn occurs whenever the direction of movement changes from left to right or right to left while traversing the tree.
If the path between the two nodes does not involve any turns (i.e., the nodes lie on the same straight path), return -1.
Note: All node values are distinct.
Examples :
Input: root[] = [1, 2, 3, 4, 5, 6, 7, 8, N, N, N, 9, 10], p = 5, q = 10
Output: 4
Explanation: The path from node 5 to node 10 is: 5 -> 2 -> 1 -> 3 -> 6 → 10. Direction changes occur at nodes 2, 1, 3, and 6. Therefore, the number of turns is 4.
Input: root[] = [1, 2, 3, 4, 5, 6, 7, 8, N, N, N, 9, 10], p = 1, q = 4
Output: -1
Explanation: No turn is required since they are in a straight line.
Constraints:
1 ≤ n ≤ 104, n is the number of nodes
1 ≤ node->data ≤ 104
1 ≤ p, q ≤ n
*/
class Solution {
    private:
    Node* LCS(Node* root,int p,int q){
        if(root==NULL || root->data==p || root->data==q){
            return root;
        }

        Node* left=LCS(root->left,p,q);
        Node* right=LCS(root->right,p,q);

        if(left && right){
            return root;
        }

        else if(left){
            return left;
        }

        else {
            return right;
        }
    }

    int solver(Node* root,int p,int q,int prev){
        if(root==NULL){
            return 1e9;
        }

        if(root->data==p || root->data==q){
            return 0;
        }

        int ans=1e9;

        if(!prev){
            ans=min({ans,0+solver(root->left,p,q,0),1+solver(root->right,p,q,1)});
        }

        else{
            ans=min({ans,1+solver(root->left,p,q,0),0+solver(root->right,p,q,1)});
        }

        return ans;
    }
  public:
    int numberOfTurns(Node* root, int p, int q) {
        // code here
        Node* point=LCS(root,p,q);

        int left=solver(point->left,p,q,0);
        int right=solver(point->right,p,q,1);

        int ans=0;
        if(left<1e9){
            ans+=left;
        }

        if(right<1e9){
            ans+=right;
        }

        ans++;

        if(point->data==p || point->data==q){
            ans--;
        }

        if(ans==0){
            return -1;
        }


        return ans;
    }
};