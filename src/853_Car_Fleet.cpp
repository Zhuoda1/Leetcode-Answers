class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n == 0) return 0;
        vector<pair<int,int>> pns;
        for(int i = 0; i < n; i++) pns.push_back({position[i], speed[i]});
        sort(pns.begin(), pns.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            return a.first > b.first;
        });
        stack<float> st;
        for(int i = 0; i < n; i++){
            float time =  (target - pns[i].first) / float(pns[i].second);
            if(st.empty() || time > st.top()) st.push(time);
        }
        return st.size();
    }
};