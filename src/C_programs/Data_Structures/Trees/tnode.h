


#if !defined(TNODE_UTIL)

#define TNODE_UTIL

typedef struct tnode {
     int key;
     int value;
     struct tnode *left;
     struct tnode *right;
}tnode;


#endif
