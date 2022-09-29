class Solution {
public:
    vector<int> stack;
    vector<int> visit;
    vector<vector<int>> edge;
    bool flag = true;

    void dfs(int course){
        visit[course] = 1;
        for(auto prev : edge[course]){
            if(visit[prev] == 0){
                dfs(prev);
                if(!flag) return;
            }
            else if(visit[prev] == 1){
                flag = false;
                return;
            }
        }
        visit[course] = 2;
        stack.push_back(course);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses);
        visit.resize(numCourses);
        for(const auto& info : prerequisites){
            edge[info[1]].push_back(info[0]);
        }
        for(int i = 0; i < numCourses && flag; i++){
            if(!visit[i]) dfs(i);
        }
        if(!flag) return vector<int>();
        reverse(stack.begin(),stack.end());
        return stack;
    }
};