

#if !defined(SRK_STACK)

#define SRK_STACK
typedef enum st_type {
    ST_CHAR = 0,
    ST_INT,
    ST_FLOAT,
    ST_DOUBLE,

    /* Add user defined types above this */
    ST_MAX = 0xF
} st_type;


typedef struct stack_node {
    struct stack_node *next;
    char val[0];
} stack_node;

typedef struct stack {

    struct stack_node *stn_ptr;
    int length; // number of elements in the stack
    st_type type;
    /** based on type we would print out the top element */
} stack;


stack* _get_stack(st_type type);

void _push(stack **st_ptr, void *val);

void _pop(stack **st_ptr);

int _get_length(stack *st_ptr);


#endif
