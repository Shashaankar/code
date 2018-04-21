#include<stdio.h>
#include <stdlib.h>
#include "tnode.h"
#include<assert.h>

extern void* SRK_ALLOC(int size);
static tnode *root;
extern _print_inorder_tree(tnode *rootp);
extern _free_tnode(tnode *rootp);
extern _print_bst_range(tnode *rootp, int k1, int k2);

#define TNODE_SIZE sizeof(tnode)

tnode* _create_tnode() {

    tnode *node;
    node = SRK_ALLOC(TNODE_SIZE);

    if (!node) {
        printf("_cr_nd: failed\n");
        exit(0);
    }
    return node;
}


/*@Desc: Creates a new tree node with given key value and inserts into 
         bst at right position  
	@Input: bst root pointer, node key value, recursive or iterative mode of insertion 
	@Output: 0 on successful insertion of the node */
int _insert_node_bst(tnode *rootp, int node_key, int mode) {

    tnode *new_node = NULL;


    if (!rootp) {
        printf("_insert_bst: Empty BST tree \n");
        return;
    }


    /** BST insert logic */

    if (mode == 0) {

    if (rootp->key > node_key) {
        /** left sub tree */
        if (rootp->left) {
            return _insert_node_bst(rootp->left, node_key, 0);
        } else {
            new_node = _create_tnode();
            new_node->key = node_key;
            new_node->value = 0;
            rootp->left = new_node;
        }
    } else {
        /** right sub tree */
        if (rootp->right) {
            return _insert_node_bst(rootp->right, node_key, 0);
        } else {
            new_node = _create_tnode();
            new_node->key = node_key;
            new_node->value = 0;
            rootp->right = new_node;
        }

    }

    } else if (mode == 1) {

        tnode *temp = rootp;

   	while (!new_node) {

		if (temp->key > node_key) {

		    if(!temp->left) {
		       temp->left = _create_tnode();
		       temp->left->key = node_key;
		       temp->left->value = 0;
		       new_node = temp->left; 
		    } else {
		        temp = temp->left;
		    }

		} else {

		    if(!temp->right) {
		       temp->right = _create_tnode();
		       temp->right->key = node_key;
		       temp->right->value = 0;
		       new_node = temp->right; 
		    } else {
		        temp = temp->right;
		    }

		}
	} // while

    } else {
	printf("\nError: Invalid bst insertion mode given");
	assert(0);
    }

    return 0;
}

void main() {

    /** create a root node for BST */

    root = _create_tnode(TNODE_SIZE);
    root->key = 10;
    root->value = 0;

    _insert_node_bst(root, 1, 1);
    _insert_node_bst(root, 14, 1);
    _insert_node_bst(root, 5, 1);
    _insert_node_bst(root, 2, 1);
    _insert_node_bst(root, 15, 1);


    _print_bst_range(root, 1, 20);
   // _inorder_succ_bst(&root, 4);
    _print_inorder_tree(root);

    _free_tnode(root);

}
