/*
K-th element of two Arrays
Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the kth position of the final sorted array.
Example 1:
Input:
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6
Explanation:
The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.
Example 2:
Input:
arr1[] = {100, 112, 256, 349, 770}
arr2[] = {72, 86, 113, 119, 265, 445, 892}
k = 7
Output:
256
Explanation:
Final sorted array is - 72, 86, 100, 112,
113, 119, 256, 265, 349, 445, 770, 892
7th element of this array is 256.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function kthElement() which takes the arrays arr1[], arr2[], its size N and M respectively and an integer K as inputs and returns the element at the Kth position.
Expected Time Complexity: O(Log(N) + Log(M))
Expected Auxiliary Space: O(Log (N))
Constraints:
1 <= N, M <= 106
0 <= arr1i, arr2i < INT_MAX
1 <= K <= N+M
*/
// Time Complexity: O(n) 
// Auxiliary Space : O(1) 
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i =0 , j=0,d=0;
        while(i<n && j<m){
            if(arr1[i] <arr[j]){
                d++;
                if(d==k) return arr1[i];
                i++;
            }
            else{
                d++;
                if(d==k) return arr2[j];
                j++;
            }
        }
        // If array arr2[] is completely traversed
    while(i < n) 
    {
        k++;
        if(d == k)
            return arr1[i];
        i++;
    }

    // If array arr1[] is completely traversed
    while(j < m) 
    {
        d++;
        if(d == k)
            return arr2[j];
        j++;
    }
    }
};

// Time Complexity: O(n) 
// Auxiliary Space : O(m + n) 
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int> ans;
        int i=0 ,j=0;
        while(i<n && j<m){
            if(arr1[i] > arr2[j]){
                ans.push_back(arr2[j]);
                j++;
            }
            else{
                ans.push_back(arr1[i]);
                i++;
            }
        }
        while(i<n){
            ans.push_back(arr1[i]);
                i++;
        }
        while(j<m){
            ans.push_back(arr2[j]);
                j++;
        }
        return ans[k-1];
        
    }
};