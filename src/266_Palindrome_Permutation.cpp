class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> bs;
        for(char ch : s) bs.flip(ch);
        return bs.count() < 2;
    }
};