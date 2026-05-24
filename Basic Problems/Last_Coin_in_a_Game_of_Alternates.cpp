/*
Last Coin in a Game of Alternates

Given an array integer arr[] , representing the values of coins arranged in a row.

Two players play a game by picking coins alternately.
At each turn, a player can pick a coin from either the beginning or the end of the array. Both players follow a greedy strategy, i.e., they always pick the coin with the maximum value among the two available ends.
The game continues until only one coin remains.
Find the value of the last remaining coin.

Examples:

Input : arr[] = [5, 3, 1, 6, 9]
Output : 1
Explanation:
Players always pick the larger coin from the two ends.
Pick 9, remaining array: [5, 3, 1, 6]
Pick 6, remaining array: [5, 3, 1]
Pick 5, remaining array: [3, 1]
Pick 3, remaining array: [1]
Final Output: 1
Input : arr[] = [5, 9, 2, 5]
Output : 2
Explanation:
Players always pick the larger coin from the two ends.
Pick 5, remaining array: [9, 2, 5]
Pick 9, remaining array: [2, 5]
Pick 5, remaining array: [2]
Final Output: 2
Input : arr[] = [11]
Output : 11
Explanation:
Only one coin is present in the array, so no moves are made.
Final Output: 11
Constraints :
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106
*/
class Solution {
  public:
      int coin(vector<int>& arr) {
        return *min_element(arr.begin(),arr.end());
    }
};