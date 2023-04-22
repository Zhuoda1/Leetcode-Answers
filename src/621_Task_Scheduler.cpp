class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        int time = 0;
        vector<int> temp;
        int init[26] = {};
        for(char task : tasks) init[task - 'A'] += 1;
        for(int i = 0; i < 26; i++) if(init[i]) pq.push(init[i]);
        while(pq.size()){
            for(int i = 0; i < n + 1; i++){
                if(pq.empty() && temp.size() == 0) break;
                time++;
                if(pq.size()){
                    int cur = pq.top();
                    pq.pop();
                    if(cur - 1 != 0) temp.push_back(cur - 1);
                }
            }
            for(int ele : temp) pq.push(ele);
            temp.clear();
        }
        return time;
    }
};