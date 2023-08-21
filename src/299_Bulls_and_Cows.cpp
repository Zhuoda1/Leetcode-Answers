class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        unordered_map<char, int> gue;
        int n = secret.size();
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]) bull += 1;
            else{
                gue[guess[i]] += 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(secret[i] != guess[i]){
                if(gue[secret[i]] > 0){
                    gue[secret[i]] -= 1;
                    cow += 1;
                }
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};