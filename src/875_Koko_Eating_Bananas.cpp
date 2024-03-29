class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1000000000;
        while(l < r){
            int m = (l + r) / 2, total = 0;
            for(int pile : piles) total += (pile + m - 1) / m;
            if(total > h) l = m + 1;
            else r = m;
        }
        return l;
    }
};