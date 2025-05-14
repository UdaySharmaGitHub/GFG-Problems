/*
Meeting Rooms III
You are given an integer n representing the number of rooms numbered from 0 to n - 1. Additionally, you are given a 2D integer array meetings[][] where meetings[i] = [starti, endi] indicates that a meeting is scheduled during the half-closed time interval [starti, endi). All starti values are unique.

Meeting Allocation Rules:

When a meeting starts, assign it to the available room with the smallest number.
If no rooms are free, delay the meeting until the earliest room becomes available. The delayed meeting retains its original duration.
When a room becomes free, assign it to the delayed meeting with the earliest original start time.
Determine the room number that hosts the most meetings. If multiple rooms have the same highest number of meetings, return the smallest room number among them.

Examples:

Input: n = 2, meetings[][] = [[0, 6], [2, 3], [3, 7], [4, 8], [6, 8]]
Output: 1
Explanation: Time 0: Both rooms available. [0,6] starts in room 0.
Time 2: Room 0 busy until 6. Room 1 available. [2,3] starts in room 1.
Time 3: Room 1 frees up. [3,7] starts in room 1.
Time 4: Both rooms busy. [4,8] is delayed.
Time 6: Room 0 frees up. Delayed [4,8] starts in room 0 [6,10).
Time 6: [6,8] arrives but both rooms busy. It’s delayed.
Time 7: Room 1 frees up. Delayed [6,8] starts in room 1 [7,9).
Meeting counts: [2, 3]
Input: n = 4, meetings[][] = [[0, 8], [1, 4], [3, 4], [2, 3]
Output: 2
Explanation: Time 0: All rooms available. [0,8] starts in room 0.
Time 1: Room 0 busy until 8. Rooms 1, 2, 3 available. [1,4] starts in room 1.
Time 2: Rooms 0 and 1 busy. Rooms 2, 3 available. [2,3] starts in room 2.
Time 3: Room 2 frees up. [3,4] starts in room 2.
Meeting counts: [1, 1, 2, 0]
Constraints:

1 ≤ n ≤ 104
1 ≤ meetings.size() ≤ 104
meetings[i].size() == 2
0 ≤ starti < endi ≤ 104
*/

// User function Template for C++
class Solution {
  private:
    vector<int> meetCnt;
    priority_queue<int, vector<int>, greater<int>> availableRooms;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busyRooms;

    void initializeRooms(int n) 
    {
        meetCnt.resize(n, 0);
        while (!availableRooms.empty()) availableRooms.pop();
        while (!busyRooms.empty()) busyRooms.pop();
        for (int i = 0; i < n; ++i) 
        {
            availableRooms.push(i);
        }
    }

    void freeUpRooms(int currentTime) 
    {
        while (!busyRooms.empty() && busyRooms.top().first <= currentTime) 
        {
            availableRooms.push(busyRooms.top().second);
            busyRooms.pop();
        }
    }

    void allocateRoom(int startTime, int endTime) 
    {
        if (!availableRooms.empty()) 
        {
            int roomInd = availableRooms.top();
            availableRooms.pop();
            meetCnt[roomInd]++;
            busyRooms.push({endTime, roomInd});
        } 
        else 
        {
            pair<int, int> topRoom = busyRooms.top(); // structured binding replaced
            busyRooms.pop();
            int roomEndTime = topRoom.first;
            int roomInd = topRoom.second;
            int duration = endTime - startTime;
            meetCnt[roomInd]++;
            busyRooms.push({roomEndTime + duration, roomInd});
        }
    }

    int getMostBookedRoom() 
    {
        int maxMeetings = 0, roomIndex = 0;
        for (int i = 0; i < meetCnt.size(); ++i) 
        {
            if (meetCnt[i] > maxMeetings) 
            {
                maxMeetings = meetCnt[i];
                roomIndex = i;
            }
        }
        return roomIndex;
    }

public:
    int mostBooked(int n, vector<vector<int>> &meetings) 
    {
        sort(meetings.begin(), meetings.end());
        initializeRooms(n);
        for (const auto& meeting : meetings) 
        {
            int start = meeting[0], end = meeting[1];
            freeUpRooms(start);
            allocateRoom(start, end);
        }
        return getMostBookedRoom();
    }
};