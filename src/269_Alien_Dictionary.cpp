class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> indeg;
        // first build adjanct list
        unordered_map<char, unordered_set<char>> adj;
        // find the order between char
        // record indegree
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                indeg[words[i][j]] = 0; 
            }
        }
        for(int i = 0; i < words.size() - 1; i++){
            int min_size = min(words[i].size(), words[i+1].size());
            for(int j = 0; j < min_size; j++){
                if(words[i][j] != words[i+1][j]){
                    if(adj[words[i][j]].count(words[i+1][j]) == 0){
                        adj[words[i][j]].insert(words[i+1][j]);
                        indeg[words[i+1][j]] += 1;
                    }
                    break;
                }
                if (j == min_size - 1 and words[i].size() > words[i+1].size()) return "";
            }
        }
        string ans;
        if(indeg.size() == 1){
            for(auto node : indeg) ans.push_back(node.first);
            return ans;
        }
        // queue to contain 0 indegree char, decrease indegree of its adjanct char
        queue<char> q;
        for(auto node : indeg){
            if(node.second == 0){
                q.push(node.first);
            }
        }
        
        while(q.size()){
            char cur = q.front();
            ans.push_back(cur);
            q.pop();
            for(char ch : adj[cur]){
                if(--indeg[ch] == 0) q.push(ch);
            }
        }
        if(ans.size() == indeg.size()) return ans;
        return "";
    }
};