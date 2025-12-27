class Solution {
public:
    typedef pair<long long , int> p;

    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(begin(meetings) , end(meetings));
        vector<int> roomsUsed(n , 0);

        priority_queue<p , vector<p> , greater<p>> usedRooms;
        priority_queue<int , vector<int> , greater<int>> available;

        for (int room = 0; room < n; room++) {
            available.push(room);
        }

        for (vector<int>& meet : meetings) {
            int st = meet[0];
            int end = meet[1];
            int duration = end - st;

            while(!usedRooms.empty() && usedRooms.top().first <= st) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                available.push(room);
            }

            if (!available.empty()) {
                int room = available.top();
                available.pop();
                usedRooms.push({end , room});
                roomsUsed[room]++;
            }
            else {
                int room = usedRooms.top().second;
                long long endTime = usedRooms.top().first;

                usedRooms.pop();
                usedRooms.push({endTime + duration , room});
                roomsUsed[room]++;
            }
        }
        int res = -1;
        int maxUse = 0;

        for (int room = 0; room < n; room++) {
            if (roomsUsed[room] > maxUse) {
                maxUse = roomsUsed[room];
                res = room;
            }
        }

        return res;
    }
};