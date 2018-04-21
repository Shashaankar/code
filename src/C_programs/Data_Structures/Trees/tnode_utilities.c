#include<stdio.h>
#include<stdlib.h>
#include "tnode.h"


#define TNODE_SIZE (sizeof(struct tnode))

void* SRK_ALLOC(int size) {

    void *temp=NULL;
    temp  = malloc(size);

    if(!temp) {
         printf("\n malloc failed");
         return NULL;
    }

    return temp;
}


void _tree_insert_left(tnode *rootp, int key, int value) {

    if (!rootp || rootp->left) {
        printf("Invalid root or left pointer \n");
        return;
    }

    rootp->left = (struct tnode *)SRK_ALLOC(TNODE_SIZE);

    rootp->left->key = key;
    rootp->left->value = value;

}


void _tree_insert_right(struct tnode *rootp, int key, int value) {

    if (!rootp || rootp->right) {
        printf("Invalid root or right pointer \n");
        return;
    }

    rootp->right = (struct tnode *)SRK_ALLOC(TNODE_SIZE);

    rootp->right->key = key;
    rootp->right->value = value;

}


void _print_inorder_tree(tnode *rootp) {

    if (rootp)  {
        _print_inorder_tree(rootp->left);
        printf("rootp->key: %d, rootp->value: %d\n", rootp->key, rootp->value);
        _print_inorder_tree(rootp->right);
    }


}

void _free_tnode(tnode *rootp) {

    if (!rootp) {
        return;
    }


    if (rootp->left) {
        _free_tnode(rootp->left);
    }
    if (rootp->right) {
        _free_tnode(rootp->right);
    }

    printf("_free_tnode: key: %d, value: %d\n", rootp->key, rootp->value);
    free(rootp);
#if 0
    /** leaf node */
    if (!rootp->left && !rootp->right) {
        printf("_free_tnode: key: %d, value: %d\n", rootp->key, rootp->value);
        free(rootp);
    }            

    /** free the node */
    if (rootp->left || rootp->right) {
        printf("_free_tnode: key: %d, value: %d\n", rootp->key, rootp->value);
        free(rootp);
    }
#endif

}

 /** @brief : Given two values k1 and k2 (where k1 < k2) and a root
  * pointer to a Binary Search Tree. Print all the keys of tree in range
  * k1 to k2. i.e. print all x such that k1<=x<=k2 and x is a key of
  * given BST. Print all the keys in increasing order.*/

void _print_bst_range(tnode *rootp, int k1, int k2) {

    if (! (k1 < k2)) {
        printf("_bst_range: Invalid range %d --- > %d\ni", k1, k2);
        return;
    }
    if (!rootp) {
        return;
    }

    /** BST range logic */

    if (rootp->key > k2) {
        _print_bst_range(rootp->left, k1, k2);
    } else if (rootp->key < k1) {
        _print_bst_range(rootp->right, k1, k2);
    } else {

        printf("\n_bst_range: %d", rootp->key);
        _print_bst_range(rootp->left, k1, k2);
        _print_bst_range(rootp->right, k1, k2);
    }

}


/* @brief: In Binary Tree, Inorder successor of a node is the next node
 * in Inorder traversal of the Binary Tree. Inorder Successor is NULL
 * for the last node in Inoorder traversal.
 * In Binary Search Tree, Inorder Successor of an input node can also be
 * defined as the node with the smallest key greater than the key of
 * input node. So, it is sometimes important to find next node in sorted
 * order.*/


int _get_min_key(tnode *rootp, tnode *parent_node, int key) {

    /** If we are here then, successor node will be the minimum key node
     * in right sub tree */

    if (rootp) {
        if (rootp->left) {
            _get_min_key(rootp->left, rootp, key);
        } else if (rootp->right) {
            _get_min_key(rootp->right, rootp, key);
        } else {
            /** This rootp is the min node key */
            if (rootp->key > key) {
                return rootp->key;
            }
        }
    } else {
        printf("_min_key: something wrong !!\n");
    }
}

/** @brief: rootp -- > root pointer of the tree 
 *  node ----- > Node for whose successor node has to be found */

int _get_in_suc_key(tnode *rootp, tnode *node, int key) {

    /** Here we traverse the path from the root and find the successor
     * node */

    tnode *succ = NULL;

    while (rootp) {
        if (node->key < rootp->key) {
            succ = rootp;
            rootp = rootp->left;
        } else if (node->key > rootp->key) {
            rootp = rootp->right;
        } else {
            break;
        }
    }

    if (succ) {    
        return succ->key;
    } else {
        printf("_in_suc_key: succesor node for %d is NULL\n", key);
        return 0;
    }

}

void _print_in_suc_bst(tnode *head_node, tnode *rootp, tnode *parent_node, int key) {

    /** This function will be used to direct search based on right
     * subtree of the node we are interested in finding out successor */

    if (rootp->key ==  key) {
        if (rootp->right) {
            /** succesor node in right sub-tree 
             * print minimum key in tree greater than given key */
           printf("_print_in_suc_bst: successor of node %d, is %d\n", key, _get_min_key(rootp->right, rootp, key));
           return;
        } else {
           printf("_print_in_suc_bst: successor node of %d is %d\n", key, _get_in_suc_key(head_node, rootp, key));
           return;
        }
    } else if (rootp->key > key) {
        /** key should be in left sub tree */
        _print_in_suc_bst(head_node, rootp->left, rootp, key);
    } else if (rootp->key < key) {
        /** key should be in right sub tree */
        _print_in_suc_bst(head_node, rootp->right, rootp, key);
    }

}

void _inorder_succ_bst(tnode **head, int key) {


    if (!head || !*head) {
        printf("_print_isucc_bst: BST is NULL \n");
        return;
    }

    _print_in_suc_bst(*head, *head, NULL, key);

}
