/*
Sum of Mode
Given an array arr[] of positive integers and an integer k. You have to find the sum of the modes of all the subarrays of size k.
Note: The mode of a subarray is the element that occurs with the highest frequency. If multiple elements have the same highest frequency, the smallest such element is considered the mode.
Examples:
Input: arr[] = [1, 2, 3, 2, 5, 2, 4, 4], k = 3
Output: 13
Explanation: The mode of each k size subarray is [1, 2, 2, 2, 2, 4] and sum of all modes is 13.
Input: arr[] = [1, 2, 1, 3, 5], k = 2
Output: 6
Explanation: The mode of each k size subarray is [1, 1, 1, 3] and sum of all modes is 6.
Constraints:
1 ≤ k ≤ arr.size() ≤105
1 ≤ arr[i] ≤ 105
*/
class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
// code here
        map<int,int>mp;
        
        int n = arr.size();
        for(int i = 0; i < k; i++){
            mp[arr[i]]++;
        }
        multiset<int>am;
        vector<int>freq;
        for(auto i : mp){
            am.insert(i.second);
        }
        
        int sum = 0;
        freq.push_back(*--am.end());
        for(int i = k; i < n; i++){
            
            if(mp.find(arr[i]) != mp.end()){
                am.erase(am.find(mp[arr[i]]));
                mp[arr[i]]++;
            }else{
                mp[arr[i]]++;
            }
            am.insert(mp[arr[i]]);
            
            if(mp[arr[i - k]] == 1){
                am.erase(am.find(1));
                mp.erase(arr[i - k]);
            }else {
                am.erase(am.find(mp[arr[i - k]]));
                mp[arr[i - k]]--;
                am.insert(mp[arr[i - k]]);
            }
            freq.push_back(*--am.end());
        }
        map<int,set<int>>ss;
        
        map<int,int>deu;
        for(int i = 0; i < k; i++){
            
            if(deu.find(arr[i]) != deu.end()){
                ss[deu[arr[i]]].erase(arr[i]);
            }
            
            deu[arr[i]]++;
            ss[deu[arr[i]]].insert(arr[i]);
        }
        for(int i = k; i <= n; i++){
            
            sum += *ss[freq[i - k]].begin();
            if(i == n) break;
            if(deu[arr[i - k]] ==  1){
                ss[1].erase(arr[i - k]);
                deu.erase(arr[i - k]);
            } else{
                ss[deu[arr[i - k]]].erase(arr[i - k]);
                deu[arr[i - k]]--;
                ss[deu[arr[i - k]]].insert(arr[i - k]);
            }
            
            if(deu.find(arr[i]) != deu.end()){
                ss[deu[arr[i]]].erase(arr[i]);
            }
            
            deu[arr[i]]++;
            ss[deu[arr[i]]].insert(arr[i]);
        }
        return sum;        
    }
};