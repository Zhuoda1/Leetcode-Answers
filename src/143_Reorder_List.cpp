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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* fast = head, *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* temp = nullptr, *prev = slow, *node = slow->next;
        while(node){
            temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        slow->next = nullptr;
        node = head;
        while(prev != slow){
            temp = prev->next;
            prev->next = node->next;
            node->next = prev;
            node = node->next->next;
            prev = temp;
        }
    }
};