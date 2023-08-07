class Solution {
public:
    double myPow(double x, int n) {
        long num = n;
        if(n < 0){
            x = 1 / x;
            num = -num;
        }
        double ans = 1;
        while(num != 0){
            if((num & 1)) ans *= x;
            x *= x;
            num = num >> 1;
        }
        return ans;
    }
};