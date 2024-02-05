class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string enc = "";
        for(const auto& str : strs){
            int sz = str.size();
            enc += to_string(sz);
            enc += ";";
            enc += str;
        }
        return enc;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> dec;
        int idx = 0, n = s.size();
        while(idx < n){
            string sz_str = "";
            while(s[idx] != ';') sz_str.push_back(s[idx++]);
            int sz = stoi(sz_str);
            idx += 1;
            dec.push_back(s.substr(idx, sz));
            idx += sz;
        }
        return dec;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));