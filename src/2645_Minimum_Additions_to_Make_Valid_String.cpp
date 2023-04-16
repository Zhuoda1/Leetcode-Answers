class Solution {
public:
    int addMinimum(string word) {
        int k = 0;
        char prev = 'z';
        for(char c : word){
            k += c <= prev;
            prev = c;
        }
        return k * 3 - word.size();
    }
};