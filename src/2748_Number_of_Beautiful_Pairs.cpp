class Solution {
public:
    bool my_gcd(int a, int b){
        if(b > a) return my_gcd(b, a);
        if(b == 1) return false;
        if(b == 2) return (a == 2 || a == 4 || a == 6 || a == 8);
        if(b == 3) return (a == 3 || a == 6 || a == 9);
        if(b == 4) return (a == 4 || a == 6 || a == 8);
        if(b == 5 || b == 7 || b == 8 || b == 9) return a == b;
        if(b == 6) return (a == 6 || a == 8 || a == 9);
        return false;
    }
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int cur = nums[i];
            int start = cur % 10;
            while(cur != 0){
                start = cur % 10;
                cur /= 10;
            }    
            for(int j = i+1; j < nums.size(); j++){
                int end = nums[j] % 10;
                cout<<start<<" "<<end<<" "<<my_gcd(start, end)<<endl;
                if(!my_gcd(start, end)) ans += 1;
            }

            
        }
        return ans;
    }
};