class cmp{
public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, pair<int,string>> m;
        unordered_map<string, long long> view;
        int maxView = 0;
        unordered_set<string> ansName;
        vector<vector<string>> ans;
        for(int i = 0; i < creators.size(); i++){
            view[creators[i]] += views[i];
            if(m.count(creators[i]) > 0){
                if(views[i] > m[creators[i]].first) m[creators[i]] = make_pair(views[i],ids[i]);
                else if(views[i] == m[creators[i]].first){
                    if(ids[i].compare(m[creators[i]].second) < 0) m[creators[i]] = make_pair(views[i],ids[i]);
                }
            }
            else m[creators[i]] = make_pair(views[i],ids[i]);
            if(view[creators[i]] > maxView){
                maxView = view[creators[i]];
                ansName.clear();
                ansName.insert(creators[i]);
            }
            else if(view[creators[i]] == maxView && ansName.count(creators[i]) == 0){
                ansName.insert(creators[i]);
            }
        }
        for(string name : ansName){
            vector<string> temp(2);
            temp[0] = name;
            temp[1] = m[name].second;
            ans.push_back(temp);
        }
        return ans;
    }
};