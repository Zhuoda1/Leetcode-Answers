class RandomizedCollection {
public:
    vector<pair<int,int>> mp_ind;
    unordered_map<int, vector<int>> mp;

    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool flag = true;
        if(mp.count(val)) flag = false;
        mp[val].push_back(mp_ind.size());
        mp_ind.push_back({val, mp[val].size() - 1});
        return flag;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;
        //assign last val to removed val
        auto last = mp_ind.back();
        mp[last.first][last.second] = mp[val].back();
        mp_ind[mp[val].back()] = last;
        mp[val].pop_back();
        if(mp[val].size() == 0) mp.erase(val);
        mp_ind.pop_back();
        return true;
    }
    
    int getRandom() {
        int ind = rand() % mp_ind.size();
        auto ans = mp_ind[ind];
        return ans.first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */