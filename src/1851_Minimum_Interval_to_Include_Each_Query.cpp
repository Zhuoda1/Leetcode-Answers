class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        unordered_map<int,int> ans;
        vector<int> ret;
        vector<int> Q(queries);
        priority_queue<vector<int>> pq;
        sort(Q.begin(), Q.end());
        sort(intervals.begin(), intervals.end());
        int i = 0, n = intervals.size();
        for(int q : Q){
            while (i < n && intervals[i][0] <= q) {
                int l = intervals[i][0], r = intervals[i][1];
                i++;
                pq.push({l - r - 1, r});
            }
            while (pq.size() && pq.top()[1] < q)
                pq.pop();
            ans[q] = pq.size() ? -pq.top()[0] : -1;
        }
        for(int q : queries) ret.push_back(ans[q]);
        return ret;
    }
};