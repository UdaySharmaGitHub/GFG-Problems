/*
Largest number in K swaps
Given a number k and string s of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of s at most k times.

Examples :

Input: s = "1234567", k = 4
Output: 7654321
Explanation: Three swaps can make the input 1234567 to 7654321, swapping 1 with 7, 2 with 6 and finally 3 with 5.
Input: s = "3435335", k = 3
Output: 5543333
Explanation: Three swaps can make the input 3435335 to 5543333, swapping 3 with 5, 4 with 5 and finally 3 with 4.
Input: s = "1034", k = 2
Output: 4301
Explanation: Two swaps can make the input 1034 to 4301, swapping 1 with 4 and finally 0 with 3. 
Constraints:
1 ≤ s.size() ≤ 15
1 ≤ k ≤ 7
*/
class Solution {
    public:
      // Function to find the largest number after k swaps.
        void Solve(string &ans,string str,int k,int idx){
        if(k==0 || idx>=str.size())
        return;
        char maxC=str[idx];
        for(int i=idx+1;i<str.size();i++){
            if(str[i]>maxC)
            maxC=str[i];
        }
        if(maxC!=str[idx])
        k--;
        for(int i=idx;i<str.size();i++){
            if(maxC==str[i]){
            swap(str[idx],str[i]);
            if(str.compare(ans)>0)
            ans=str;
            Solve(ans,str,k,idx+1);
            swap(str[idx],str[i]);
            }
        }
    }
      // Function to find the largest number after k swaps.
      string findMaximumNum(string& s, int k) {
          string ans=s;
          Solve(ans,s,k,0);
          return ans;
      }
  };