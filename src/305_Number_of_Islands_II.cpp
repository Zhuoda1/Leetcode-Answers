class UnionFind{
private:
    vector<int> rank;
    vector<int> parent;
    int count;
public:
    UnionFind(int n){
        count = 0;
        for(int i = 0; i < n; i++){
            parent.push_back(-1);
            rank.push_back(0);
        }
    }

    void setParent(int curr){
        if(parent[curr] == -1){
            parent[curr] = curr;
            count++;
        }
    }

    int find(int curr){
        if(parent[curr] != curr) parent[curr] = find(parent[curr]);
        return parent[curr];
    }

    bool valid(int curr){
        return parent[curr] >= 0;
    }

    void unio(int a, int b){
        int root1 = find(a);
        int root2 = find(b);
        if(root1 == root2) return;
        if(rank[root1] > rank[root2]) parent[root2] = root1;
        else if(rank[root2] > rank[root1]) parent[root1] = root2;
        else{
            parent[root2] = root1;
            rank[root1]++;
        }
        count--;
    }

    int cnt(){
        return count;
    }

};
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> ans;
        UnionFind uf(m * n);

        for(auto& position : positions){
            int nx = position[0];
            int ny = position[1];

            vector<int> overlap;
            if(nx >= 1 && uf.valid((nx - 1) * n + ny)) overlap.push_back((nx - 1) * n + ny);
            if(nx < m - 1 && uf.valid((nx + 1) * n + ny)) overlap.push_back((nx + 1) * n + ny);
            if(ny >= 1 && uf.valid(nx * n + ny - 1)) overlap.push_back(nx * n + ny - 1);
            if(ny < n - 1 && uf.valid(nx * n + ny + 1)) overlap.push_back(nx * n + ny + 1);

            uf.setParent(nx * n + ny);
            for(int lap : overlap) uf.unio(lap, nx * n + ny);
            ans.push_back(uf.cnt());
        }
        return ans;
    }
};