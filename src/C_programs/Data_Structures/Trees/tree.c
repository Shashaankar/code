#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
    int key;
    int value;
    struct tnode *left;
    struct tnode *right;
}tnode;

void* SRK_ALLOC(int size) {

    void *temp=NULL;
    temp  = malloc(size);

    if(!temp) {
         printf("\n malloc failed");
         return NULL;
    }

    return temp;
}


#define TNODE_SIZE (sizeof(struct tnode))

tnode *root = NULL;


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

int _full_btree_recursive(tnode *rootp) {
    int res=0;

    if (!rootp) {
        return 0;
    }

    if (rootp->left) {
        if (rootp->right) {
            res  = _full_btree_recursive(rootp->left);
        } else {
            return -1;
        }
    }

    if (rootp->right) {
        if (rootp->left) {
            res  = _full_btree_recursive(rootp->right);
        } else {
            return -1;
        }
    }

    return res;
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

    /** leaf node */
    if (!rootp->left && !rootp->right) {
        printf("_free_tnode: key: %d, value: %d\n", rootp->key, root->value);
        free(rootp);
    }            

    /** free the node */
    if (rootp->left || rootp->right) {
        printf("_free_tnode: key: %d, value: %d\n", rootp->key, rootp->value);
        free(rootp);
    }

}

void _check_full_binary_tree() {

    tnode *rootp = NULL;
    int out = 0;
    root = (struct tnode *)SRK_ALLOC(TNODE_SIZE);
    root->key = 0;
    root->value = 0;

    _tree_insert_left(root, 5, 0);
    _tree_insert_right(root, 6, 0);
    _tree_insert_right(root->right, 7, 0);
    _tree_insert_left(root->left, 8, 0);


    /** logic to check for full binary tree */
    rootp = root;
    if(!rootp) {
        printf("Tree is empty \n");
        printf("NULL Trees are full binary trees \n");
    }

    out = _full_btree_recursive(rootp);

    printf("output = %d\n", out);

    _free_tnode(root);

}

/** Given A binary Tree, how do you remove all the half nodes (which has
 * only one child)? Note leaves should not be touched as they have both
 * children as NULL.*/

/** @brief: recursive function called to adjust the half subtree nodes
 * rootp -- > node pointer 
 * parent_node -- > pointer to parent node */
void _rem_half_nodes_recur(tnode *rootp, tnode *parent_node) {

    tnode *delete_node=NULL;

    if (!rootp) {
        return;
    }

    if (rootp->left && rootp->right) {
        _rem_half_nodes_recur(rootp->left, rootp);
        _rem_half_nodes_recur(rootp->right, rootp);
    }

    if (rootp->left && !rootp->right && parent_node) {
        /** Incomplete tree having only left sub tree */
        delete_node = rootp;
        printf("_rem_half: deleted key: %d, value: %d\n", delete_node->key, delete_node->value);

        if (parent_node->left == delete_node) {
            parent_node->left = delete_node->left;
            free(delete_node);
            _rem_half_nodes_recur(parent_node->left, parent_node);
        } else {
            parent_node->right = delete_node->left;
            free(delete_node);
            _rem_half_nodes_recur(parent_node->right, parent_node);
        }

        free(delete_node);
        /** Now recurse on deleted node child */
    }

    if (!rootp->left && rootp->right && parent_node) {
        /** Incomplete tree with only right sub tree */
        delete_node = rootp;
        printf("_rem_half: deleted key: %d, value: %d\n", delete_node->key, delete_node->value);
        if (parent_node->left == delete_node) {
            parent_node->left = delete_node->right;
            free(delete_node);
            _rem_half_nodes_recur(parent_node->left, parent_node);
        } else {
            parent_node->right = delete_node->right;
            free(delete_node);
            _rem_half_nodes_recur(parent_node->right, parent_node);
        }
    }

    /** leaf nodes fall through */
    return;
}

void _remove_half_nodes(){

    tnode *rootp = NULL;

    root = (tnode *)SRK_ALLOC(TNODE_SIZE);
    root->key = 0;
    root->value = 0;

    /** Insert few nodes to test the feature */
    _tree_insert_left(root, 7, 0);
    _tree_insert_right(root, 5, 0);

    _tree_insert_right(root->left,6, 0);
    _tree_insert_left(root->left->right, 1, 0);
    _tree_insert_right(root->left->right, 11, 0);

    _print_inorder_tree(root);


    rootp = root;
    /** Call a function to remove the half nodes */
    if (!rootp) {
        printf("Tree is empty\n");
        return;
    }
    /** recursive function which deletes nodes and update pointers
     * accordingly */
    _rem_half_nodes_recur(root, NULL);

    _print_inorder_tree(root);

    /** free nodes it will print the nodes also In free order */
    _free_tnode(root);

}

void main() {

   // _check_full_binary_tree();
   _remove_half_nodes();
}



