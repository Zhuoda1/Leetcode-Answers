class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int maxScore = 0;
        int ans = divisors[0];
        for(int div : divisors){
            int curScore = 0;
            for(int num : nums){
                if(num % div == 0){
                    curScore++;
                }
            }
            if(curScore == maxScore && div < ans) ans = div;
            else if(curScore > maxScore) {
                maxScore = curScore;
                ans = div;
            }
        }
        return ans;
    }
};