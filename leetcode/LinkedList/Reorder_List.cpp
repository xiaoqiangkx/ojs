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
    void reorderList(ListNode *head) {
        int n = count(head);
        if (n <= 1) return;
        
        ListNode first_dummy(-1);
        ListNode *first_tail = &first_dummy;
        
        ListNode second_dummy(-1);
        ListNode *second_tail = &second_dummy;
        
        int cnt = 1;
        ListNode *p = head;
        while (cnt <= n) {
            if (cnt <= (n + 1) / 2) {
                first_tail->next = p;
                first_tail = p;
                p = p->next;
            } else {
                ListNode *tmp = p;
                p = p->next;
                if (second_dummy.next == NULL) {
                    second_tail = tmp;
                }
                
                tmp->next = second_dummy.next;
                second_dummy.next = tmp;
            }
            
            ++cnt;
        }
        
        first_tail->next = NULL;
        second_tail->next = NULL;
        
        p = first_dummy.next;
        ListNode *q = second_dummy.next;
        
        ListNode dummy(-1);
        ListNode *result_tail = &dummy;
        
        while (p && q) {
            ListNode *p_tmp = p;
            ListNode *q_tmp = q;
            p = p->next;
            q = q->next;
            
            p_tmp->next = q_tmp;
            result_tail->next = p_tmp;
            result_tail = q_tmp;
        }
        
        result_tail->next = p;
        
        head = dummy.next;
    }
    
    int count(ListNode *head) {
        int cnt = 0;
        while (head) {
            ++cnt;
            head = head->next;
        }
        
        return cnt;
    }
};
