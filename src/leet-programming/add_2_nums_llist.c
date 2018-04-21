#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


/*
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked
 * list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
 /* Definition for singly-linked list*/
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    
    struct ListNode *ret_result,*l3, *temp;
    int n,carry;
    
    /* Base failure case */
    if (l1 == NULL && l2 ==  NULL) {
        
        return NULL;
    
    }
    
    l3 = ret_result = temp = NULL;
    carry = 0;
    
    while (l1 || l2) {
        
        n = 0;
        
        if (l1) {
            n += l1->val;
        }
        
        if (l2) {
            n += l2->val;
        }
        
        n += carry;
        carry = 0;
        
        /* Allocate and link new node */
        if (l3) {
            
            l3->next = malloc(sizeof(struct ListNode));    
            l3 = l3->next;
        } else {
            
            l3 = malloc(sizeof(struct ListNode));
        }
        
        /* Assign head of the new list to ret list */
        if (ret_result == NULL) {
            
            ret_result = l3;
            printf("first assignmnet ret_result=%p\n", ret_result);
        }
        
        
        if (n > 9) {
            
            l3->val = n%10;
            carry = n/10;
            printf("val=%d, carry=%d\n", l3->val, carry);
        } else {
            
            l3->val = n;
            printf("val=%d\n", l3->val);
        }
        
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
        
    } // while
    
    printf("ret_result=%p\n", ret_result);
    temp = ret_result;

    while(temp) {
        
        printf("temp=%p val=%d\n", temp, temp->val);
        temp = temp->next;
    }

    return ret_result;
    
}


void main() 
{


    struct ListNode *l1,*l2, *head1, *head2, *ret_list;
    int i = 0;
    l1 = l2 = head1 = head2 = ret_list = NULL;

    for(i=0; i<1; i++) {

        if(!l1) {
            l1 = malloc(sizeof(struct ListNode));
            l1->val = i;
            l1->next = NULL;
        } else {
            l1->next = malloc(sizeof(struct ListNode));
            l1 = l1->next;
            l1->val = i;
            l1->next = NULL;
        }


            if(!l2) {
                l2 = malloc(sizeof(struct ListNode));
                l2->val = i+1;
                l2->next = NULL;
            } else {
                l2->next = malloc(sizeof(struct ListNode));
                l2 = l2->next;
                l2->val = i+1;
                l2->next = NULL;
            }


        if (!head1) {
            head1 = l1;
        }
        if (!head2) {
            head2 = l2;
        }
    }

    ret_list = addTwoNumbers(head1, head2);
}
