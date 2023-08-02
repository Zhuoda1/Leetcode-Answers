class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        map<int, int> m;
        for (auto &it: hand) {
            m[it]++;
        }

        while(!m.empty()) {
            int curr = m.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                if (m[curr + i] == 0) {
                    return false;
                } else if (--m[curr + i] < 1) {
                    m.erase(curr + i);
                }
            }
        }
        return true;
    }
};