class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 2) return min(cost[1], cost[0]);
        int p = cost[1], pp = cost[0];
        int ans = 0;
        for(int i = 2; i < cost.size(); i++){
            ans = min(p, pp) + cost[i];
            pp = p;
            p = ans;
        }
        return min(ans, pp);
    }
};