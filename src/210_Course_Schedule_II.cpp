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

class Solution {
public:
    vector<vector<int>> edge;
    vector<int> indeg;
    vector<int> ans;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses);
        indeg.resize(numCourses);

        for(auto pr : prerequisites){
            edge[pr[1]].push_back(pr[0]);
            indeg[pr[0]]++;
        }
        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int course = q.front();
            q.pop();
            ans.push_back(course);
            for(int after : edge[course]){
                if(--indeg[after] == 0){
                    q.push(after);
                }
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};