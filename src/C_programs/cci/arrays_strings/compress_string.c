#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Implement a method to perform basic string compression using the
 * counts of
 * repeated characters. For example, the string aabcccccaaa would become
 * a2blc5a3. If the "compressed" string would not become smaller than
 * the original
 * string, your method should return the original string
 */

void compress_string(char **str);
int str_append(char *new_str, char ch, int cont, int max_len);

void main()
{

    char *str = "aaaabaaacaaa";
    printf("original string:= %s\n", str);
    compress_string(&str);
    printf("compressed string:= %s\n", str);
}


void compress_string(char **pp_str)
{
    char *p_str = NULL, *new_str = NULL;
    int len = 0, i =0, count=0, new_len=0;
    char ch;
    p_str = *pp_str;

    if (*pp_str == NULL || **pp_str == NULL) {
        printf("NULL string\n");
        return;
    }

    len = strlen(p_str);

    if (len == 1) {
        printf("Invalid string of length 1");
        return;
    }

    /* Allocate a null terminated string on heap */
    new_str = malloc(len * sizeof(char));
    new_str[0] = '\0';

    /* Replace chars with numbers */
    i = 0;
    while (i < len) {

        /* We should always get start of new character here */
        ch = p_str[i];
        count = 1;
        printf("DEBUG: char:=%c\n", ch);

        while(ch == p_str[i+1]) {
            count++;
            i++;
        }
        if(str_append(new_str, ch, count, len) == -1) {
            printf("Done processing..\n");
            *pp_str = p_str;
            return;
        }
        printf("DEBUG: new_str:=%s\n", new_str);
        i++;
    }

    if (strlen(new_str) >= len) {
        *pp_str = p_str;
    } else {
        *pp_str = new_str;
    }
}

/* Caller has to make sure the given pointer array has considerbale
 * length */
int str_append(char *p_str, char ch, int count, int max_len)
{
    int len = 0;
    int value = (int)'0';

    /* Get to last element of the given string */
    while(p_str[len]) 
    {   
        len++;
    }

    if (len+1 >= max_len) {
        printf("compresses string exceeding given string length\n");
        return -1;
    }

    value += count;
    printf("DEBUG: char:= %c, count:= %d, value:= %d\n", ch, count, value);

    p_str[len] = ch;
    p_str[len+1] = value;
    p_str[len+2] = '\0';

    return 0;
}

