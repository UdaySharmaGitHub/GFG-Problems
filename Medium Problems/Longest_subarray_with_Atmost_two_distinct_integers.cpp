/*
Longest subarray with Atmost two distinct integers
Given an array arr[] consisting of positive integers, your task is to find the length of the longest subarray that contains at most two distinct integers.
Examples:
Input: arr[] = [2, 1, 2]
Output: 3
Explanation: The entire array [2, 1, 2] contains at most two distinct integers (2 and 1). Hence, the length of the longest subarray is 3.
Input: arr[] = [3, 1, 2, 2, 2, 2]
Output: 5
Explanation: The longest subarray containing at most two distinct integers is [1, 2, 2, 2, 2], which has a length of 5.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
*/
/*
     Using Sliding Window - O(n) Time and O(1) Space
*/
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int,int> map;
        int i =0  , j = 0 ,count = 0;
        int size =0;
        while(j<arr.size()){
            map[arr[j]]++;
            while(map.size()>2){
                map[arr[i]]--;
                if(map[arr[i]]  == 0 ) map.erase(arr[i]);
                i++;
            }
            count = max(count , j - i +1);
            j++;
        }
        return count ;
    }
};
/*
    Generate all subarrays, efficiently check distinct elements - O(n^2) Time and O(1) Space
*/
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int count = 0;
        for(int i=0;i<arr.size();i++){
            unordered_map<int,int> map;
            int distinct = 0;
            for(int j = i ;j<arr.size();j++){
                if(map[arr[j]]==0) distinct++;
                map[arr[j]]++;
                if(distinct>2) break;
                count  = max(count ,j - i +1);
            }
            
        }
        return count;
    }
};
/*
    Generate all subarrays - O(n^3) Time and O(1) Space
*/
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int count =0 ;
    for(int i =0 ; i<arr.size();i++){
        for(int j =i;j<arr.size();j++){
            unordered_set<int> set;
            for(int k = i ;k<=j;k++){
                set.insert(arr[k]);
                if(set.size()>2){break;}
            }
            if(set.size()<=2) count = max(count , j-i+1);
        }
        
    }
    return count;
    }
};