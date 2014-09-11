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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *newHead = NULL;
        ListNode *newTail = NULL;
        
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        
        while (p1 != NULL && p2 != NULL) {
            int sum = p1->val + p2->val;
            ListNode *tmp = new ListNode(sum);
            p1 = p1->next;
            p2 = p2->next;
            
            if (newHead == NULL) {
                newHead = tmp;
                newTail = newHead;
            } else {
                newTail->next = tmp;
                newTail = newTail->next;
            }
        }
        
        if (p1 == NULL) {
            newTail->next = p2;
        } else {
            newTail->next = p1;
        }
        
        int add = 0;
        ListNode *p = newHead;
        
        while (p != NULL) {
            int sum = p->val + add;
            p->val = sum % 10;
            add = sum / 10;
            
            if (p->next == NULL && add == 1) {
                ListNode *tmp = new ListNode(add);
                p->next = tmp;
                break;
            } else {
                p = p->next;                
            }
        }
        
        return newHead;
    }
};