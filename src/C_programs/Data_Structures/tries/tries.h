#if !defined(TRIES_DS)


#define TRIES_DS

#define NUM_ALPHABETS 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')



/** tries structure for alphabets */
typedef struct _tries {
    int value;
    trie_node_t *link[NUM_ALPHABETS];
} trie_node_t;

/** Trie root to hold root pointer and count of number of elements */
typedef struct _trie {
    trie_node_t *root;
    int count;
} trie_root_t;

#endif
