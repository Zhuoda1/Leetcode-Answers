class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int minimum = INT_MAX;
        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i+1] - arr[i] == minimum){
                ans.push_back({arr[i], arr[i+1]});
            }
            else if(arr[i+1] - arr[i] < minimum){
                minimum = arr[i+1] - arr[i];
                vector<vector<int>>().swap(ans);
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};