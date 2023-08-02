class Solution {
public:
    vector<int> partitionLabels(string s) {
        int freq[26] = {};
        for(int i = 0; i < s.size(); i++) freq[s[i] - 'a'] = i;
        vector<int> ans;
        int interval = 0, size = 0;
        for(int i = 0; i < s.size(); i++){
            if(i > interval){
                ans.push_back(size);
                size = 0;
                interval = 0;
            }
            interval = max(freq[s[i] - 'a'], interval);
            size++;
        }
        ans.push_back(size);
        return ans;
    }
};