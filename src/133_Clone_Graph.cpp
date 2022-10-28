/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> nodeMap;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;

        if(nodeMap.count(node) > 0) return nodeMap[node];

        Node* newNode = new Node(node->val);

        nodeMap[node] = newNode;
        for(Node* nd : node->neighbors){
            newNode->neighbors.push_back(cloneGraph(nd));
        }

        return newNode;
    }
};