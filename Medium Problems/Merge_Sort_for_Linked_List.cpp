/*
Merge Sort for Linked List
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.
Example 1:
Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.
Example 2:
Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15
Explanation: After sorting the given
linked list , resultant will be
0->9->15.
Your Task:
For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.
Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N)
Constraints:
1 <= N <= 105
*/
//{ Driver Code Starts
/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
/*
    Approach: Using the Merge Sort Algorithm to sort the linked list.
    Time Complexity: O(max(m,n)) where m and n are the lengths of the two linked lists.
    Space Complexity: O(1) as we are not using any extra space for sorting.
*/
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        if(!head1 && !head2) return nullptr;
        if(!head1) return head2;
        if(!head2) return head1;
        Node* res = new Node(-1);
        Node* temp = res;
        while(head2  && head1){
            if(head1 ->data >head2->data){
                temp->next = head2;
                temp = head2;
                head2 = head2->next;
            }
            else{
                temp->next = head1;
                temp = head1;
                head1 =head1->next;
            }
        }
        if(!head1) temp->next =head2;
        else temp->next = head1;
        return res->next;
    }
};
/*
    Approach: Using the Sort function of the vector to sort the elements and then create a new linked list with the sorted elements.
    Time Complexity: O(N*Log(N)) where N is the number of nodes in the linked list.
    Space Complexity: O(N) where N is the number of nodes in the linked list.
*/
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        vector<int> ans;
        while(head1) ans.push_back(head1->data),head1 = head1->next;
        while(head2)ans.push_back(head2->data),head2 = head2->next;
        sort(ans.begin(),ans.end());
        Node* head =nullptr , *tail = nullptr;
        for(int i:ans){
            Node* node = new Node(i);
            if(!head && !tail){
                head = node;
                tail = head;
            }
            else{
                tail->next = node;
                tail = node;
            }
        }
        return head;
    }
};