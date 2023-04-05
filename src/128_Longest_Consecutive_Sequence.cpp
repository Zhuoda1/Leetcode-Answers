class Solution {
public:
    int find(int f, unordered_map<int, int>& parent){
        if(parent[f] != f){
            parent[f] = find(parent[f], parent);
        }
        return parent[f];
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> parent;
        unordered_map<int, int> size;
        for(int num : nums){
            if(parent.count(num) > 0) continue;
            if(parent.count(num-1) == 0){
                parent[num] = num;
                size[num] = 1;
            }
            else{
                parent[num] = num - 1;
                size[find(num - 1, parent)] += 1;
            }
        }

        for(int num : nums){
            int f = find(num, parent);
            if(parent.count(f - 1) > 0){
                int nf = find(f - 1, parent);
                parent[f] = nf;
                size[nf] += size[f]; 
            }
        }
        int ans = 0;
        for(auto pr : size){
            ans = max(pr.second, ans);
        }
        return ans;
    }
};