/*
Palindrome Pairs
Given an array arr[] consisting of n strings. Determine whether there exists a pair of indices (i, j) such that i ≠ j and the concatenation arr[i] + arr[j] forms a palindrome.

Return true if such a pair exists; otherwise, return false.

Note: A string is considered a palindrome if it reads the same forward and backward.

Examples:

Input: arr[] = ["geekf", "geeks", "or", "keeg", "abc", "bc"]
Output: true
Explanation: There is a pair "geekf" and "keeg". Their concatenation "geekfkeeg" is a palindrome.
Input: arr[] = ["abc", "xyxcba", "geekst", "or", "bc"]
Output: true
Explanation: There is a pair "abc" and "xyxcba". Their concatenation "abcxyxcba" is a palindrome.
Input: arr[] = ["aa"]
Output: false
Explanation: There is only one string present, so the output is false.
Constraints:
1 ≤ n ≤ 2*104
1 ≤ |arr[i]| ≤ 10
*/
/*
    APPROACH:
    1. We can use a hash map to store the strings and their indices.
    2. For each string in the array, we can split it into two parts: left and right.
    3. We can check if the left part is a palindrome and if the reverse of the right part exists in the hash map. If it does, we can return true.
    4. We can also check if the right part is a palindrome and if the reverse of the left part exists in the hash map. If it does, we can return true.
    5. If we iterate through all the strings and do not find any such pair, we can return false.

    TIME COMPLEXITY: O(n * k^2), where n is the number of strings and k is the maximum length of a string.
    SPACE COMPLEXITY: O(n * k), where n is the number of strings and k is the maximum length of a string.
*/
class Solution {
  public:
     bool isPalindrome(string &s, int left, int right) {
        
        while(left < right) {
            
            if(s[left] != s[right]) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
    
    bool palindromePair(vector<string>& arr) {
        
        unordered_map<string, int> mp;
        
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
        }
        
        for(int i = 0; i < arr.size(); i++) {
            
            string word = arr[i];
            int n = word.length();
            
            for(int j = 0; j <= n; j++) {
                
                string left = word.substr(0, j);
                string right = word.substr(j);
                
                if(isPalindrome(word, 0, j - 1)) {
                    
                    string revRight = right;
                    reverse(revRight.begin(), revRight.end());
                    
                    if(mp.count(revRight) && mp[revRight] != i) {
                        return true;
                    }
                }
                
                if(j != n && isPalindrome(word, j, n - 1)) {
                    
                    string revLeft = left;
                    reverse(revLeft.begin(), revLeft.end());
                    
                    if(mp.count(revLeft) && mp[revLeft] != i) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};