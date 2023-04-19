class FileSystem {
public:
    struct fileNode {
        unordered_map<string, fileNode*> next;
        bool isFile;
        string content;
        fileNode() : isFile(false), content("") {}
    };
    fileNode* root;

    FileSystem() {
        root = new fileNode();
    }
    fileNode* findFolder(string path){
        fileNode* find = root;
        stringstream s(path);
        string folder;
        while(getline(s, folder, '/')){
            if(folder.size()){
                if(!find->next[folder]) find->next[folder] = new fileNode();
                find = find->next[folder];
            }
        }
        return find;
    }
    vector<string> ls(string path) {
        fileNode* find = findFolder(path);
        if(find->isFile){
            return {path.substr(path.find_last_of('/') + 1)};
        }
        else{
            vector<string> ret;
            for(auto ele : find->next){
                ret.push_back(ele.first);
            }
            sort(ret.begin(), ret.end());
            return ret;
        }
    }
    
    void mkdir(string path) {
        findFolder(path);
    }
    
    void addContentToFile(string filePath, string content) {
        fileNode* find = findFolder(filePath);
        find->content += content;
        find->isFile = true;
    }
    
    string readContentFromFile(string filePath) {
        fileNode* find = findFolder(filePath);
        return find->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */