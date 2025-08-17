/*
Insert Interval
Geek has an array of non-overlapping intervals intervals[][] where intervals[i] = [starti , endi] represent the start and the end of the ith event and intervals is sorted in ascending order by starti . He wants to add a new interval newInterval[] = [newStart, newEnd] where newStart and newEnd represent the start and end of this interval.
Help Geek to insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Examples:

Input: intervals[][] = [[1, 3], [4, 5], [6, 7], [8, 10]], newInterval[] = [5, 6]
Output: [[1, 3], [4, 7], [8, 10]]
Explanation: The newInterval [5, 6] overlaps with [4, 5] and [6, 7]. So, they are merged into one interval [4, 7].
Input: intervals[][] = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]], newInterval[] = [4, 9]
Output: [[1, 2], [3, 10], [12, 16]]
Explanation: The new interval [4, 9] overlaps with [3, 5], [6, 7] and [8, 10]. So, they are merged into one interval [3, 10].
Constraints:
1 ≤ intervals.size() ≤  105
0 ≤ starti ≤ endi ≤ 109
0 ≤ newStart ≤ newEnd ≤ 109
*/
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
 vector<vector<int>> res;
        
        int s=newInterval[0];
        int e=newInterval[1];
        int n=intervals.size();
        bool flag =true;
        
        for(int i=0;i<n;i++){
          
               if(intervals[i][1]<s){
                   res.push_back(intervals[i]);
                   continue;
               }
              
               if(intervals[i][0]>e){
                   if(flag){
                       res.push_back({s,e});
                       flag=false;
                   }
                   res.push_back(intervals[i]);
                   continue;
               }
               else{
                   s=min(s,intervals[i][0]);
                   e=max(e,intervals[i][1]);
               }
               
             
        }
        if(flag)res.push_back({s,e});
        return res;
    }
};
