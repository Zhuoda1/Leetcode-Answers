class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        if(len < 3) return len;
        int max_num = 2;
        for(int i = 0; i < len; i++){
            unordered_map<double, int> m;
            for(int j = i + 1; j < len; j++){
                long long x = points[i][0] - points[j][0];
                long long y = points[i][1] - points[j][1];
                double grad;
                if(x == 0) grad = INT_MAX;
                else if(y == 0) grad = 0;
                else grad = y * 1.0 / x;
                if(m.count(grad)){
                    m[grad]++;
                }
                else m[grad] = 2;
                max_num = max(max_num, m[grad]);
            }
        }
        return max_num;
    }
};