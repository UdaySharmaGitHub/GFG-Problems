/*
Special Keyboard
Given a special keyboard that contains only four keys:

Key 1: Prints a single character 'A' on the screen.
Key 2 (Ctrl + A): Selects all the characters currently present on the screen.
Key 3 (Ctrl + C): Copies the selected characters to a buffer, overwriting its previous content.
Key 4 (Ctrl + V): Pastes the content of the buffer onto the screen, appending it to the existing text.
Initially, the screen is empty and the buffer is also empty.
Determine the maximum number of 'A' characters that can be displayed on the screen after performing exactly n key presses.
Examples :
Input: n = 3
Output: 3
Explanation: With only 3 key presses, the best option is to press Key 1 each time. So, the screen shows "AAA" and the total number of A’s is 3.
Input: n = 7
Output: 9
Explanation: An optimal sequence is: press Key 1 three times to get "AAA", then use Key 2 (select all) and Key 3 (copy), followed by Key 4 twice (paste). This results in "AAAAAAAAA", so the total number of A’s is 9.
Constraints:
1 ≤ n ≤ 70
*/
class Solution {
  public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        // code here
        int m = b.size();
        int n = a.size();
        vector<int>ans;
        vector<int>lps(m,0);
        lps[0]=0;
        
        int first = 0;
        int second = 1;
        
        // finding LPS
        while(second<m){
            
            if(b[first]==b[second]){
                lps[second] = first+1;
                first++;
                second++;
            }
            else if(first==0){
                lps[second]=0;
                second++;
            }
            else first = lps[first-1];
            
            
        }
        // string matching;
        b.push_back(-1);
        lps.push_back(0);
        first = 0;
        second = 0;
        
        while(second<n){
            
            if(b[first]==a[second]){
                first++;
                second++;
            }
            else if(first==0)second++;
            else{
                
                if(first==m)ans.push_back(second-m);
                first = lps[first-1];
            }
            
        }
        
        if(second==n && first==m)ans.push_back(second-m);
        return ans;
        
        
    }
};