class Solution {
        public:
        int averageValue(vector<int>& nums) {
            int sum = 0, n = 0;
            for(int num : nums){
                if(num % 2 == 0 && num % 3 == 0){
                    sum += num;
                    n += 1;
                }
            }
            return n == 0 ? 0 : sum/n;
        }
};