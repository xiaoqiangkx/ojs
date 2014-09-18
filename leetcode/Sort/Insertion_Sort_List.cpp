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
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        
        while (head != NULL) {
            ListNode *tmp = head;
            head = head->next;
            
            ListNode *prev = &dummy;
            ListNode *cur = dummy.next;
            while (cur != NULL) {
                if (cur->val > tmp->val) {
                    tmp->next = cur;
                    prev->next = tmp;
                    break;
                }
                prev = cur;
                cur = cur->next;
            }
            
            if (cur == NULL) {
                tail->next = tmp;
                tmp->next = NULL;
                tail = tmp;
            }
        }
        
        return dummy.next;
    }
};
