class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans = "";
        for(string str : strs){
            size_t size = str.size();
            string size_str = "";
            // 8  abcdefgh -> 8aabcdefgh
            while(size){
                size_str.push_back((size % 10) + '0');
                size /= 10;
            }
            // 321
            ans += size_str;
            ans.push_back('a');
            ans += str;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        while(s != ""){
            size_t size = 0;
            size_t dig = 1;
            size_t j = 0;
            char c = s[j++];
            while(c != 'a'){
                size = size + (c - '0') * dig;
                c = s[j++];
                dig *= 10;
            }
            s.erase(0,j);
            string cur = s.substr(0, size);
            ans.push_back(cur);
            s.erase(0, size);
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));