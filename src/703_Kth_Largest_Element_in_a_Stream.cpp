class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int cap;
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for(int num : nums) pq.push(num);
        while(pq.size() > cap) pq.pop();
    }
    
    int add(int val) {
        if(pq.size() == cap && val <= pq.top()) return pq.top();
        pq.push(val);
        while(pq.size() > cap) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */