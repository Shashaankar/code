
/*
Write a function to find the longest common prefix string amongst an array of strings.
*/



char * subString(char* str, int len)
{
    char *ret = NULL;
    int i;
    
    if (len <= 0) {
        return "";
    }
    
    ret = malloc(sizeof(char) * (len+1));
    
    for (i=0;i<len;i++) {
        ret[i] = str[i];
    }
    ret[i] = '\0';
    printf("len = %d, ret = %s\n", len, ret);
    
    return ret;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    
    int i,j,count,flag;
    char ch;
    
    if (strsSize <= 0 || !strs ) {
        return "";
    }
    
    count = 0;
    for (i=0; i<strsSize; i++) {
        if (strs[i][0] == NULL) {
            count++;
        }
    }
    if (count == strsSize) {
        return "";
    }
    
    flag = count = i = j = 0;
    ch = strs[0][0];
    printf("ch = %c\n", ch);
    
    while (!flag) {
        
        // Init the ch for comparision
        if (j < strlen(strs[0])) {
            ch = strs[0][j];    
        } else {
            flag = 1;
        }
        
        
        for (i=1; i<strsSize; i++) {
        
            if (j == strlen(strs[i])) {
                flag=1;
                break;
            }
            
            if (ch != strs[i][j]) {
                flag = 1;
                break;
            }
            
        } // for
        
        if (flag) {
            break;
        }
        
        j++;
        count++;
    } // while
    
    printf("count = %d\n", count);
    if (count) {
        return subString(strs[0], count);
    }
    
    return "";
}
