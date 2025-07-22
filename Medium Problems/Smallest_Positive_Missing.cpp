/*
Smallest Positive Missing
You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.
Note: Positive number starts from 1. The array can have negative integers too
Examples:
Input: arr[] = [2, -3, 4, 1, 1, 7]
Output: 3
Explanation: Smallest positive missing number is 3.
Input: arr[] = [5, 3, 2, 5, 1]
Output: 4
Explanation: Smallest positive missing number is 4.
Input: arr[] = [-8, 0, -1, -4, -3]
Output: 1
Explanation: Smallest positive missing number is 1.
Constraints:  
1 ≤ arr.size() ≤ 105
-106 ≤ arr[i] ≤ 106
*/
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int maxa = 0 , mina = 1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0) mina = min(mina ,arr[i]);
            maxa = max(maxa,arr[i]);
        }
        vector<int> freq(maxa+1,0);
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0) freq[arr[i]]++;
        }
        int ans = -1;
        for(int i=mina ;i<=maxa ;i++){
            if(freq[i] == 0){ ans = i ; break;}
        }
        return (ans== -1)?(maxa+1):ans;
    }
};