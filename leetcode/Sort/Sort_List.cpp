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
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);
        return mergeTwoLists(left, right);
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        
        while (p1 != NULL && p2 != NULL) {
            if (p1->val < p2->val) {
                ListNode *tmp = p1;
                p1 = p1->next;
                tail->next = tmp;
                tail = tmp;
            } else {
                ListNode *tmp = p2;
                p2 = p2->next;
                tail->next = tmp;
                tail = tmp;
            }
        }
        
        if (p1 != NULL) {
            tail->next = p1;
        } else {
            tail->next = p2;
        }
        
        return dummy.next;
    }
};
