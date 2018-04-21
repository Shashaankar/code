#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>


/** Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function
 * search(char pat[], char txt[]) that prints all occurrences of pat[]
 * in txt[]. You may assume that n > m. */

void pat_match(char *txt, char *pat, int start_index) {

    int i = 0, j = 0;

    /** Loop through the text to see if pat is found */
    for (i = start_index; i < strlen(txt) && j < strlen(pat); i++) {
        
        if (txt[i] == pat[j]) {
            j++;
        } else {
            break;
        }
    }

    if (j == strlen(pat)) {
        printf("\nINFO: Pattern found at index:=%d in string:=%s", start_index, txt);
    }
}

void main() {

    /** Input for now assumed to be static */
    char *txt = "THIS IS A TEST TEXT";
    char *pat = "TEST";
    int i = 0;


    printf("\n text: %s", txt);
    printf("\n pattern: %s", pat);
    /** Actual algo */

    for (i = 0; i < strlen(txt); i++) {
        if (txt[i] == pat[0]) {
            printf("\njump index:=%d", i);
            pat_match(txt, pat, i);
        }
    }

}



