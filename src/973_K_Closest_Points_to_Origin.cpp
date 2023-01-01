class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto com = [](const auto& p1, const auto& p2)->bool {return p1.second < p2.second;};
        priority_queue<pair<int, double>, vector<pair<int, double>>, decltype(com)> pq(com);
        size_t n = points.size();
        for (size_t i = 0; i < n; i++) {
            int x = points[i][0U], y = points[i][1U];
            pq.emplace(i, sqrt(x * x + y * y));
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            size_t idx = pq.top().first;
            ans.emplace_back(vector<int>{points[idx][0], points[idx][1]});
            pq.pop();
        }
        return ans;
    }
};
