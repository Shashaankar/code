#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "stack.h"

int size_arr[ST_MAX] = {1,2,4,4,8}; //char, int, float, double


stack* _get_stack(st_type type) {

    stack *st_ptr = NULL;

    st_ptr = malloc(sizeof(stack));
    if (st_ptr == NULL) {
        printf("getstack: malloc failed !\n");
        assert(0);
    }

    /** Default initializing */
    st_ptr->stn_ptr = NULL;
    st_ptr->length = 0;
    st_ptr->type = type;

    return st_ptr;
}


/** @Brief: psush an element onto top of stack, based on type of the
 * stack */
void _push(stack **st_ptr, void *val) {

    int i=0;
    if (!st_ptr || !*st_ptr) {
        printf("_push: stack is empty\n");
        assert(0);
    }

    struct stack_node *temp = NULL;
    temp = (struct stack_node *)malloc((sizeof(stack_node) + size_arr[(*st_ptr)->type]));
    if (!temp) {
        printf("_push: malloc failed!\n");
        assert(0);
    }

    for (i=0; i<size_arr[(*st_ptr)->type]; i++) {
        temp->val[i] = *((char *)val+i);
    }

    temp->next = (*st_ptr)->stn_ptr;
    (*st_ptr)->stn_ptr = temp;
    (*st_ptr)->length++;

}


/** Delete top element and print it on console */
void _pop(stack **st_ptr) {

    struct stack_node *temp=NULL;
    if (!st_ptr || !*st_ptr || !(*st_ptr)->stn_ptr) {
        printf("_pop: Invalid operation, stack empty\n");
        assert(0);
    }

    printf("_pop: Element to be popped\n");
    switch ((*st_ptr)->type) {
    case ST_INT:
        printf("_pop: %d\n", *(int *)((*st_ptr)->stn_ptr->val));
        break;
    default :
        printf("_pop: Invalid stack type\n");
        assert(0);
        break;
    }
    temp = (*st_ptr)->stn_ptr;
    (*st_ptr)->stn_ptr = (*st_ptr)->stn_ptr->next;
    free(temp);
    (*st_ptr)->length--;
}


/** @brief: get stack length */
int _get_length(stack *st_ptr) {

    return st_ptr->length;
}

void main() {
    

    stack *stack_ptr=NULL;
    int arr[] = {1,2,3};
    stack_ptr = _get_stack(ST_INT);

    _push(&stack_ptr, &arr[0]);
    _push(&stack_ptr, &arr[1]);
    _push(&stack_ptr, &arr[2]);

    printf("_main: stack length: %d\n", _get_length(stack_ptr));

    _pop(&stack_ptr);
    printf("_main: stack length: %d\n", _get_length(stack_ptr));
    _pop(&stack_ptr);
    printf("_main: stack length: %d\n", _get_length(stack_ptr));
    _pop(&stack_ptr);
    printf("_main: stack length: %d\n", _get_length(stack_ptr));
    _push(&stack_ptr, &arr[0]);
    _push(&stack_ptr, &arr[1]);
    _push(&stack_ptr, &arr[2]);
    printf("_main: stack length: %d\n", _get_length(stack_ptr));
    _pop(&stack_ptr);
    printf("_main: stack length: %d\n", _get_length(stack_ptr));
    _pop(&stack_ptr);
    printf("_main: stack length: %d\n", _get_length(stack_ptr));
    _pop(&stack_ptr);
    printf("_main: stack length: %d\n", _get_length(stack_ptr));
}


