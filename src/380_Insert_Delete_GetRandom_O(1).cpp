class RandomizedSet {
public:
    vector<int> mp_ind;
    unordered_map<int, int> mp;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        mp_ind.push_back(val);
        mp[val] = mp_ind.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;
        mp[mp_ind.back()] = mp[val];
        mp_ind[mp[val]] = mp_ind.back();
        mp_ind.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int ind = rand() % mp_ind.size();
        int ans = mp_ind[ind];
        return ans;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */