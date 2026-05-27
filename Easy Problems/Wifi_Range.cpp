/*
Wifi Range
There are n rooms in a straight line in Geekland State University's hostel. You are given a binary string s of length n, where s[i] = '1' means there is a WiFi router in the i-th room, and s[i] = '0' means there is no WiFi in that room.

Each WiFi router has a range of x, meaning it can cover up to x rooms to its left and x rooms to its right.

Given x and s, determine whether all rooms are covered by at least one WiFi router. Return true if all rooms are covered; otherwise, return false.

Examples: 

Input: x = 0, s = "010"
Output: false
Explanation: Since the range is 0, so Wifi is only accessible in second room while 1st & 3rd room have no wifi. Therefore answer is false for this test case.
Input: x = 1, s = "10010"
Output: true
Explanation: 
Index 0: WiFi is available.
Index 1: Since the range of the 0th index is 1, WiFi is available here.
Index 2: Since the range of the 3rd index is 1, WiFi is also available here.
Index 3: WiFi is available.
Index 4: The range of the 3rd index covers this position.
So, all the rooms have WiFi. Therefore, the answer is true for this test case. 
Constraints:
1 ≤ n ≤ 105
0 ≤ x ≤ 105
*/
/*
    APPROACH:
    1. We can use a difference array to keep track of the coverage of WiFi routers.
    2. For each router found in the string, we will mark the start and end of its coverage in the difference array.
    3. After processing all routers, we will iterate through the difference array to calculate the cumulative coverage for each room.
    4. If any room has zero coverage, we return false. If all rooms have coverage, we return true.

    Time Complexity: O(n) - We traverse the string once to build the difference array and once more to check coverage.
    Space Complexity: O(n) - We use an additional array to store the difference values.
*/
class Solution {
  public:
     bool wifiRange(string &s, int x) {
        
        int n = s.length();
        vector<int> diff(n + 1, 0);
        
        for(int i = 0; i < n; i++) {
            
            if(s[i] == '1') {
                
                int left = max(0, i - x);
                int right = min(n - 1, i + x);
                
                diff[left]++;
                
                if(right + 1 < n)
                    diff[right + 1]--;
            }
        }
        
        int coverage = 0;
        
        for(int i = 0; i < n; i++) {
            
            coverage += diff[i];
            
            if(coverage <= 0)
                return false;
        }
        
        return true;
    }
};