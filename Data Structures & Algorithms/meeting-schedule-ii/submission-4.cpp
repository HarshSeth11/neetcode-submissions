/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n == 0 || n == 1) return n;

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.end < b.end;
        });

        vector<int> rooms;
        rooms.push_back(intervals[0].end);

        for(int i=1; i<n; i++) {
            int j;
            for(j=rooms.size()-1; j>=0; j--) {
                if(rooms[j] <= intervals[i].start) {
                    rooms[j] = intervals[i].end;
                    break;
                }
            }
            if(j < 0) {
                rooms.push_back(intervals[i].end);
            }
        }

        return rooms.size();
    }
};
// 3, 8, 15, 20, 30
// 6, 12, 18, 25, 
// 10,
