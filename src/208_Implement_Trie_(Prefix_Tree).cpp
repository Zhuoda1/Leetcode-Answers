class TrieNode{
private:
    vector<TrieNode*> childs;
    bool isEnd;

public:
    TrieNode(){
        childs.resize(26);
        isEnd = false;
    }

    bool containsKey(char ch){
        return childs[ch - 'a'] != nullptr;
    }

    TrieNode* get(char ch){
        return childs[ch - 'a'];
    }

    void put(char ch, TrieNode* node){
        childs[ch - 'a'] = node;
    }

    void setEnd(){
        isEnd = true;
    }

    bool end(){
        return isEnd;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)) node->put(ch, new TrieNode());
            node = node->get(ch);
        }
        node->setEnd();
    }

    TrieNode* searchPrefix(string word){
        TrieNode* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)) return nullptr;
            node = node->get(ch);
        }
        return node;
    }

    bool search(string word) {
        TrieNode* node = searchPrefix(word);
        return node != nullptr && node->end();
    }

    bool startsWith(string prefix) {
        TrieNode* node = searchPrefix(prefix);
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */