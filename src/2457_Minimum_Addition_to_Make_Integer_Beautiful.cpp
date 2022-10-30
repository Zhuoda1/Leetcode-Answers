class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        if(n == target) return 0;
        vector<int> bitNum;
        long long temp = n;
        int zeroindex = 0, k = 0;
        bool flag = true;
        while(temp != 0){
            if(temp % 10 != 0 && flag){
                zeroindex = k;
                flag = false;
            }
            bitNum.push_back(temp % 10);
            temp /= 10;
            k++;
        }
        int len = bitNum.size();
        vector<int> pre(len + 1, 0);
        for(int i = 1; i <= len; i++){
            pre[i] = pre[i-1] + bitNum[i-1];
        }
        long long ans = 0, ansindex = -1;
        for(int i = zeroindex; i < len; i++){
            if(zeroindex == i && pre[len] - pre[i] <= target){
                return 0;
            }
            if(zeroindex < i && pre[len] - pre[i] + 1 <= target){
                ansindex = i;
                break;
            }
        }
        if(ansindex == -1){
            ans = 1;
            while(len--){
                ans *= 10;
            }
            return ans - n;
        }
        for(int i = len - 1; i >= 0; i--){
            if(i < ansindex) ans = ans * 10;
            else if(i == ansindex) ans = ans * 10 + bitNum[i] + 1;
            else ans = ans * 10 + bitNum[i];
        }
        return ans - n;
    }
};