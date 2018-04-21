#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>


/** Given a binary tree, print out all of its root-to-leaf paths one per
 * line.
 * Solution:
 * # Have an auxilary array to keep track of nodes visited, if a node is
 * encountered with left and right sub trees NULL, print the stack
 * contents as backtrace path.
 * For every visited node push node value onto stack, then recurse via
 * nodes left subtree then nodes right sub tree.
 * # Have a path length var being passed to recursive functions */


void main() {








} 
