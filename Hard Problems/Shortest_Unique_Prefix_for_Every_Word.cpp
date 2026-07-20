/*
Shortest Unique Prefix for Every Word
Given an array of strings arr[ ], find the shortest prefix of each string that uniquely identifies it among all strings in the array. A prefix is unique if it is not a prefix of any other string in the array. Return the shortest unique prefix for every string in the same order as the input.
Note: No string in the array is a prefix of another string.

Examples :

Input: arr[] = {"zebra", "dog", "duck", "dove"}
Output: z dog du dov
Explanation: z => zebra, dog => dog, duck => du, dove => dov 

Input: arr[] = {"geeksgeeks", "geeksquiz", "geeksforgeeks"}
Output: geeksg geeksq geeksf
Explanation: geeksgeeks => geeksg, geeksquiz => geeksq, geeksforgeeks => geeksf

Constraints:
1 ≤ length of arr, length of each word ≤ 1000
Expected Complexities
Time Complexity: O(n*length of each word)
Auxiliary Space: O(n*length of each word)
*/
class TrieNode {
public:
    TrieNode* child[26];
    int freq;

    TrieNode() {
        freq = 0;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string &word) {

        TrieNode* node = root;

        for(char ch : word) {

            int idx = ch-'a';

            if(node->child[idx]==NULL)
                node->child[idx]=new TrieNode();

            node=node->child[idx];
            node->freq++;
        }
    }

    string uniquePrefix(string &word) {

        TrieNode* node=root;

        string ans="";

        for(char ch:word){

            int idx=ch-'a';

            node=node->child[idx];

            ans+=ch;

            if(node->freq==1)
                break;
        }

        return ans;
    }

    vector<string> findPrefixes(vector<string>& arr) {

        for(auto &s:arr)
            insert(s);

        vector<string> ans;

        for(auto &s:arr)
            ans.push_back(uniquePrefix(s));

        return ans;
    }
};