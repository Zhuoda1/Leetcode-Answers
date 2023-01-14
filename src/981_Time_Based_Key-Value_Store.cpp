class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mp;
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if(!mp.count(key)) return "";
        if(timestamp < mp[key][0].first) return "";
        int left = 0, right = mp[key].size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(mp[key][mid].first <= timestamp) left = mid + 1;
            else right = mid - 1;
        }
        if(right == -1) return "";
        else return mp[key][right].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */