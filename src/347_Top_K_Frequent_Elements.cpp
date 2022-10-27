class compare{
public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int num : nums) mp[num]++;
        for(pair<int,int> num : mp){
            pq.emplace(num);
        }
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};