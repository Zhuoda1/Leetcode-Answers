class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        int level = 1;
        vector<int> ans(n+1, 0);
        ans[1] = 1;
        for(int i = 2; i <= n;){
            for(int j = 0; j < level && i <= n; j++) ans[i++] = ans[i-level];
            int target = i + level;
            while(i <= n && i < target) ans[i++] = ans[i-level]+1;
            level *= 2;
        }
        return ans;
    }
};