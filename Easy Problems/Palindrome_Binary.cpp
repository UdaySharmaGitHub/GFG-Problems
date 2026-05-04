/*
Palindrome Binary
Given an integer n, determine whether its binary representation forms a palindrome. Return true if the binary representation of n is a palindrome; otherwise, return false.

Note: A binary representation is considered a palindrome if it reads the same forward and backward.

Examples:

Input: n = 17
Output: true
Explanation: Binary representation of 17 is (10001)2, which reads the same forward and backward, so it is a palindrome. 
Input: n = 16
Output: false
Explanation: Binary representation of 16 is (10000)2, which is not a palindrome. 
Constraints:
1 ≤ n ≤ 109
*/
/*
    Approach:
    1. We can convert the given number to its binary representation and store the bits in a vector.
    2. Then, we can use two pointers to check if the binary representation is a palindrome. We can initialize one pointer at the beginning of the vector and another pointer at the end of
         the vector. We can compare the bits at these two pointers and move the pointers towards each other until they meet or cross each other.
    3. If we find any pair of bits that are not the same, we can return false. If we successfully compare all pairs of bits and find that they are the same, we can return true.

    Time Complexity: O(log n) - This is because we are converting the number to binary and checking for palindrome, which takes logarithmic time in relation to the value of n.
    Space Complexity: O(log n) - This is because we are storing the binary representation of the number in a vector, which takes logarithmic space in relation to the value of n.

*/
class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        vector<int> bits;
        while(n){
            bits.push_back(n%2);n/=2;
        }
        int i =0 , j = bits.size()-1;
        while(i<j)if(bits[i++]!=bits[j--]) return 0;
        return 1;
    }
};
