class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(words.find(endWord) == words.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        int ladder = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string cur = q.front();
                q.pop();
                if(cur == endWord) return ladder;
                words.erase(cur);
                for(int j = 0; j < cur.size(); j++){
                    char temp = cur[j];
                    for(int k = 0; k < 26; k++){
                        cur[j] = k + 'a';
                        if(words.find(cur) != words.end()) q.push(cur);
                    }
                    cur[j] = temp;
                }
            }
            ladder++;
        }
        return 0;
    }
};