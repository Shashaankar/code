/**
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *head, *seek_node;
    head = seek_node = NULL;
    
    if (!l1 && !l2) {
        return NULL;
    }
    if (!l1 && l2) {
        return l2;
    }
    if (!l2 && l1) {
        return l1;
    }
    
    while (l1 || l2) {
        
        if (l1 && l2) {
            
            if (l1->val <= l2->val) {
                
                if (!head) {
                    // First node in the return list
                    head = l1;
                    seek_node = head;
                } else {
                    seek_node->next = l1;
                    seek_node = seek_node->next;
                }
                // Go to next node int the list
                l1 = l1->next;
                
            } else {
                
                if (!head) {
                    head = l2;
                    seek_node = l2;
                } else {
                    seek_node->next = l2;
                    seek_node = seek_node->next;
                }
                l2 = l2->next;
            }
        } else if (l1 && !l2) {
            
            //printf("loop l1 : %d\n", l1->val);
            do{
                seek_node->next = l1;
                seek_node = seek_node->next;
                l1 = l1->next;
            } while(l1);
            
        } else if (l2 && !l1) {
            
            //printf("loop l2 : %d\n", l2->val);
            do {
                seek_node->next = l2;
                seek_node = seek_node->next;
                l2 = l2->next;
            }while(l2);
        }
        
    } // while l1 || l2
    
    
    return head;
    
}
