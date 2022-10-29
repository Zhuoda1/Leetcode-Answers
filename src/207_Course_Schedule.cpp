class Solution {
public:
    vector<vector<int>> edges;
    vector<int> visit;
    bool flag = true;

    void dfs(int course){
        visit[course] = 1;
        for(auto v : edges[course]){
            if(visit[v] == 0){
                dfs(v);
                if(!flag) return;
            }
            else if(visit[v] == 1){
                flag = false;
                return;
            }
        }
        visit[course] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visit.resize(numCourses);
        for(const auto& info : prerequisites){
            edges[info[1]].push_back(info[0]);
        }
        for(int i = 0; i < numCourses; i++){
            if(!flag) return flag;
            dfs(i);
        }
        return flag;
    }
};

class Solution {
public:
    vector<vector<int>> edge;
    vector<int> indeg;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses);
        indeg.resize(numCourses);

        for(auto pq : prerequisites){
            edge[pq[1]].push_back(pq[0]);
            indeg[pq[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0) q.push(i);
        }

        int take = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            take++;
            for(int after : edge[course]){
                if(--indeg[after] == 0){
                    q.push(after);
                }
            }
        }
        return take == numCourses;
    }
};