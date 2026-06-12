/*
Check Repeated Substring with K Replacements
Given a string s and an integer k, check if it is possible to convert s to a string that is repetition of a substring with k characters else returns false. In order to convert we can replace one substring of length k with any k characters.

Note:  In one operation, you can replace any substring of length k whose starting index i (0-based) satisfies i % k == 0 with any sequence of k characters.

Examples:

Input: s = "abcbedabcabc",  k = 3
Output: true
Explanation: Replace "bed" with "abc" so that the whole string becomes repetition of "abc".
Input: s = "bdac", k = 2
Output: true
Explanation: The string can be divided into substrings of length k: ["bd", "ac"]. 
Since there are exactly two substrings and both are different, we can make them identical by replacing one substring with the other. Hence, the result is true.
Input: s = "abcdabcd", k = 2
Output: false
Explanation: Since we are allowed to change only one instance, we cannot covert.
Constraints:
2 ≤ k ≤ s.size() ≤ 105
*/
/*
    APPROACH:
    1. We can check if the length of the string is divisible by k, if not then we can return false.
    2. We can create a map to store the count of each substring of length k.
    3. If the size of the map is 1, then we can return true, as all the substrings are the same.
    4. If the size of the map is greater than 2, then we can return false, as we can only replace one substring.
    5. If the size of the map is 2, then we can check if    
         a. If one of the substrings has a count of 1 and its length is k, then we can replace it with the other substring and return true.
         b. Otherwise, we can return false. 

    Time Complexity: O(n), where n is the length of the string.
    Space Complexity: O(n), where n is the length of the string.
*/
class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        
        if(s.size()%k!=0) return 0;
        unordered_map<string ,int> map;
        for(int i =0 ; i<s.size();i+=k){
            string temp = s.substr(i,k);
            map[temp]++;
        }
        if(map.size()==1) return 1;
        if(map.size()>2) return 0;
        for(auto i:map){
            if(i.second == 1 && i.first.size()==k) return 1; 
        }
        return 0;
    }
};