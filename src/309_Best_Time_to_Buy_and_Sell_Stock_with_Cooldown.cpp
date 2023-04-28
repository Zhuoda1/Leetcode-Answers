class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // buy[i] = max(sell[i-2]-price, buy[i-1])
        // sell[i] = max(buy[i-1]+price, sell[i-1])
        int buy = INT_MIN;
        int sell = 0;
        int prev_buy = 0;
        int prev_sell = 0;
        for(int price : prices){
            prev_buy = buy;
            buy = max(prev_sell - price, buy);
            prev_sell = sell;
            sell = max(prev_buy + price, sell);
        }
        return sell;
    }
};