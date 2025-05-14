/*
Look and Say Pattern
Given an integer n. Return the nth row of the following look-and-say pattern.
1
11
21
1211
111221
Look-and-Say Pattern:

To generate a member of the sequence from the previous member, read off the digits of the previous member, counting the number of digits in groups of the same digit. For example:

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
1211 is read off as "one 1, one 2, then two 1s" or 111221.
111221 is read off as "three 1s, two 2s, then one 1" or 312211.
Examples:

Input: n = 5
Output: 111221
Explanation: The 5th row of the given pattern will be 111221.
Input: n = 3
Output: 21
Explanation: The 3rd row of the given pattern will be 21.

Constraints:
1 ≤ n ≤ 30
*/
//User function template for C++

//------------------APPROACH-1---------------------------///

class Solution {
  public:
    string countAndSay(int n) {
        // code here
        string ans = "1" , res = "";
        if(n==1) return ans;
        for(int i=1;i<n;i++){
            stack<char> st;
            for(char ch:ans){
                if(st.empty()) st.push(ch);
                else{   if(st.top() != ch){
                            res+=('0'+st.size());
                            res+=st.top();
                            st = stack<char>();
                        }
                        st.push(ch);

                }
            }
            if(!st.empty()){
                            res+=('0'+st.size());
                            res+=st.top();
                            st = stack<char>();
            }
            ans= res;
            res ="";
        }
        return ans;
    }
};


//------------------APPROACH-2---------------------------///
class Solution
{
  public:
    string lookandsay(int n) {
        // code here
	// Base cases
	if (n == 1)	 return "1";
	if (n == 2)	 return "11";

	// Find n'th term by generating all terms from 3 to
	// n-1. Every term is generated using previous term
	string str = "11"; // Initialize previous term
	for (int i = 3; i<=n; i++)
	{
		// In below for loop, previous character
		// is processed in current iteration. That
		// is why a dummy character is added to make
		// sure that loop runs one extra iteration.
		str += '$';
		int len = str.length();

		int cnt = 1; // Initialize count of matching chars
		string tmp = ""; // Initialize i'th term in series

		// Process previous term to find the next term
		for (int j = 1; j < len; j++)
		{
			// If current character doesn't match
			if (str[j] != str[j-1])
			{
				// Append count of str[j-1] to temp
				tmp += cnt + '0';

				// Append str[j-1]
				tmp += str[j-1];

				// Reset count
				cnt = 1;
			}

			// If matches, then increment count of matching
			// characters
			else cnt++;
		}

		// Update str
		str = tmp;
	}

	return str;
    }   
};