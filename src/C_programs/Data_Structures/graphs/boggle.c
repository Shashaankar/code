#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include "graph_utils.h"

/** Given a dictionary, a method to do lookup in dictionary and a M x N
 * board where every cell has one character. Find all possible words
 * that can be formed by a sequence of adjacent charactersNote that we
 * can move to any of 8 adjacent characters, but a word should not have
 * multiple instances of same cell.
 */

/** Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
 * boggle[][]   = {{'G','I','Z'},
 *               {'U','E','K'},
 *              {'Q','S','E'}};
 *  isWord(str): returns true if str is present in dictionary
 *  else false.
 *  Output:  Following words of dictionary are present
 *  GEEKS
 *  QUIZ
 */

/** Solution: 
 * source :
 * http://exceptional-code.blogspot.in/2012/02/solving-boggle-game-recursion-prefix.html
 * 
 * Simple way is to list all possible words with boggle and compare if
 * it forms a word in the dictionary. For this we need to use
 * backtracking, where we start from an index and go through all
 * possible directions until all the alphabets in the boggle are visited
 * from that index. 
 * Time complexity of this solution is worse and doesn't scale for
 * increase in size of boggle or dictionary. O((N * N)!)
 *
 * Further optimization can be done if we could check a given
 * combination of staring letters 'xy', for this if there's any word
 * possibly in given dictionary. If so continue exploring else stop
 * exploring with given combination as there will be no words starting
 * with given search letters xy.
 * However even with this approach, we are given a huge search space,
 * for which we need to loop through dictionary if its found or not.
 * implementing a trie for given dictionary would scale well with large
 * number of dictionary items.
 *
 * However further optimizations can be possible with dynamic
 * programming , as described in above link
 *
 *
 * */




void main() {








} 
