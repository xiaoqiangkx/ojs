/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p = head;
        while (p) {
            RandomListNode *tmp = new RandomListNode(p->label);
            tmp->next = p->next;
            p->next = tmp;
            p = p->next->next;
        }
        
        p = head;
        while (p) {
            if (p->random != NULL) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        
        RandomListNode dummy(-1);
        RandomListNode *tail = &dummy;
        
        p = head;
        while (p) {
            tail->next = p->next;
            tail = p->next;
            p->next = p->next->next;
            p = p->next;
        }
        
        return dummy.next;
    }
};
