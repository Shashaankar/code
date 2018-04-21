/**Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
**/
int top = -1;
int push_stack(char *stack, int top, char ch)
{
    top++;
    if (top >= 128) {
        //printf("FATAL: stack overflow\n");
        top = 0;
    }
    stack[top] = ch;
    
    
    //printf("push_stack: ch = %c, top = %d\n", stack[top], top);
    return top;
}


char pop_stack(char *stack)
{
    char ret;
    if (top == -1) {
        //printf("Stack is empty\n");
        return NULL;
    }
    
    ret = stack[top];
    top--;
    //printf("pop_stack: ch= %c, top = %d\n", ret, top);
    
    return ret;
}

bool isValid(char* s) {
    
    int i;
    
    char *ch_stack = malloc(128 * sizeof(char));
    top = -1;
    
    
    
    if (!s) {
        return NULL;
    }
    
    for (i=0; s[i] !='\0'; i++) {
        
        switch (s[i]) {
            
            case '(':
          
            top = push_stack(ch_stack, top, ')');
            break;
            
            case '{':
           
            top = push_stack(ch_stack, top, '}');
            break;
            
            case '[':
         
            top = push_stack(ch_stack, top, ']');
            break;
            
            case ')':
          
            if (')' != pop_stack(ch_stack)) {
                
                return 0;
            }
            break;
            
            case '}':
           
            if ('}' != pop_stack(ch_stack)) {
                return 0;
            }
         
            break;
            
            case ']':
          
            if (']' != pop_stack(ch_stack)) {
                return 0;
            }
            break;
            
        }
        
    } // for
    
    if (top != -1) {
        return 0;
    }
    
    return 1;
    
}
