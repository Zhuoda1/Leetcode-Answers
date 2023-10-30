class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        long ans = 0, n_houses = houses.size(), n_heaters = heaters.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int k = 0;
        for(int i = 0; i < n_houses; i++){
            long dis = 0;
            while(k < n_heaters && heaters[k] < houses[i]) k++;
            if(k == n_heaters) dis = houses[i] - heaters[k-1];
            else if(k == 0) dis = heaters[k] - houses[i];
            else dis = min(houses[i] - heaters[k-1], heaters[k] -  houses[i]);
            ans = max(ans, dis);
        }
        return ans;
    }
};
// find max of min heater dis for every house
/*
while(k < n && heaters[k] < houses[i]) k++;
if(k == n || k == 0) dis = heaters[k]
else dis = min(heater[k-1], cur = heater[k]);
*/