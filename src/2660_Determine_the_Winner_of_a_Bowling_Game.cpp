class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int s1 = 0, s2 = 0;
        s1 = score(player1);
        s2 = score(player2);
        if(s1 == s2) return 0;
        if(s1 < s2) return 2;
        return 1;
    }
    int score(vector<int> player){
        int cnt = 0;
        vector<bool> flag(player.size(), false);
        for(int i = 0; i < player.size(); i++){
            if(flag[i]) cnt += player[i] * 2;
            else cnt += player[i];
            if(player[i] == 10){
                if(i + 1 < player.size() && !flag[i+1]) {
                    flag[i+1] = true;
                }
                if(i + 2 < player.size() && !flag[i+2]){
                    flag[i+2] = true;
                }
            }
        }
        return cnt;
    }
};