class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()){
            return "";
        }
        unordered_map<char,int> tm;
        for(int i = 0; i < t.length(); i++){
            tm[t[i]]++;
        }
        int cnt = 0, minLen = INT_MAX,  left = 0, ansl = 0, ansr = -1, need = t.length();
        for(int i = 0; i < s.length(); i++){

            if(tm.count(s[i]) > 0){
                if(tm[s[i]] > 0) {
                    need--;
                }
                tm[s[i]]--;
            }

            while(need == 0){
                if(i - left + 1 < minLen){
                    ansl = left;
                    ansr = i;
                    minLen = i - left + 1;
                }
                if(tm.count(s[left]) > 0){
                    if(tm[s[left]] >= 0){
                        need++;
                    }
                    tm[s[left]]++;
                }
                left++;
            }

        }
        cout<<ansl<<" "<<ansr<<endl;
        return s.substr(ansl, ansr - ansl + 1);
    }
};