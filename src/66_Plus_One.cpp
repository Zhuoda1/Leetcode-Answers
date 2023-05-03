class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(++digits[digits.size()-1] < 10) return digits;
        int s = 0;
        for(int i = digits.size() - 1; i >= 0; i--){
            if(digits[i] + s == 10){
                digits[i] = 0;
                s = 1;
            }
            else {
                digits[i] += s;
                s = 0;
            }
        }
        if(s == 1) digits.insert(digits.begin(), 1);
        return digits;
    }
};