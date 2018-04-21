#include<stdio.h>
#include <stdlib.h>

#if !defined(LL_UTIL)
#define LL_UTIL
#define DLL_NODE_SIZE = sizeof(dll_node_s)

typedef struct dll_node {
    int key;
    int val;
    struct dll_node *next;
    struct dll_node *prev;
} dll_node_s;


#define push_dll(rootp, key, val) _insert_dll_node((rootp), (key), (val));

/** Node with next and random pointer */
typedef struct node_random {
    int key;
    int val;
    struct node_random *next;
    struct node_random *random;
} node_random;

#endif
