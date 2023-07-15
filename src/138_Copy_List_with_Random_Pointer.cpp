/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        unordered_map<Node*, Node*> mp;
        Node* hd = new Node(0);
        mp[head] = hd;

        Node* node = head;
        Node* node2 = hd;
        while(node){
            Node* cur = new Node(node->val);
            node2->next = cur;
            mp[node] = cur;
            node2 = node2->next;
            node = node->next;
        }

        node = head;
        node2 = hd;
        while(node){
            node2->next->random = mp[node->random];
            node = node->next;
            node2 = node2->next;           
        }
        return hd->next;
    }
};