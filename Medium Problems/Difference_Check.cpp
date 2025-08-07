/*
Difference Check
Given an array arr[] of time strings in 24-hour clock format "HH:MM:SS", return the minimum difference in seconds between any two time strings in the arr[].
The clock wraps around at midnight, so the time difference between "23:59:59" and "00:00:00" is 1 second.
Examples:
Input: arr[] = ["12:30:15", "12:30:45"]
Output: 30
Explanation: The minimum time difference is 30 seconds.
Input: arr[] = ["00:00:01", "23:59:59", "00:00:05"]
Output: 2
Explanation: The time difference is minimum between "00:00:01" and "23:59:59".
Constraints:
2 ≤ arr.size() ≤ 105
arr[i] is in "HH:MM:SS" format.
*/
class Solution {
  public:
   int findDiff(string s1, string s2){
        int hour1, minute1, second1;
        char sep;
    
        stringstream ss(s1);
        ss >> hour1 >> sep >> minute1 >> sep >> second1;
        
        int hour2, minute2, second2;
        stringstream sss(s2);
        sss >> hour2 >> sep >> minute2 >> sep >> second2;
        
        int time1 = hour1*3600 + minute1*60 + second1;
        int time2 = hour2*3600 + minute2*60 + second2;
        
        return time2-time1;
        
    }
    int minDifference(vector<string> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int mini = INT_MAX;
        for(int i=0; i<arr.size()-1; i++){
            mini = min(mini, findDiff(arr[i], arr[i+1]));
        }
        
        int time1 = findDiff(arr[arr.size()-1], "24:00:00");
        int time2 = findDiff("00:00:00", arr[0]);
        
        return min(mini, time1+time2);
       
    }
};
