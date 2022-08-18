/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialization(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialization(in);
    }
private:

    void serialization(TreeNode* root, ostringstream& out){
        if(root == nullptr){
            out << "null" << " ";
            return;
        }
        out << root->val << " ";
        serialization(root->left, out);
        serialization(root->right, out);
    }

    TreeNode* deserialization(istringstream& in){
        string val;
        in >> val;
        if(val == "null") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialization(in);
        root->right = deserialization(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));