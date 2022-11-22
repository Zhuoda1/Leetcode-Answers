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

//Solution
struct cmp{
    bool operator()(const pair<int,int>& left, const pair<int,int>& right) const {
        return left.second > right.second;
    }
};
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
            return u[0] < v[0];
        });
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        for(auto interval : intervals){
            if(!pq.empty() && pq.top().second <= interval[0]){
                pq.pop();
            }
            pq.push({interval[0],interval[1]});
        }
        return pq.size();
    }
};