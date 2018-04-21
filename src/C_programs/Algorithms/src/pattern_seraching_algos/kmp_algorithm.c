#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>


/** Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function
 * search(char pat[], char txt[]) that prints all occurrences of pat[]
 * in txt[]. You may assume that n > m. */


/** Compute longest prefix suffix integer array of size equal to pattern
 * length */
int* _computeLPS(char *pat) {

    int pat_len = strlen(pat);
    /** Allocate longest suffic prefix length array */
    int *lsp = malloc(sizeof(int) * pat_len);

    int i = 1, len = 0; /** len is the length of the previous longest prefix suffix */
    lsp[0] = 0; /** First would be always zero */

    while (i < pat_len) {

        /** If pattern matches at both the locations increment both
         * indexs */
        printf("\n _computeLPS: pat check %c, %c", pat[i], pat[len]);
        if (pat[i] == pat[len]) {
            len++;
            lsp[i] =  len;
            i++;
            printf("\n _computeLPS: pat match %c, %c", pat[i], pat[len]);
        } else {
            /** If they are not equal then we have two case */
            if (len != 0) {
                /** initialize lsp, slide down the lsp array */
                len = lsp[len-1];
                printf("\n _computeLPS: length adjustmenti:= %d", len);
            } else {
                /** We reach a position where lsp */
                lsp[i] = 0;
                i++;
                printf("\n _computeLPS: set to zero:=%d", i-1);
            }
        }
    }

    return lsp;
}

void main() {

    /** For now assume static allocation of txt and pattern */
    char *txt = "THIS IS A TEST TEXT";
    char *pat = "TEST";
    int *lsp;
    int i = 0, j = 0, str_len = strlen(txt), pat_len = strlen(pat);

    /** KMP algo */
    lsp = _computeLPS(pat);


    if (!lsp) {
        printf("\nError: lsp array not allocated ");
        exit(0);
    }

    for (int k =0; k < strlen(pat); k++) {
        printf("lsp[%d]:=%d", k, lsp[k]);
    }
    printf("\n");

    while (i < str_len) {

        /** If there is a match, increment both counters and move
         * further */
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }


        if (j == pat_len) {
            /** We found the pattern */
            printf("\nSUCCESS: Found pattern at %d", i-j);
            j = lsp[j-1]; /** why ?*/
        } else if (i < str_len &&   pat[j] != txt[i]) {
            /** Here we optimize the matching algo to move comparing
             * indexes as necessary */
            if (j != 0) {
                j = lsp[j-1];
            } else {
                i = i+1;
            }
        }
    }

    /** Memory free for lsp array */
    free(lsp);

} 
