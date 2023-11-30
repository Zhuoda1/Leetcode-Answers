class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, n = prices.size();
        
        for(int i = 1; i < n; i++) maxProfit += max(prices[i] - prices[i-1], 0);
   
        return maxProfit;
    }
};