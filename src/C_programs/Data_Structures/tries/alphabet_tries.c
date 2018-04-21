#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>


#include "tries.h"


trie_node_t* get_trie_node() {

    trie_node_t temp = malloc(sizeof(trie_node_t));
    int i = 0;

    if (temp) {
        for (i=0; i < NUM_ALPHABETS; i++) {
            temp->link[i] = NULL;
        }
        temp.value = 0;
    } else {
        printf("\nalpha_trie: malloc failed");
        exit(-1);
    }
}


void insert_trie_node(trie_root_t *root, char key[]) {

    int str_len = strlen(key);
    trie_node_t *temp;

    if (*root == NULL) {
        *root = malloc(sizeof(trie_root_t));
        printf("\ninsert_trie: root created");
        root->root = NULL;
        root->count = 0;

    }
    temp = root->root;

    for (level = 0; level < str_len; level++) {

        index = CHAR_TO_INDEX(key[level]);
        if (!(temp->link[index])) {
            temp->link[index] = get_trie_node();
        }
        temp = temp->link[index];
    }
    temp->value = 
}

trie_root_t *trie_root = NULL;
void main() {

} 
