/*
Count Reverse Pairs
You are given an array arr[] of positive integers, find the count of reverse pairs. A pair of indices (i, j) is said to be a reverse pair if both the following conditions are met:
0 ≤ i < j < arr.size()
arr[i] > 2 * arr[j]
Examples:
Input: arr[] = [3, 2, 4, 5, 1, 20]
Output: 3
Explanation:
The Reverse pairs are
(0, 4), arr[0] = 3, arr[4] = 1, 3 > 2*1
(2, 4), arr[2] = 4, arr[4] = 1, 4 > 2*1
(3, 4), arr[3] = 5, arr[4] = 1, 5 > 2*1
Input: arr[] = [5, 4, 3, 2, 2]
Output: 2
Explanation:
The Reverse pairs are
(0, 3), arr[0] = 5, arr[3] = 2, 5 > 2*2
(0, 4), arr[0] = 5, arr[4] = 2, 5 > 2*2
Constraints:
1 ≤ arr.size() ≤ 5*104
1 ≤ arr[i] ≤ 109
*/
class Solution
{
public:
    int rcount = 0;
    void merge(vector<int> &vec, int start, int mid, int end)
    {
        int j = mid + 1;
        for (int i = start; i <= mid; i++)
        {
            while (j <= end && vec[i] > 2 * vec[j])
            {
                j++;
            }
            rcount += (j - (mid + 1));
        }
        int i = start;
        j = mid + 1;
        vector<int> b;
        while (i <= mid && j <= end)
        {
            if (vec[i] <= vec[j])
            {
                b.push_back(vec[i]);
                i++;
            }
            else
            {
                b.push_back(vec[j]);
                j++;
            }
        }
        if (i <= mid)
        {
            while (i <= mid)
            {
                b.push_back(vec[i]);
                i++;
            }
        }
        else if (j <= end)
        {
            while (j <= end)
            {
                b.push_back(vec[j]);
                j++;
            }
        }
        int k = start;
        for (int m = 0; m < b.size(); m++)
        {
            vec[k] = b[m];
            k++;
        }
        return;
    }
    void merge_sort(vector<int> &vec, int start, int end)
    {
        if (start < end)
        {
            int mid = (start + end) / 2;
            merge_sort(vec, start, mid);
            merge_sort(vec, mid + 1, end);
            merge(vec, start, mid, end);
        }
        else
        {
            return;
        }
    }
    int countRevPairs(vector<int> &arr)
    {
        int n = arr.size();
        merge_sort(arr, 0, n - 1);
        return rcount;
    }
};