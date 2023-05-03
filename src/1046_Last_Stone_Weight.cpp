class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone : stones) pq.push(stone);
        while(pq.size() > 1){
            int big = pq.top();
            pq.pop();
            int sm = pq.top();
            pq.pop();
            if(big != sm) pq.push(big - sm);
        }
        return pq.size() ? pq.top() : 0;
    }
};