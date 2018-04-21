/**
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    
    struct ListNode *head, *tail;
    int i,count, min_val, min_val_index;
    min_val = (1<<31)-1;
    min_val_index = -1;
    head = tail = NULL;
    
    //printf("min_val = %d\n", min_val);
    
    do {
        count = 0;
        min_val_index = -1;
        min_val = (1<<31)-1;
        for (i=0; i < listsSize; i++) {
        
            if (!lists[i]) {
                count++;
                continue;
            }
        
            // Now traverse top node from each list
            //printf("lists[i]->val = %d\n", lists[i]->val);
            
            if (lists[i]->val <= min_val) {
                min_val = lists[i]->val;
                min_val_index = i;
            }
        }
        
        // break loop when all the entries in the list are NULL
        if (count == listsSize) {
            break;
        }
        if (min_val_index == -1) {
                //printf("Error min_val_index = %d\n", min_val_index);
        }
        if (!head) {
            head = lists[min_val_index];
            tail = head;
            lists[min_val_index] = lists[min_val_index]->next;
            //printf("head = %x\n", head);
        } else {
            tail->next = lists[min_val_index];
            tail = tail->next;
            lists[min_val_index] = lists[min_val_index]->next;
            //printf("head = %x, tail = %x\n", head, tail);
        }
        
    } while(1);

    
    return head;
}
