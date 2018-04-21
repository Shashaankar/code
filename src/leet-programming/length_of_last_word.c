/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

int lengthOfLastWord(char* s) {
    
    int i,count;
    
    
    
    if (s == NULL || strlen(s) == 0) {
        return 0;
    }
    
    count = 0;
    for (i=strlen(s)-1; i>=0 && !count; i--) {
        
        if (s[i] == ' ') {
            continue;
        } else {
            
            // Count number of characters until first space is encountered or string length
            while (s[i] != ' ' && i>=0) {
              i--;
              count++;
            }
            
        }
        
    }
    
    return count;
}
