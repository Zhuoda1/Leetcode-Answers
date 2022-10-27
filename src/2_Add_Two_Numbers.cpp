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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) return l1 ? l1 : l2;
        ListNode *head = new ListNode(), *tail = head;
        int c = 0;
        while(l1 || l2){
            ListNode *temp = new ListNode();
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            temp->val = (c + val1 + val2) % 10;
            c = (c + val1 + val2) / 10;
            tail->next = temp;
            tail = tail->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(c) tail->next = new ListNode(1);
        return head->next;
    }
};