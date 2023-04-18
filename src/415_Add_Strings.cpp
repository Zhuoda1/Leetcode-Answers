class Solution {
public:
    string addStrings(string num1, string num2) {
        int c = 0, s = 0;
        int pt1 = num1.size() - 1, pt2 = num2.size() - 1;
        string ans = "";
        while(pt1 >= 0 || pt2 >= 0 || s){
            c += s;
            if(pt1 >= 0) c += num1[pt1--] - '0';
            if(pt2 >= 0) c += num2[pt2--] - '0';
            s = c / 10;
            ans += char(c % 10 + '0');
            c = 0;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};