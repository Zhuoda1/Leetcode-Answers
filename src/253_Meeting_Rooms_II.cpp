class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int res = 0, cur = 0;
        map<int, int> it;
        for(auto interval : intervals){
            it[interval[0]]++;
            it[interval[1]]--;
        }
        for(auto i : it){
            cur += i.second;
            res = max(res, cur);
        }
        return res;
    }
};