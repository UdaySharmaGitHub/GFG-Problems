/*
Nine Divisors
Given a positive integer n, you need to count the numbers less than or equal to n having exactly 9 divisors.
Examples :
Input: n = 100
Output: 2
Explanation: Numbers which have exactly 9 divisors are 36 and 100.
Input: n = 200
Output: 3
Explanation: Numbers which have exactly 9 divisors are 36, 100, 196. 
Constraints:
1 ≤ n ≤ 109
*/
class Solution {
  public:
     bool has9div(int x){
      // finding divs of the numbers. 
      int cnt = 0;
      
      for(int i=1; i*i<=x; i++){
          if(x%i==0 && x!=i*i) cnt+=2;
          else if(x%i==0) cnt++;
          if(cnt>9) return false;
      }
      
      return cnt==9;
      
  }
  
  
    int countNumbers(int n) {
        // Code Here
        int ans = 0;
        
        // as from example 36 is the first one. 
        for(int i=6; i*i<=n; i++){
            if(has9div(i*i)){
                ans++;
            }
        }
        return ans;
        
        
    }
};