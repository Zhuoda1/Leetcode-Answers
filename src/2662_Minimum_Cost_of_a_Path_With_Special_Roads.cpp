// Define a min-heap priority queue to store pairs of distance and index
template<class T> using min_pq = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
    
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        
        const int INF = 1e9+10;
        int n = specialRoads.size();

        // Initialize the distance of each special road to infinity
        vector<int> d(n, INF);

        // Create a priority queue and push the distance from start to each special road
        min_pq<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            d[i] = abs(start[0] - specialRoads[i][0]) + abs(start[1] - specialRoads[i][1]) + specialRoads[i][4];
            pq.push({d[i], i});
        }
        
        // Initialize the answer with the manhattan distance between start and target
        int ans = abs(start[0] - target[0]) + abs(start[1] - target[1]);

        // Continue to search for the shortest path until the priority queue is empty
        while (pq.size()) {
            // Pop the pair with smallest distance
            auto [d_c, c] = pq.top(); pq.pop();

            // If the distance stored in d is not equal to the current distance d_c, skip this node
            if (d_c != d[c]) continue;

            // Update the answer by finding the distance from the current special road to the target
            ans = min(ans, d_c + abs(target[0] - specialRoads[c][2]) + abs(target[1] - specialRoads[c][3]));

            // For each special road that can be reached from the current special road, update its distance
            for (int nxt = 0; nxt < n; nxt++) {
                int w = abs(specialRoads[c][2] - specialRoads[nxt][0]) + abs(specialRoads[c][3] - specialRoads[nxt][1]) + specialRoads[nxt][4];
                if (d_c + w < d[nxt]) {
                    d[nxt] = d_c + w;
                    pq.push({d[nxt], nxt});
                }
            }
        }

        // Return the minimum cost of reaching the target
        return ans;
    }
};