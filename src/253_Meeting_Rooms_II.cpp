class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for(const auto& interval : intervals){
            if(pq.size() && interval[0] >= pq.top()) pq.pop();
            pq.push({interval[1]});
        }
        return pq.size();
    }
};