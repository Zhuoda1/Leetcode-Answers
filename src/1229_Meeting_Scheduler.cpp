class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> slot1_start_end;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> slot2_start_end;
        for(auto& ele : slots1){
            slot1_start_end.push(make_pair(ele[0], ele[1]));
        }
        for(auto& ele : slots2){
            slot2_start_end.push(make_pair(ele[0], ele[1]));
        }
        while(!slot1_start_end.empty() && !slot2_start_end.empty()){
            auto [s1_start, s1_end] = slot1_start_end.top();
            auto [s2_start, s2_end] = slot2_start_end.top();

            if(s1_start >= s2_end) slot2_start_end.pop();
            else if(s2_start >= s1_end) slot1_start_end.pop();

            else{
                int lower_bound = max(s1_start, s2_start);
                int upper_bound = min(s1_end, s2_end);
                if(upper_bound - lower_bound >= duration) return {lower_bound, lower_bound + duration};
                if(s1_end < s2_end) slot1_start_end.pop();
                else slot2_start_end.pop();
            }
        }
        return {};
    }
};