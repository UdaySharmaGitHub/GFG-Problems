/*
Prime List
You are given the head of a linked list. You have to replace all the values of the 
nodes with the nearest prime number. If more than one prime number exists at an 
equal distance, choose the smallest one. Return the head of the modified linked list.
Examples :
Input: head = 2 → 6 → 10
Output: 2 → 5 → 11
Explanation: The nearest prime of 2 is 2 itself. The nearest primes of 6 are 5 and 7, since 5 is smaller so, 5 will be chosen. The nearest prime of 10 is 11.
Input: head = 1 → 15 → 20
Output: 2 → 13 → 19
Explanation: The nearest prime of 1 is 2. The nearest primes of 15 are 13 and 17, since 13 is smaller so, 13 will be chosen. The nearest prime of 20 is 19.
Constraints:
1 <= no. of Nodes <= 104
1 <= node.val <= 104
*/
/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/
class Solution {
    private:
      bool isPrime(int n){
          if(n<=1) return false;
          for(int i=2;i*i<=n;++i){
              if((n % i) == 0){
                  return false;
              }
          }
          return true;
      }
      
      int prevPrime(int n){
          
          for(int i=n-1;i>=2;--i){
              if(isPrime(i)){
                  return i;
              }
          }
          return -1;
      }
      
      int nextPrime(int n){
          
          for(int i=n+1;;i++){
              if(isPrime(i)){
                  return i;
              }
          }
      }
      
      
    public:
      Node *primeList(Node *head) {
          Node* temp=head;
          while(temp){
              if(temp->val==1){
                  temp->val=2;
              }else if(!isPrime(temp->val)){
                  int nxt=nextPrime(temp->val);
                  int prev=prevPrime(temp->val);
                  if(temp->val - prev ==  nxt-temp->val){
                      temp->val = prev;
                  }else if(temp->val-prev < nxt-temp->val){
                      temp->val=prev;
                  }else{
                      temp->val=nxt;
                  }
              }
              temp=temp->next;
          }
          return head;
      }
  }