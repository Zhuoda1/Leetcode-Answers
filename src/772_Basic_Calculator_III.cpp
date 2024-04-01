class Solution {
public:
    int eval(string& s, int& idx){
        vector<int> nums;
        int n = s.size();
        int num = 0;
        char op = '+';
        while(idx < n && op != ')'){
            if(s[idx] == ' ') continue;
            else if(s[idx] == '(') num = eval(s, ++idx);
            else if(isdigit(s[idx])) num = s[idx] - '0' + num * 10;
            if(!isdigit(s[idx]) || idx == n - 1){
                if(op == '+') nums.push_back(num);
                else if(op == '-') nums.push_back(-num);
                else if(op == '*') nums.back() *= num;
                else if(op == '/') nums.back() /= num;
                op = s[idx];
                num = 0;
            }
            idx++;
        }
        int ans = 0;
        for(const auto& ele : nums) ans += ele;
        return ans;
    }
    int calculate(string s) {
        int idx = 0;
        return eval(s, idx);
    }
};