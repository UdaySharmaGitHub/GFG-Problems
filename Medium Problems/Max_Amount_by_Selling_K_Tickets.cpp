/*
Max Amount by Selling K Tickets
Given an integer array arr[], where arr[i] denotes the number of tickets available with the i-th ticket seller.

The price of each ticket is equal to the number of tickets remaining with that seller at the time of sale. 
A seller can sell at most one ticket at a time, and after each sale, the price of the next ticket from that seller decreases by 1.
All sellers are allowed to sell at most k tickets in total.
Find the maximum amount that can be earned by selling k tickets. Return the answer modulo 109+7.

Examples:

Input: arr[] = [4, 3, 6, 2, 4], k = 3
Output: 15
Explanation: One optimal sequence is to sell two tickets from the seller with 6 tickets (the price of first would be 6 and second 5) and one ticket from a seller with 4 tickets. This gives a total earning of 6 + 5 + 4 = 15.
Input: arr[] = [5, 3, 5, 2, 4, 4], k = 2
Output: 10
Explanation: One optimal sequence is to sell one ticket each from the two sellers with 5 tickets, earning 5 + 5 = 10.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i], k ≤ 106
*/
class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
         int mod = 1000000007;
         int n = arr.size();
         priority_queue<int> q;
         for(int num:arr){
             q.push(num);
         }
         int res=0;
         int x;
          while(k&&!q.empty()){
              x = q.top();
             q.pop();
             res = (res + x) % mod;
             x--;
             k--;
            if (x){
            q.push(x);
            }
    }
    return res;
        
    }
};