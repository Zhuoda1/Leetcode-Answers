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
    struct comp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;

        for(auto nd : lists){
            if(nd) pq.push(nd);
        }

        ListNode *head = new ListNode(), *tail = head;

        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            tail->next = temp;
            tail = tail->next;
            if(temp->next) pq.push(temp->next);
        }

        return head->next;
    }
};