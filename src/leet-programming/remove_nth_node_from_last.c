/**

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    struct ListNode *p_fast, *p_slow, *p_prev, *temp;
    int count = 1;
    
    
    if (head == NULL) {
        return NULL;
    }
    
    p_prev = NULL;
    p_fast = p_slow = head;
    
    /* Seek fast ptr to n nodes from the head */
    while (count < n) {
        if (p_fast == NULL) {
            //printf("Invalid entry n=%d\n", n);
            return NULL;
        }
        
        p_fast = p_fast->next;
        count++;
    }
    
    /* Now seek one node at a time */
    while (p_fast) {
        
        p_fast = p_fast->next;
        
        if (p_fast == NULL) {
            
            /* Now slow ptr will point to nth node from last */
            temp = p_slow;
            if (p_prev) {
                p_prev->next = p_slow->next;
            } else {
                /* Head is removed fron the node list, update head ptr */
                head = p_slow->next;
            }
            free(temp);
            break;
            
        }
        p_prev = p_slow;
        p_slow = p_slow->next;
    }
    
    return head;
}
