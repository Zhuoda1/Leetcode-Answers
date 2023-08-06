class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        int n = arrival.size();
        queue<int> enter;
        queue<int> exit;
        int time = 0;
        vector<int> ans(n, 0);
        int prev = 1;
        int i = 0;
        while(i < n || enter.size() || exit.size()){
            while(i < n && arrival[i] <= time){
                if(state[i] == 0) enter.push(i);
                else exit.push(i);
                i += 1;
            }
            if(prev == 1){
                if(exit.size()){
                    ans[exit.front()] = time;
                    exit.pop();
                }
                else if(enter.size()){
                    ans[enter.front()] = time;
                    enter.pop();
                    prev = 0;
                }
            }
            else{
                if(enter.size()){
                    ans[enter.front()] = time;
                    enter.pop();
                }
                else if(exit.size()){
                    ans[exit.front()] = time;
                    exit.pop();
                    prev = 1;
                }
                else prev = 1;
            }
            time += 1;
        }
        return ans;
    }
};