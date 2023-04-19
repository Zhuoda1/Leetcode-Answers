class Solution {
public:
    bool judgeCircle(string moves) {
        int left = 0;
        int up = 0;
        for(char move : moves){
            if(move == 'L') left++;
            else if(move == 'R') left--;
            else if(move == 'U') up++;
            else up--;
        }
        return !left && !up;
    }
};