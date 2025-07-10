/*
Find the longest string
Given an array of strings words[]. Find the longest string in words[] such that every prefix of it is also present in the array words[]. 
Note: If multiple strings have the same maximum length, return the lexicographically smallest one.
Examples:
Input: words[] = ["p", "pr", "pro", "probl", "problem", "pros", "process", "processor"]
Output: pros
Explanation: "pros" is the longest word with all prefixes ("p", "pr", "pro", "pros") present in the array words[].
Input: words[] = ["ab", "a", "abc", "abd"]
Output: abc
Explanation: Both "abc" and "abd" has all the prefixes in words[]. Since, "abc" is lexicographically smaller than "abd", so the output is "abc".
Constraints:
1 ≤ words.length() ≤ 103
1 ≤ words[i].length ≤ 103
*/
class Solution {
  public:
    string longestString(vector<string> &arr) {
        // code here
         sort(arr.begin(), arr.end());
        unordered_map<string, bool> map;
        
        for(int i=0; i<arr.size(); i++){
            
            if(arr[i].size() == 1)
                map[arr[i]] = true;
            
            else {
                string temp = arr[i];
                temp.pop_back();
                
                if(map[temp] == true)
                    map[arr[i]] = true;
                else 
                    map[arr[i]] = false;
            }
        }
        string ans = "";
        for(int i=0; i<arr.size(); i++){
            if(map[arr[i]] == true && arr[i].size() > ans.size())
                ans = arr[i];
        }
        
        return ans;
    }
};