/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pt1 = headA;
        ListNode* pt2 = headB;
        while(pt1 != pt2){
            if(pt1 == nullptr) pt1 = headB;
            else pt1 = pt1->next;
            if(pt2 == nullptr) pt2 = headA;
            else pt2 = pt2->next;
        }
        return pt1;
    }
};