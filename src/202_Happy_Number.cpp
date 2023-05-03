class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        long t = n;
        st.insert(t);
        while(t != 1){
            t = cal(t);
            if(st.count(t)) return false;
            st.insert(t);
        }
        return true;
    }
    long cal(long n){
        if(n == 0) return 0;
        if(n == 1) return 1;
        int cur = n % 10;
        return cur * cur + cal(n / 10);
    }
};