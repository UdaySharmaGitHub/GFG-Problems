/*
Minimum Insert and Delete to Convert
Given two arrays a[] and b[] of size n and m respectively, find the minimum insertions and deletions on the array a[], required to make both the arrays identical.

The array b[] is sorted and all its elements are distinct.
The array a[] may or may not be sorted and may have duplicates.
Operations can be performed at any index in a[] not necessarily at the end.
Examples :

Input: a[] = [1, 2, 5, 3, 1], b[] = [1, 3, 5]
Output: 4
Explanation:
Delete 2 from a: a[] = [1, 5, 3, 1]
Insert 3 after 1: a[] = [1, 3, 5, 3, 1]
Delete the last two elements: a[] = [1, 3, 5]
Total operations = 1 + 1 + 2 = 4.
Input: a[] = [1, 4], b[] = [1, 4]
Output : 0
Explanation: Both the Arrays are already identical.
 Constraints:
1 ≤ n, m ≤ 105
1 ≤ a[i], b[i] ≤ 105
*/
class Solution {
  public:
      int minInsAndDel(vector<int> &a, vector<int> &b) {
        vector<int> v;
        unordered_map<int,int> mp;
        for(int i = 0;i<b.size();i++){
            mp[b[i]]++;
        }
        for(int i = 0;i<a.size();i++){
            if(mp.find(a[i]) != mp.end()){
                v.push_back(a[i]);
            }
        }
        //finding LIS by B.S method.
        int cnt = 0;
        vector<int> w;
        w.push_back(v[0]);
        for(int i = 1;i<v.size();i++){
            if(v[i] > w[w.size()-1]){
                w.push_back(v[i]);
                continue;
            }
            int a = lower_bound(w.begin(),w.end(),v[i])-w.begin();
            w[a] = v[i];
        }
        return a.size()-w.size()+b.size()-w.size();
    }
};