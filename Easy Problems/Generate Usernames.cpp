/*
Generate Usernames
Given an array of strings arr[]. The array represents first names of users, generate a unique username for each entry in the order it appears.

Initially, consider all usernames present in the input array as reserved.
If a username has not already been assigned to any previous user, keep it unchanged.
Otherwise, append the smallest positive integer suffix that produces a username that has not been reserved or assigned to any previous user.
Return the array of generated usernames.

Examples:

Input: arr[] = ["aba", "ab", "aba", "aba", "ab"]
Output: ["aba", "ab", "aba1", "aba2", "ab1"]
Explanation: The first occurrences of "aba" and "ab" are new, so they remain unchanged. The next "aba" is already used, so "aba1" is assigned. When "aba" appears again, "aba1" is already used, so "aba2" is assigned. Similarly, the second occurrence of "ab" becomes "ab1".
Input: arr[] = ["a", "a", "a1", "a"]
Output: ["a", "a2", "a1", "a3"]
Explanation: Initially, "a" and "a1" are reserved. The first occurrence of "a" retains its name. For the second occurrence, "a1" is already reserved, so the smallest available username is "a2". The original "a1" retains its name when processed. Finally, the last occurrence of "a" gets "a3".
Input: arr[] = ["aba1", "aba", "aba"]
Output: ["aba1", "aba", "aba2"]
Explanation: Initially, "aba1" and "aba" are reserved. The first occurrence of each retains its original name. For the second occurrence of "aba", "aba1" is already reserved, so "aba2" is assigned.
Constraints:

1 ≤ |arr| ≤ 103
1 ≤ |arr[i]| ≤ 102
arr consists of English alphabets and digits
*/
class Solution {
  public:
    vector<string> generateUsernames(vector<string> arr) {
        // code here
        vector<string> ans;
               unordered_map<string,bool> visited;

               for (auto x : arr) {
                   visited[x] = false;
               }

               for (int i=0;i<arr.size();i++) {

                   if (visited[arr[i]] == false) {
                       ans.push_back(arr[i]);
                       visited[arr[i]] = true;
                   } else {

                       string str = arr[i];
                       int k = 1;
                       string news = str;

                       while (visited.find(news) != visited.end()) {
                           news = str+to_string(k);
                           k++;
                       }

                       visited[news] = false;
                       ans.push_back(news);
                   }
               }

               return ans;
    }
};