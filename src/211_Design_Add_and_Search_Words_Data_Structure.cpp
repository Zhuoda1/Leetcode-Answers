class TrieNode{
public:
    vector<TrieNode*> child;
    bool isWord;
    TrieNode(){
        child.resize(26);
        isWord = false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(auto ch : word){
            if(node->child[ch - 'a'] == nullptr) node->child[ch - 'a'] = new TrieNode();
            node = node->child[ch - 'a'];
        }
        node->isWord = true;
    }
    bool searchHelp(string word, TrieNode* node){
        TrieNode* curr = node;
        for(int i = 0; i < word.size(); ++i){
            if(word[i] == '.'){
                for(int j = 0; j < 26; ++j){
                    if(curr->child[j] && searchHelp(word.substr(i+1), curr->child[j])) return true;
                }
                return false;
            }
            else{
                if(curr->child[word[i] - 'a'] == nullptr) return false;
                curr = curr->child[word[i] - 'a'];
            }
        }
        return curr->isWord;
    }
    bool search(string word) {
        TrieNode* node = root;
        return searchHelp(word, node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */