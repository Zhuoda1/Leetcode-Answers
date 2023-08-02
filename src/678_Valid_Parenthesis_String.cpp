class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0; 
        for (const auto& c : s) {
            if (c == '(') {
                cmax++;
                cmin++;
            } else if (c == ')') {
                cmax--;
                cmin--;
            }else if(c == '*'){
                cmax++;
                cmin--;
            }
            if (cmax < 0) return false;
            cmin = max(cmin, 0);
        }
        return cmin == 0;
    }
};