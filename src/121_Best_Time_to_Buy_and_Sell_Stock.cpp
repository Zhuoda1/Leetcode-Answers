class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = -1;
        int maxPrice = 0;
        for(auto price : prices){
            if(mini == -1) mini = price;
            else{
                if(price >= mini) maxPrice = max(maxPrice, price - mini);
                else mini = price;
            }
        }
        return maxPrice;
    }
};