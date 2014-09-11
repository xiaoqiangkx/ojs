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
    ListNode *partition(ListNode *head, int x) {
        ListNode smallerHead(-1);
        ListNode *smallerTail = &smallerHead;
        
        ListNode greaterHead(-1);
        ListNode *greaterTail = &greaterHead;
        
        ListNode *p = head;
        
        while (p != NULL) {
            if (p->val < x) {
                smallerTail->next = p;
                smallerTail = smallerTail->next;
            } else {
                greaterTail->next = p;
                greaterTail = greaterTail->next;
            }
            p = p->next;
        }
        
        smallerTail->next = greaterHead.next;
        greaterTail->next = NULL;
        return smallerHead.next;
    }
};
