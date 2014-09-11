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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL) {
            return head;
        }
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        
        ListNode *p = head;
        ListNode *q = p->next;
        
        while (p != NULL && q != NULL) {
            ListNode *tmp_p = p;
            ListNode *tmp_q = q;
            p = q->next;
            if (p != NULL) {
                q = p->next;
            } else {
                q = NULL;
            }
            
            tmp_q->next = tmp_p;
            tail->next = tmp_q;
            tail = tmp_p;
        }
        
        if (p == NULL) {
            tail->next = q;
            tail = q;
        } else {
            tail->next = p;
            tail = p;
        }
        
        return dummy.next;
    }
};
