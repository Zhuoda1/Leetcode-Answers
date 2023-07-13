/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        ListNode *l_node = nullptr, *r_node = nullptr, *node = head;
        ListNode *l_prev = nullptr, *r_next = nullptr, *prev = nullptr;
        int cur = 0;
        while(!l_node || !r_node){
            ++cur;
            if(cur == left){
                cout<<cur;
                l_node = node;
                l_prev = prev;
            }
            if(cur == right){
                r_node = node;
                r_next = node->next;
            }
            prev = node;
            node = node->next;
        }

        ListNode* temp = nullptr;
        node = l_node;
        prev = nullptr;

        while(prev != r_node){
            temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        if(l_prev) l_prev->next = r_node;
        l_node->next = r_next;
        if(left == 1) return r_node;
        return head;
    }
};