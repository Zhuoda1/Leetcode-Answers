bool cmp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        int room = 1;
        sort(intervals.begin(), intervals.end(), cmp);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < intervals[i-1][1]) room++;
        }
        return room;
    }
};