bool cmp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < intervals[i-1][1]) return false;
        }
        return true;
    }
};