/*
Product Pair
Given an integer array arr[] and an integer target, determine whether there exists a pair of elements in the array whose product is equal to target.

Return true if such a pair exists; otherwise, return false.

Examples:

Input: arr[] = [10, 20, 9, 40], target = 400
Output: true
Explanation: As 10 * 40 = 400, the answer is true.
Input: arr[] = [-10, 20, 9, -40], target = 30
Output: false
Explanation: No pair exists with product 30.
Input: arr[] = [-10, 0, 9, -40], target = 0
Output: true
Explanation: As -10 * 0 = 0, the answer is true.
Constraints:
2 ≤ arr.size ≤ 105
-108 ≤ arr[i] ≤ 108
-1018 ≤ target ≤ 1018
*/
/*
    APPROACH: Using Hashing
    1. Create an empty hash map to store the frequency of elements in the array.
    2. Iterate through each element in the array:
       a. If the current element is zero and the target is also zero, check if the hash map has a count greater than zero for zero. If it does, return true (since any non-zero element multiplied by zero will yield zero).
       b. If the current element is not zero, check if the target is divisible by the current element. If it is, calculate the required value (target divided by the current element) and check if this required value exists in the hash map with a count greater than zero. If it does, return true.
       c. Increment the count of the current element in the hash map.
    3. If the loop completes without finding a valid pair, return false.
*/
class Solution {
public:
    bool isProduct(vector<int>& arr, long long target) {

        unordered_map<long long, int> mp;

        for (long long x : arr) {

            // Handle zero separately
            if (x == 0) {

                if (target == 0 && mp[0] > 0)
                    return true;
            }
            else {

                if (target % x == 0) {

                    long long need = target / x;

                    if (mp[need] > 0)
                        return true;
                }
            }

            mp[x]++;
        }

        return false;
    }
};
/*
    APPROACH: Using Hashing
    1. Create an empty hash set to store the elements of the array.
    2. Iterate through each element in the array:
       a. If the current element is zero and the target is also zero, check if the hash set is not empty. If it is not empty, return true (since any non-zero element multiplied by zero will yield zero).
       b. If the current element is not zero, check if the target is divisible by the current element. If it is, calculate the required value (target divided by the current element) and check if this required value exists in the hash set. If it does, return true.
       c. Add the current element to the hash set.
    3. If the loop completes without finding a valid pair, return false.

    TIME COMPLEXITY: O(n), where n is the number of elements in the array.
    SPACE COMPLEXITY: O(n), due to the hash set storing the elements of the array.

*/
class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
          unordered_set<long long>seen;
        for(int i=0;i<arr.size();i++)
        {
            long long num=arr[i];
            if(num==0)
            {
                if(target==0&&!seen.empty())
                
                {
                    return true;
                }
            }
            else{
                if(target%num==0)
                {
                    long long  required =target/num;
                    if(seen.find(required)!=seen.end())
                    {
                        return true;
                    }
                }
            }
            seen.insert(num);
            
        }
        return false;
    }
};