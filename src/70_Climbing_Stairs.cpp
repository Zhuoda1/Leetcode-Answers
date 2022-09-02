class Solution {
public:
    int climbStairs(int n) {
        int step1 = 1;
        int step2 = 0;
        int cur = 0;
        int stair = 1;
        while(stair <= n){
            cur = step1 + step2;
            step2 = step1;
            step1 = cur;
            stair++;
        }
        return cur;
    }
};