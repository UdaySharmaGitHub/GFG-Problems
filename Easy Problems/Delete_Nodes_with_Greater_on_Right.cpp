/*
Delete Nodes with Greater on Right
Given a singly linked list, remove all nodes that have a node with a greater value anywhere to their right in the list. Return the head of the modified linked list.

Examples:

Input: LinkedList = 12->15->10->11->5->6->2->3
Output: 15->11->6->3

Explanation: Since, 12, 10, 5 and 2 are the elements which have greater elements on the following nodes. So, after deleting them, the linked list would like be 15, 11, 6, 3.
Input: LinkedList = 10->20->30->40->50->60
Output: 60

Explanation: All the nodes except the last node has a greater value node on its right, so all the nodes except the last node must be removed.
Constraints:
1 ≤ size of linked list ≤ 106
1 ≤ element of linked list ≤ 106
*/
/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
      Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    Node* compute(Node* head) {

        if (!head || !head->next)
            return head;

        head = reverse(head);

        int mx = head->data;
        Node* curr = head;

        while (curr && curr->next) {

            if (curr->next->data < mx) {
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
                mx = curr->data;
            }
        }

        return reverse(head);
}
};