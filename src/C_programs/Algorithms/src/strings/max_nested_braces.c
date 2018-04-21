#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

/** Find maximum depth of nested parenthesis in a string
 * We are given a string having parenthesis like below
 *      “( ((X)) (((Y))) )”
 *      We need to find the maximum depth of balanced parenthesis, like
 *      4 in above example. Since ‘Y’ is surrounded by 4 balanced
 *      parenthesis.
 *
 *      If parenthesis are unbalanced then return -1.
 */

/** 
 * Solution: Initlaize two vars current_max and max = 0
 * for every '(' inc current max, once you hit a alpha set max equal to
 * current_max. continue traversing the string, whenever you see ')'
 * decrement the current_max. Before decrementing check if it has a
 * postive value, else its an unbalanced expression. Finally after
 * finishing the expression check for current_max == 0; and max depth is
 * max.  else unbalanced expression. */


void main() {








} 
