/*
Numbers with Given Digit Sum
Given two integers n and sum, determine the number of n-digit positive integers whose digits add up to sum.

An n-digit number cannot have leading zeros; that is, the first digit must be between 1 and 9.
If there exist no n digit number with sum of digits equal to given sum, return -1.
Examples :

Input: n = 2, sum = 2
Output: 2
Explaination: The valid 2-digit numbers whose digits sum to 2 are 11 and 20.
Input: n = 1, sum = 10
Output: -1
Explaination: A single-digit number can only have a digit sum between 0 and 9.
Input: n = 2, sum = 10
Output: 9
Explaination: The 2-digit numbers whose digits add up to 10 are: 19, 28, 37, 46, 55, 64, 73, 82, 91.
Constraints:
1 ≤ n ≤ 9
1 ≤ sum ≤ 81
*/
class Solution {
  public:
    // set<string> st;
    // void fun(int id,string s,int cur,int n,int sum){
    //     if(id==n){
    //         if(cur==sum)st.insert(s);
    //         return;
    //     }
    //     for(int i=0;i<=9;i++){
    //         if( id==0 && i==0 ){
    //             continue;
    //         }
    //         if(cur+i<=sum){
    //             s.push_back(i+'0');
    //             fun(id+1,s,cur+i,n,sum);
    //             s.pop_back();
    //         }
    //     }
    //     return;
    // }
    
    int fun(int id,int cur,int n,int sum,vector<vector<int>>&dp){
        if(id==n){
            if(cur==sum){
                return 1;
            }
            return 0;
        }
        
        if( dp[id][cur] != -1 ){
            return dp[id][cur];
        }
        
        int ans=0;
        for(int i=0;i<=9;i++){
            if( id==0 && i==0 ){
                continue;
            }
            if(cur+i<=sum){
                int c=fun(id+1,cur+i,n,sum,dp);
                ans+=c;
            }
        }
        return dp[id][cur]=ans;
    }
    int countWays(int n, int sum) {
        // code here
        //fun(0,"",0,n,sum);
        //dp
        vector< vector<int> > dp(n,vector<int>(sum+1,-1));
        int ans=fun(0,0,n,sum,dp);
        if( ans == 0 ) return -1;
        return ans;
        // if(st.size()==0){
        //     return -1;
        // }
        // return (int)st.size();
    }
};