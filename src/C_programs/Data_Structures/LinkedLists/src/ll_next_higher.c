#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include "ll_util.h"


void* _create_ll_node(int size) {

    void *head = NULL;
    head = malloc(size);
    if (!head) {
        printf("\nMalloc failed .. exiting ...");
        exit(-1);
    }

    return head;
}

void _insert_singly_ll(node_random **head, int key) {

    node_random *temp = NULL;
    if (!*head) {
        printf("\n List is Empty");
        printf("\n Inserting node...");

        temp = (node_random *)_create_ll_node(sizeof(node_random));
        temp->next = NULL;
        temp->random =NULL;
        temp->key = key;
        temp->val = 0;
        *head = temp;
    } else {

        /** Loop until end of list */
        temp = *head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = (node_random *)_create_ll_node(sizeof(node_random));
        temp->next->next = NULL;
        temp->next->random =NULL;
        temp->next->key = key;
        temp->next->val = 0;
    }

}

void _print_singly_ll(node_random *head) {

    printf("\n");
    while(head) {

        printf("Node key:=%d, val:=%d, next:=%p, random:=%p\n", 
                head->key, head->val, head->next, head->random);
        head = head->next;
    }
}

void _free_singly_ll(node_random *head) {

    if (head->next) {
        _free_singly_ll(head->next);
        free(head);
    } else {
        free(head);
    }
}

void _singly_ll_split_random(node_random *head, node_random **first_half, node_random **second_half) {

    node_random *slow = NULL;
    node_random *fast = NULL;
    if (head == NULL || head->random == NULL) {
        *first_half = head;
        *second_half = NULL;
    } else {

        slow = head;
        fast = head->random;

        while (fast) {
            
            fast = fast->random;
            if (fast) {
                slow = slow->random;
                fast = fast->random;
            }
        }

        *first_half = head;
        *second_half = slow->random;
        slow->next = NULL;

    }

}

node_random* _sort_merge(node_random *first_half, node_random *second_half) {

    node_random *result = NULL;

    if (first_half == NULL) {
        return second_half;
    } else if (second_half == NULL) {
        return first_half;
    }

    if (first_half->key < second_half->key) {
        result = first_half;
        result->random = _sort_merge(first_half->next, second_half);
    } else {
        result = second_half;
        result->random = _sort_merge(first_half, second_half->next);
    }

    return result;
}

void _merge_sort_singly_random_ll(node_random **head) {

    node_random *first_half = NULL;
    node_random *second_half = NULL;
    node_random *temp_head = *head;

    /** return for single and empty list */
    if (temp_head == NULL || temp_head->random == NULL) {
        return;
    }

    /** Split the list into two halves */
    _singly_ll_split_random(temp_head, &first_half, &second_half);

    /** Sort the two halves */
    _merge_sort_singly_random_ll(&first_half);
    _merge_sort_singly_random_ll(&second_half);

    /** merge two lists */
    *head = _sort_merge(first_half, second_half);

}

/** @Brief; sort singly LL populating random pointers, without changing
 * any data values */
void _sort_with_random(node_random **head) {

    node_random *temp;
    /** Idea is to use merge sort for singly LL with random pointers */

    /** 1. First copy all next pointers to random pointers */

    temp = *head;
    while (temp->next) {
        temp->random = temp->next;
        temp = temp->next;
    }
    _print_singly_ll(*head);

    /** 2. Do merge sort with random pointers */
    _merge_sort_singly_random_ll(head);

    /** 3. Print list */
    _print_singly_ll(*head);
}





void main() {

    node_random *head = NULL;

    _insert_singly_ll(&head, 5);
    _insert_singly_ll(&head, 10);
    _insert_singly_ll(&head, 2);
    _insert_singly_ll(&head, 3);

    _print_singly_ll(head);

    _sort_with_random(&head);
    

    _free_singly_ll(head);

} 
