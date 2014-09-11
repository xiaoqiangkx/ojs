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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        
        ListNode *p = head;
        
        while (p != NULL) {
            if (dummy.next == NULL || tail->val != p->val) {
                tail->next = p;
                tail = p;
            }
            
            p = p->next;
        }
        
        tail->next = NULL;
        return dummy.next;
    }
};
