struct TrieNode{
    TrieNode* children[26] = {};
    string* word;
    void addWord(string& word){
        TrieNode* cur = this;
        for(char ch : word){
            if(!cur->children[ch - 'a']) cur->children[ch - 'a'] = new TrieNode();
            cur = cur->children[ch - 'a'];
        }
        cur->word = &word;
    }
};
class Solution {
public:
    int dir[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};
    vector<string> ans;
    void dfs(vector<vector<char>>& board, int x, int y, TrieNode* trie){
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == '*' ||!trie->children[board[x][y] - 'a']) return;
        trie = trie->children[board[x][y] - 'a'];
        if(trie->word){
            ans.push_back(*(trie->word));
            trie->word = nullptr;
        }
        char temp = board[x][y];
        board[x][y] = '*';
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            dfs(board, nx, ny, trie);
        }
        board[x][y] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* trie = new TrieNode();
        for(string& word : words) trie->addWord(word);
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(board, i, j, trie);
            }
        }
        return ans;
    }
};