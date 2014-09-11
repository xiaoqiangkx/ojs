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
        ListNode *prev = NULL;
        int cnt = 0;
        
        while (p != NULL) {
            if (0 == cnt) {
                prev = p;
                p = p->next;
                cnt = 1;
                continue;
            }
            
            if (p->val == prev->val) {
                ++cnt;
                prev = p;
                p = p->next;
            } else {
                if (1 == cnt) {
                    tail->next = prev;
                    tail = prev;
                }
                
                prev = p;
                p = p->next;
                cnt = 1;
            }
        }
        
        if (1 == cnt) {
            tail->next = prev;
            tail = prev;
        }
        
        tail->next = NULL;
        return dummy.next;
    }
};
