#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>


/** Write an Efficient C Function to Convert a Binary Tree into its
 * Mirror Tree
 * Mirror of a Tree: Mirror of a Binary Tree T is another Binary Tree
 * M(T) with left and right children of all non-leaf nodes interchanged.
 *
 * Solution:
 * TO create a new mirror tree: consider in order traversal of given 
 * tree T, when traversing create right child of the mirror tree, 
 * when traversing right create left child for mirror tree. You could 
 * pass a direction var to recursive function to indicate whther 
 * traversing left or right sub tree 
 *
 * (1)  Call Mirror for left-subtree    i.e., Mirror(left-subtree)
 * (2)  Call Mirror for right-subtree  i.e., Mirror(right-subtree)
 * (3)  Swap left and right subtrees.
 *          if node has left or right subtrees
 *          temp = left-subtree
 *           left-subtree = right-subtree
 *           right-subtree = temp
 **/


void main() {








} 
