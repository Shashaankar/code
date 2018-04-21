#include "ll_util.h"


/** private members not accessible to other files */
static dll_node_s *dll_middle_node = NULL;
static unsigned int dll_node_count = 0;
/** Note: Top of stack of DLL always refers to last node inserted into the DLL
 * list */
static dll_node_s *dll_top=NULL;

void* SRK_ALLOC(int size) {

    void *temp=NULL;
    temp  = malloc(size);

    if(!temp) {
        printf("\n malloc failed");
        return NULL;
    }

    return temp;
}


dll_node_s* _create_dll_node(int size) {
    dll_node_s *node=NULL;

    node = (dll_node_s *)SRK_ALLOC(size);
    if (!node) {
        printf("node allocation failed\n");
        exit(-1);
    }

    return node;
}

/** API functions take an address of pointer to dll_node */

/** Create and Insert dll node and the end */
void _insert_dll_node_last(dll_node_s **rootp, int key, int val) {

    if (!rootp) {
        printf("_insert_dll: invalid address \n");
        return;
    }


    if (!*rootp) {
        printf("_insert_dll: root empty, insert as first node \n");
        *rootp = _create_dll_node(sizeof(dll_node_s));
        (*rootp)->key = key;
        (*rootp)->val = val;
        (*rootp)->next = NULL;
        (*rootp)->prev = NULL;
        /** Top of DLL stack */
        dll_top = *rootp;
    } else {
        /** create a node and insert, then update pointers accordingly */
        dll_node_s *new_node = NULL, *temp=NULL;
        new_node = _create_dll_node(sizeof(dll_node_s));
        new_node->key = key;
        new_node->val = val;
        new_node->next = NULL;

        temp = *rootp;

        /** Loop until last node */
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->prev = temp;
        printf("_insert_dll: key:%d, val:%d\n", new_node->key, new_node->val);
        /** Top of DLL stack */
        dll_top = new_node;
    }

    dll_node_count++;
    if (dll_node_count & 1) {
        /** odd number of elements */
        if (dll_middle_node) {
            /** update middle node pointer */
            /** middle node will traversed from rootp, here we add
             * elements only at the end of DLL */
            dll_middle_node = dll_middle_node->next;

         } else {
             /** first node in the list */
             dll_middle_node = *rootp;
         }
    } else {
        /** even number of elements */
        /** skip: assume middle  node would be pointed (n-1)/2th node DLL */
    }

}



/** print dll_list of nodes */

void _print_dll_nodes(dll_node_s **rootp) {

    dll_node_s *temp;

    if (!rootp || !*rootp) {
        printf("_print_dll: dll list empty \n");
        return;
    }
    temp = *rootp;

    while (temp) {
        printf("_print_dll: key=%d, val=%d\n", temp->key, temp->val);
        temp = temp->next;
    }
}


/** Free dll nodes */
void _free_dll_nodes(dll_node_s **rootp) {

    dll_node_s *temp=NULL;
    if (!rootp || !*rootp) {
        printf("_free_dll: dll list is empty \n");
        return;
    }

   while (*rootp) {
       temp = (*rootp)->next;
       printf("_free_dll: key:%d, val:%d\n", (*rootp)->key, (*rootp)->val);
       free(*rootp);
       *rootp = temp;
   }

   /** set other params */
   dll_top = NULL;
   dll_middle_node = NULL;

}

/** pop nodes in DLL: remove the node from Top of the list */
void _remove_dll_top(dll_node_s **rootp) {

    if (!rootp || !*rootp) {
        printf("_remove_dll_top: Invalid root pointer \n");
        return;
    }

    dll_node_s *temp=NULL;
    temp = *rootp;

    /** Loop until temp refers to last node */
    while (temp->next) {
        temp = temp->next;
    }

    if (dll_top == temp) {
        printf("_remove_dl_top: key:%d, val:%d\n", temp->key, temp->val);
        if (temp->prev) {
            temp->prev->next = NULL;
        }
        dll_top = temp->prev;
        free(temp);
    } else {
        printf("_removr_dll_top: dll top and last node are matching!!\n");
        return;
    }

    dll_node_count--;
    if (dll_node_count & 1) {
        /** odd number of nodes */

    } else {
        /** update the middle pointer */
        dll_middle_node = dll_middle_node->prev;
    }
}


/** get middle DLL node */
dll_node_s* _get_dll_middle_node() {
    return dll_middle_node;
}

/** print middle key */
void _print_middle_node_key() {
    if (!dll_middle_node) {
        printf("_print_middle: Invalid middle node \n");
        return;
    }

    printf("_print_middle: middle_node_key : %d, middle_node_val : %d\n", dll_middle_node->key, dll_middle_node->val);
}

/** get dll node count */
unsigned int _get_dll_node_count() {
    return dll_node_count;
}

/** print top of DLL list */

void _print_dll_top() {
    if (!dll_top) {
        printf("_dll_top: Invalid top pointer \n");
        return;
    }

    printf("_dll_top: dll_top_key: %d, dll_top_val: %d\n", dll_top->key, dll_top->val);

}
