/*
Seating Arrangement
Given an integer k representing the number of people to be seated and an array seats[], where 0 denotes an empty seat and 1 denotes an occupied seat.

Determine whether it is possible to seat all k people such that no two occupied seats are adjacent (including newly seated people).

Examples:

Input: k = 2, seats[] = [0, 0, 1, 0, 0, 0, 1]
Output: true
Explanation: The two people can sit at index 0 and 4.
Input: k = 1, seats[] = [0, 1, 0]
Output: false
Explanation: There is no way to get a seat for one person.
Input: k = 0, seats[] = [0, 0, 0, 1, 1]
Output: false
Explanation: The seating arrangement already contains two adjacent occupied seats at indices 3 and 4.
Constraints:
0 ≤ k ≤ 105
1 ≤ seats.size() ≤ 105
seats[i] == 0 or seats[i] == 1
*/
/*
    APPROACH
    1. First, we need to check if there are any adjacent occupied seats in the given seating arrangement. If there are, we can immediately return false, as it violates the condition of no two occupied seats being adjacent.
    2. If there are no adjacent occupied seats, we can then count the number of available seats (0s) that can be occupied without violating the adjacency condition. We can do this by iterating through the seats array and checking for empty seats that are not adjacent to occupied seats.
    3. For each empty seat, we check if the previous and next seats are also empty (or if we are at the beginning or end of the array). If they are, we can seat a person there and increment our count of available seats. We also skip the next seat to avoid seating another person adjacent to the one we just seated.
    4. Finally, we compare the count of available seats with k. If the count is greater than or equal to k, we can seat all k people, and we return true. Otherwise, we return false.

    TIME COMPLEXITY: O(n), where n is the number of seats.
    SPACE COMPLEXITY: O(1), as we are using only a constant amount of extra space.
*/
class Solution {
  public:
       bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
        int n =  seats.size();
        for(int i=1;i<n;i++){
            if(seats[i-1]==1&&seats[i]==1)return false;
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(seats[i]==0&&(i-1<0||seats[i-1]==0)&&(i+1==n||seats[i+1]==0)){
                count++;
                i++;
            }
        }
        return (count>=k)?true:false;
    }
};