class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int idx = 0;
        if(v1.size()){
            v.push_back(v1);
            dq.push_back({idx++, 0});
        }
        if(v2.size()){
            v.push_back(v2);
            dq.push_back({idx++, 0});
        }
    }

    int next() {
        auto [v_idx, ele_idx] = dq.front();
        dq.pop_front();
        int next_ele = v[v_idx][ele_idx];

        ele_idx += 1;
        if(ele_idx != v[v_idx].size()) dq.push_back(make_pair(v_idx, ele_idx));

        return next_ele;
    }

    bool hasNext() {
        return !dq.empty();
    }

private:
    deque<pair<int,int>> dq;
    vector<vector<int>> v;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */