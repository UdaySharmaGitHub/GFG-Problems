/*
Power of k in factorial of n
Given two positive integers n and k, determine the highest value of x such that kx divides n! (n factorial) completely (i.e., n % (kx) == 0).
Examples :
Input: n = 7, k = 2
Output: 4
Explanation: 7! = 5040, and 24 = 16 is the highest power of 2 that divides 5040.
Input: n = 10, k = 9
Output: 2
Explanation: 10! = 3628800, and 9² = 81 is the highest power of 9 that divides 3628800.
Constraints:
1 ≤ n ≤ 105
2 ≤ k ≤ 105
*/
class Solution {
  public:
      int maxKPower(int n, int k) {
        map<int,int> primeFactor;
        for(int i=2;i*i<=k;i++){
            while(k%i==0){
                primeFactor[i]++;
                k=k/i;
            }
        }
        if(k>1) primeFactor[k]++;
        int ans=INT_MAX;
        for(auto &it:primeFactor){
            int p=it.first;
            int lnk=it.second;
            
            int powerinNFact=0;
            int temp=n;
            while(temp){
                powerinNFact+=temp/p;
                temp/=p;
            }
            ans=min(ans,powerinNFact/lnk);
            
        }
        return ans;
    }
};